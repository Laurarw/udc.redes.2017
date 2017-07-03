/*Se incluyen todas la bibliotecas necearias para poder ejecutar el servidorhttp.c*/
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

/*Main principal del servidor http*/
int main(int argc, char *argv[])
{      
        pid_t hijo;
        int freepuerto = 1;
        struct sockaddr_in direcc;
        int s, ns, len;
       
        //Inicio-Seteando socket
        s = socket(AF_INET, SOCK_STREAM, 0);/*Se crea un socket TCP*/
       
        direcc.sin_family = AF_INET;/*Protocolo de la conexion*/
        direcc.sin_port = htons(PUERTO);/*Puerto para la conexion*/
        direcc.sin_addr.s_addr = htonl(INADDR_ANY);/*Direccion IP del host*/
        //Fin-Seteando socket
       
        len = sizeof(struct sockaddr_in);
       
       
        if ((bind(s, (struct sockaddr *) &direcc, sizeof(struct sockaddr_in))) < 0)/*Asigna el socket a un puerto*/
        {
                printf("Error en bind\n");
                exit(0);
        }
           
        if((listen(s, 5)) < 0)/*El socket queda escuchando peticiones*/
        {
                printf("Error en listen\n");
                exit(0);
        }
       
        printf("---------------------------------------\n");
        printf("-SERVIDOR ESCUCHANDO EN EL PUERTO %d-\n", PUERTO);
        printf("---------------------------------------\n");
       
        //Espera la finalizacion del hijo
        signal(SIGCHLD, sig_chld);
       
        //funcion que no deja que el socket se bloquee si ocurre algun error
        setsockopt(s, SOL_SOCKET, SO_REUSEADDR, &freepuerto, sizeof(freepuerto));
       
        //comienza el bucle infinito
        while(1)
        {
                ns = accept(s, (struct sockaddr*) &direcc, &len);/*Se acepta una nueva conexion de un cliente y se atiende en el nuevo socket*/
               
                printf("\nConnection from: %s\n", inet_ntoa(direcc.sin_addr));
               
                switch(fork()){
                                case -1: 
                                        printf("Error en fork\n");     
                                        break;                              
                                case 0:/*Socket de atencion(hijo)*/                                     
                                        close(s);/*Se cierra el socket de escucha(padre)*/
                                        //se le asigna al cliente la entrada estandar
                                        dup2(ns, 0);
										//dup2(ns, 1); no lo agregamos porque no interesaba que nos mostraran por pantalla las cosas
                                        servicio();/*Llamamos al servicio que se encuentra en servidor.c*/
                                        close(ns);
                                        exit(0);
                                default:
                                        close(ns);                                                              
                             }
              }
        close(s);
        exit(0);
}
 
 
 

