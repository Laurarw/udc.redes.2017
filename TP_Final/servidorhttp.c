#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <sys/stat.h>   /* Biblioteca para se utilizar a struct stat para verificación de arquivos*/
//#include <fcntl.h>      /* Biblioteca para se utilizar a funcion open()*/
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
  //puts("hola");
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
 char buf[1000];
 int p;
 
    while(1){   
 	
		consocket = accept(mysocket, (struct sockaddr *)&dest, &socksize);
		//printf("Conexion desde %s\n", inet_ntoa(dest.sin_addr));

		if((pid = fork()) == 0 ){ 
			
			close(mysocket);			
 
			//p=consocket;
/*			while(p=read(consocket,buf,sizeof(buf))>0){
				
					puts("a");
				
				write(1,buf,sizeof(buf));
				
				break;
			}
	*/				puts("b");
				
			
			dup2(consocket,0);
			dup2(consocket,1);
			//read(p,buf,sizeof(buf));
			//printf("%s\n",buf);
					puts("c");
			
			//fwrite( cadena, sizeof(char), sizeof(cadena), log );
			//fwrite(consocket,sizeof(char),1000,log);
			
					puts("d");
			
			servicio();
			
			
			close(consocket);
			break;
		}else{ 
			//printf("Conexion atendida por el hijo numero: %d\n", pid);
			close(consocket);
		}
    }
 
    exit(0);
}




 

 

 
 
