
/* 

  4)Modifique Server3.c para que preste el servicio de character generator (vea RFC864) 
  * y guardelo como Server4.c




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
#define LINELEN 111

int atender_cliente(int socket);

int main(void){
    
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
		printf("Conectando con %s:\t%d\n", inet_ntoa(direcc.sin_addr),htons(direcc.sin_port));
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
int atender_cliente(int socket){
	
    while (1) {//bucle infinito mandando la cadena @algo hasta que el cliente cierra la conexión
      
        if (write(socket, "@algo", 4) < 0)
            break;
    }
    
    return 0;
    
}



