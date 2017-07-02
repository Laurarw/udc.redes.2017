#include <unistd.h>
#include <string.h>
#include <stdio.h>

#include "responseHead.h"
#include "helper.h"


/*  Crea la cabecera de respuesta(respose) HTTP */

int Output_HTTP_Headers(int conn, struct ReqInfo * reqinfo) {

    char buffer[100];

    sprintf(buffer, "HTTP/1.0 %d OK\r\n", reqinfo->status);
    Writeline(conn, buffer, strlen(buffer));

    Writeline(conn, "Server: PGWebServ v0.1\r\n", 24);
    Writeline(conn, ("Content-Type: text/html\r\n"), 25);
//	Writeline(conn, ("Content-Type: %s\r\n", ), 25);

    Writeline(conn, "\r\n", 2);

    return 0;
}
/*HACER QUE ESCRIBA LA CABECERA DEL TIPO MIME*/
/*
 * FUNCION QUE RETORNA EL TIPO DE CONTENT TYPE
 * 
 * 
 * char *get_mime_type(char *directorio_de_archivo){
	char *ext = strrchr(directorio_de_archivo, '.');
	if (!ext) return NULL;
	if (strcmp(ext, ".html") == 0 || strcmp(ext, ".htm") == 0) return "text/html";
	if (strcmp(ext, ".jpg") == 0 || strcmp(ext, ".jpeg") == 0) return "image/jpeg";
	if (strcmp(ext, ".gif") == 0) return "image/gif";
	if (strcmp(ext, ".png") == 0) return "image/png";
	if (strcmp(ext, ".css") == 0) return "text/css";
	if (strcmp(ext, ".au") == 0) return "audio/basic";
	if (strcmp(ext, ".wav") == 0) return "audio/wav";
	if (strcmp(ext, ".avi") == 0) return "video/x-msvideo";
	if (strcmp(ext, ".mpeg") == 0 || strcmp(ext, ".mpg") == 0) return "video/mpeg";
	if (strcmp(ext, ".mp3") == 0) return "audio/mpeg";
	return NULL;
}

 * 
 * 
 * 
 * */

