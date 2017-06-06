/* 

  2)Modifique el servidor para que no finalice y guardelo como Server1.c

*/
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#define PORTNUMBER  12345

int main(void){
    char buf[10];
    int s, n, ns, len;
    struct sockaddr_in direcc;
   
    s = socket(AF_INET, SOCK_STREAM, 0);//La función socket() nos devuelve un descriptor de socket
//referencia a los elementos del socket.
    bzero((char *) &direcc, sizeof(direcc));
    direcc.sin_family = AF_INET;
    direcc.sin_port = htons(PORTNUMBER);
    direcc.sin_addr.s_addr = htonl(INADDR_ANY);

    len = sizeof(struct sockaddr_in);
    bind(s, (struct sockaddr *) &direcc, len);//asociar un socket con un puerto (de nuestra máquina)
    listen(s, 5);//se usa si se están esperando conexiones entrantes
    
    
    while(1){//bucle infinito para que el servidor no se cierre cuando el cliente cierre la conexión.
		 ns = accept(s, (struct sockaddr *) &direcc, &len);//aceptamos conexiones entrantes
		 while ((n = recv(ns, buf, sizeof(buf), 0)) > 0){//cuando el valor de "n"=0, significa que el cliente cerró la conexión. Menor a 0, error.
			  write(1, buf, n);
		 }    
		 close(ns);  
		
	}  
         
    close(s);
    exit(0);
}

