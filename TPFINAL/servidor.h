/*
 * SERVIDOR.H
   ===========
 * 
 * 
 * Biblioteca contiene las funciones referentes al manejo interno del servidor.
 * 
 * */


#ifndef _SERVIDOR_H_
#define _SERVIDOR_H_

//Incluimos las librerias necesarias 
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <signal.h>
#include <ctype.h>
#include <sys/wait.h>
#include <time.h>

#define PUERTO 8000
#define N 500
#define TAM 90000000

/* prototipo de funciones*/
void sig_chld(int signo);
void servicio ();


#endif
