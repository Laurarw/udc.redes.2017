/*
 * SERVICIO.H
   ===========
 * 
 * 
 * Biblioteca contiene las funciones referentes al manejo del servicio del servidor.
 * 
 * */


#ifndef _SERVICIO_H_
#define _SERVICIO_H_
/*Se incluyen las bibliotecas externas necesarias*/
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


/*Definicion de variables globales*/

#define TAM 900000/*Tamanio maximo*/
#define N 500/*numero*/
#define MIMETYPE "mime-types.tsv"/*Ubicacion donde se encuentran guardados los diferentes tipos mime*/
#define SERVE "LBJ web"

static char root[1000] = "/home/usuario/Escritorio/TPFINAL";/*Ruta interna del servidor de la que obtiene los recursos*/

/*	Declaracion de funciones proporcionadas por el servicio */

char * get_mime_type(char *name);

int evaluandoPeticion(char metodo[5], char recurso[50], char protocolo[9]);


#endif
