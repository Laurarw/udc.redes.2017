/* 

  4)Modifique y Server2.c para que preste el servicio de echo (vea RFC862) 
  y guardelo como Server3.c



*/
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORTNUMBER  12345

void atender_cliente(int socket);

int main(void){
    
    int s, ns, len;
    struct sockaddr_in direcc;
   
    s = socket(AF_INET, SOCK_STREAM, 0);

    bzero((char *) &direcc, sizeof(direcc));
    direcc.sin_family = AF_INET;
    direcc.sin_port = htons(PORTNUMBER);
    direcc.sin_addr.s_addr = htonl(INADDR_ANY);

    len = sizeof(struct sockaddr_in);
     printf("Conectando con %s:%d\n", inet_ntoa(direcc.sin_addr),htons(direcc.sin_port));
    bind(s, (struct sockaddr *) &direcc, len);
    listen(s, 5);
    
    
    while(1){
		printf("Conectando con %s:%d\n", inet_ntoa(direcc.sin_addr),htons(direcc.sin_port));
		 ns = accept(s, (struct sockaddr *) &direcc, &len);
		 atender_cliente(ns);
		 close(ns);  
		
	}  
         
    close(s);
    exit(0);
}
/*
 Atiende la petición del cliente.
 Función que recibe como parámetro el socket en el que se conecta el cliente.
 No devuelve nada.
 * */
void atender_cliente(int socket){
	char buf[11];
	int n;
	 while ((n = recv(socket, buf, sizeof(buf), 0)) > 0){
			  write(socket, buf, n); //en vez de 1 como primer parametro de write, se envia el socket.
		 }    
}



