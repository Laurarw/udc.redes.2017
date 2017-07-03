#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <sys/stat.h>   /* Biblioteca para se utilizar a struct stat para verificación de arquivos*/

#include <sys/socket.h> /* Biblioteca que contiene definicoe de sockets*/
#include <sys/wait.h>   /* Biblioteca para utillizar a função waitpid() */
#include <sys/types.h>  /* Biblioteca contendo os tipos de socket */
#include <arpa/inet.h>  /* Biblioteca contendo Funcoes referentes ao inet (Rede) */
#include <unistd.h>     /* Biblioteca contendo varios comandos *NIX */
#include <pthread.h>    /* Biblioteca para utilizacao de THREADS para otimizar o acesso*/
#include <netinet/in.h>
#include <signal.h>
#include <ctype.h>
#include <time.h>
 

#define PORTNUM 8080

void servicio (){
	 static char *argv[] = {NULL};
	
	execv("servicio", argv);
	return;
 }
 void sig_chld(int signo){
       
        pid_t pid;
        int stat;
       
        while ((pid = waitpid(-1, &stat, WNOHANG)) > 0)
                        printf("\n.\n");
}
 
 
int main(int argc, char *argv[]){

    struct sockaddr_in dest;  
    struct sockaddr_in serv;  
    int mysocket, consocket, pid; 
    int socksize = sizeof(struct sockaddr_in);

    memset(&serv, 0, sizeof(serv));      
    serv.sin_family = AF_INET;
    serv.sin_addr.s_addr = INADDR_ANY;
    serv.sin_port = htons(PORTNUM);
 
    mysocket = socket(AF_INET, SOCK_STREAM, 0);
 
    bind(mysocket, (struct sockaddr *)&serv, sizeof(struct sockaddr));
 
    listen(mysocket, 1);
    printf("---------------------------------------\n");
    printf("-SERVIDOR ESCUCHANDO EN EL PUERTO %d-\n", PORTNUM);
    printf("---------------------------------------\n");
     
     
    signal(SIGCHLD, sig_chld);
	/*char buf[1000];
	int p;*/
 
    while(1){   
		
		/*Se acepta la conexion y se establece el socket de atencion/hijo, este va a atender al cliente*/
		consocket = accept(mysocket, (struct sockaddr *)&dest, &socksize);
		
		/*si el socket es el hijo, entoces*/
		if((pid = fork()) == 0 ){ 
			
			close(mysocket);/*se cierra el socket de escucha/padre*/			
 
			/*Imprime en la consola del servidor la cabecera request/peticion que envia el cliente
			  al socket de atencion
			*/
			
/*			while(p=read(consocket,buf,sizeof(buf))>0){
				
					puts("a");
				
				write(1,buf,sizeof(buf));
				
				break;
			}
	*/				puts("b");
				
			/*Duplica el descriptor de archivo existente, en este caso consocket*/
			dup2(consocket,0);/*entrada estandard*/
			dup2(consocket,1);/*salida estandard*/
			servicio();/*llama al servicio*/
			
			/*se cierra el socket de atencion*/
			close(consocket);
			break;
		}else{ 
			/*se cierra el socket de atencion*/
			close(consocket);
		}
    }
 
    exit(0);
}
