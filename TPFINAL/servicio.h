#ifndef _SERVICIO_H_
#define _SERVICIO_H_

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <time.h>

//helper si va include

#define PUERTO 8000
	
#define TAM 900000
#define N 500
#define MIMETYPE "mime-types.tsv"
static char root[1000] = "/home/usuario/Escritorio/TPFINAL";



char * get_mime_type(char *name);
int evaluandoPeticion(char cadena1[5], char cadena2[50], char cadena3[9]);


#endif
