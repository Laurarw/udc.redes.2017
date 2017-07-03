/*
 * 
 * SERVIDOR.C
 * ==========
 * 
 * Funciones declaradas en servidor.h
 * Propias del funcionamientos interno del servidor
 * 
 * 
 * 
 * 
 * */

#include "servidor.h"
/*
 * Funcion que devuelve el estado del los hijos y espera a que estos terminen de atender
 * 
 * 
 * */
void sig_chld(int signo){
       
        pid_t pid;
        int stat;
       
        while ((pid = waitpid(-1, &stat, WNOHANG)) > 0)
                        printf("\nHijo %d", pid);
}



/*
 * Funcion que llama y lanza el servicio para que atienda al cliente que se conecto
 * 
 * 
 * */
void servicio (){
	 static char *argv[] = {NULL};
	
	execv("service", argv);
	return;
 }
