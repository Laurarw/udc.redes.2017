#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <ctype.h>
#include <time.h>
 
#include "servidor.h"

int main(int argc, char *argv[])
{      
        pid_t hijo;
        int freepuerto = 1;
        struct sockaddr_in direcc;
        int s, ns, len;
       
        //Inicio-Seteando socket
        s = socket(AF_INET, SOCK_STREAM, 0);
       
        direcc.sin_family = AF_INET;
        direcc.sin_port = htons(PUERTO);
        direcc.sin_addr.s_addr = htonl(INADDR_ANY);
        //Fin-Seteando socket
       
        len = sizeof(struct sockaddr_in);
       
       
        if ((bind(s, (struct sockaddr *) &direcc, sizeof(struct sockaddr_in))) < 0)
        {
                printf("Error en bind\n");
                exit(0);
        }
           
        if((listen(s, 5)) < 0)
        {
                printf("Error en listen\n");
                exit(0);
        }
       
        printf("---------------------------------------\n");
        printf("-SERVIDOR ESCUCHANDO EN EL PUERTO %d-\n", PUERTO);
        printf("---------------------------------------\n");
       
        //Espera la finalizacion del hijo
        signal(SIGCHLD, sig_chld);
       
        //Reusa el puerto
        setsockopt(s, SOL_SOCKET, SO_REUSEADDR, &freepuerto, sizeof(freepuerto));
       
        //comienza el bucle infinito
        while(1)
        {
                ns = accept(s, (struct sockaddr*) &direcc, &len);
               
                printf("\nConnection from: %s\n", inet_ntoa(direcc.sin_addr));
               
                switch(fork()){
                                case -1: 
                                        printf("Error en fork\n");     
                                        break;                              
                                case 0:                                     
                                        close(s);
                                        dup2(ns, 0);
										//dup2(ns, 1);  //Crar un nuevo handle a partir de otro existente. El nuevo tiene en común con el antiguo: fichero asociado; fp, y modo de acceso.
                                        servicio();
                                        close(ns);
                                        exit(0);
                                default:
                                        close(ns);                                                              
                             }
              }
        close(s);
        exit(0);
}
 
 
 

