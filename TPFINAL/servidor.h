/*
 * SERVIDOR.H
   ===========
 * 
 * 
 * Biblioteca que contiene las funciones referentes al manejo interno del servidor.
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

/*Definicion de variables globales*/
#define SERVE "LBJ web"/*Nombre del servidor*/
#define PUERTO 8000/*Numero de puerto que va a usar el servidor*/


/*	Declaracion de funciones proporcionadas por el servidor */d
void sig_chld(int signo);
void servicio ();


#endif
