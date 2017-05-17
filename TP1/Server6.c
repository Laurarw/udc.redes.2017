/* 

  7)Transformar el Server3.c, en un servidor concurrente usando fork() 
  y guardelo como Server5.c.



*/
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <signal.h>
#include <sys/wait.h>//libreria para que reconozca el waitpid
 
#define PORTNUMBER  12345

void atender_cliente(int socket);
void sig_chld(int signo);

int main(void){
    
    int s, ns, len,proceso;
    struct sockaddr_in direcc;
   
    s = socket(AF_INET, SOCK_STREAM, 0);

    bzero((char *) &direcc, sizeof(direcc));
    direcc.sin_family = AF_INET;
    direcc.sin_port = htons(PORTNUMBER);
    direcc.sin_addr.s_addr = htonl(INADDR_ANY);

    len = sizeof(struct sockaddr_in);
    bind(s, (struct sockaddr *) &direcc, len);
    listen(s, 5);
    
    signal(SIGCHLD, sig_chld);
    
    while(1){
		 ns = accept(s, (struct sockaddr *) &direcc, &len);
		 
		 proceso=fork();//crea procesos hijos
		 switch(proceso){
			 case -1://es error en el fork()
			printf("fork() error");
        		break;
			case 0: //es un proceso hijo
				close(s);
				printf("Conectando con %s:%d\n", inet_ntoa(direcc.sin_addr),htons(direcc.sin_port));
				atender_cliente(ns);
				close(ns);		
				printf("Finalizando con %s:%d\n", inet_ntoa(direcc.sin_addr),htons(direcc.sin_port));
				exit(0);
			default://es el padre. mayor a cero
				close(ns);

		 }
		 
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
/*
  Agregar informacion
 * 
 * */
void sig_chld(int signo){
	pid_t	pid;
	int	stat;

	while ( (pid = waitpid(-1, &stat, WNOHANG)) > 0)
		printf("   Hijo %d ha terminado\n", pid);
	return;
}




