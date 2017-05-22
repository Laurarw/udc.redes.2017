/* 

  11)Transformar el Server3.c, en un servidor iterativo de Eco con UDP y guardelo como Server9.c. 
  Cree el cliente correspondiente y guardelo como  Cliente4.c.



*/
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <arpa/inet.h>
/*
 *




#include <unistd.h>
#include <ctype.h>
#include <signal.h>
 * */

#define PORTNUMBER  12345

void atender_cliente(int socket,struct sockaddr_in Cliente, int longitudCliente,struct sockaddr_in direcc);

int main(void){
  
 int s, ns, len,p;
    struct sockaddr_in direcc;
   struct sockaddr_in Cliente;
   int longitudCliente = sizeof(Cliente);
   //SOCK_DGRAM para protocolo UDP
    s = socket(AF_INET, SOCK_DGRAM, 0);

    bzero((char *) &direcc, sizeof(direcc));
    direcc.sin_family = AF_INET;
    direcc.sin_port = htons(PORTNUMBER);
    direcc.sin_addr.s_addr = htonl(INADDR_ANY);

    len = sizeof(struct sockaddr_in);
    
    printf("Creando socket ....\n");
    p=bind(s, (struct sockaddr *) &direcc, len);
    if(p==-1){
		perror("bind hhh");
		exit(1);
	}
 

   // listen(s, 5);
    
    
    while(1){
		 //ns = accept(s, (struct sockaddr *) &direcc, &len);
		  
		 atender_cliente(s,Cliente,longitudCliente,direcc);
		 //close(ns);  
		// close(s);
	}  
         
    close(s);
    exit(0);
}
/*
 Atiende la petición del cliente.
 Función que recibe como parámetro el socket en el que se conecta el cliente.
 No devuelve nada.
 * */
void atender_cliente(int socket,struct sockaddr_in Cliente, int longitudCliente,struct sockaddr_in direcc){
	char buf[11];
	
    
	int n;
	//printf("Conectando con %s:%d\n", inet_ntoa(Cliente.sin_addr),htons(Cliente.sin_port));
	printf("Esperando datos ....\n");
	
	if((n=recvfrom(socket,(char *) buf, sizeof(buf), 0, (struct sockaddr *)&Cliente, &longitudCliente)) >0){
			//perror("recvfrom");
 //exit(1);
  printf("paquete proveniente de : %s||puerto: %d\n ",inet_ntoa(Cliente.sin_addr),htons(Cliente.sin_port));
  printf("el paquete contiene : %s\n", buf);
	}
	  
		 
}




