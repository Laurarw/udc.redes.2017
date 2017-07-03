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

#include "helper.h"
#include "servreq.h"





/*INICIO PROGRAMA*/
int main(){
/*
char buf[100];
   int n;
 printf("%s",argv[0]);
 
   while ((n = read(0, buf, sizeof(buf))) > 0){
	
    write(1, buf, n);}
  */
  Service_Request(0);

exit(0);
}


