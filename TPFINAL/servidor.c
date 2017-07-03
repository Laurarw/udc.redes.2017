#include "servidor.h"



void sig_chld(int signo){
       
        pid_t pid;
        int stat;
       
        while ((pid = waitpid(-1, &stat, WNOHANG)) > 0)
                        printf("\nHijo %d", pid);
}
void servicio (){
	 static char *argv[] = {NULL};
	
	execv("service", argv);
	return;
 }
