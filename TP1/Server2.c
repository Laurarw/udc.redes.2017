/* 

  3)Modifique Server1.c para que el servicio que presta 
  se implemente en una función separada del cuerpo principal del programa (main()) 
  y guardelo como Server2.c


*/
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#define PORTNUMBER  12345

void atender_cliente(int socket);

int main(void){
    //char buf[10];
    int s, ns, len;
    struct sockaddr_in direcc;
   
    s = socket(AF_INET, SOCK_STREAM, 0);

    bzero((char *) &direcc, sizeof(direcc));
    direcc.sin_family = AF_INET;
    direcc.sin_port = htons(PORTNUMBER);
    direcc.sin_addr.s_addr = htonl(INADDR_ANY);

    len = sizeof(struct sockaddr_in);
    bind(s, (struct sockaddr *) &direcc, len);
    listen(s, 5);
    
    
    while(1){
		 ns = accept(s, (struct sockaddr *) &direcc, &len);
		 atender_cliente(ns);//función
		 close(ns);  
		
	}  
         
    close(s);
    exit(0);
}
/*
 Función que recibe como parámetro el socket en el que se conecta el cliente.
 No devuelve nada.
 * */
void atender_cliente(int socket){
	char buf[11];
	int n;
	 while ((n = recv(socket, buf, sizeof(buf), 0)) > 0){
			  write(1, buf, n);
		 }    
}


