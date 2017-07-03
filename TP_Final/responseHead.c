#include <unistd.h>
#include <string.h>
#include <stdio.h>

#include "responseHead.h"
#include "helper.h"


/*  Crea la cabecera de respuesta(respose) HTTP */

int Output_HTTP_Headers(int conn, struct ReqInfo * reqinfo) {
//int Output_HTTP_Headers(int conn, int resource, struct ReqInfo * reqinfo)
    char buffer[100];

    sprintf(buffer, "HTTP/1.0 %d OK\r\n", reqinfo->status);
    Writeline(conn, buffer, strlen(buffer));

    Writeline(conn, "Server: PGWebServ v0.1\r\n", 27);
    Writeline(conn, "Content-Type: text/html\r\n", 28);
//	
//recorre el reqinfo->resource hasta que llega al .tipo_de_archivo
//entonces manda ese content type 
/*
  //Se define el tipo de contenido de la respuesta 
  //Recorriendo el reqinfo->resource hasta que llega al .tipo_de_archivo
  
  if ((strstr(reqinfo->resource, ".html"))||( strstr(reqinfo->resource, ".htm") )){//si el recurso es .html o .htm
  		Writeline(conn, "Content-Type: text/html\r\n", 28);// entonces el Content-Type vale text/html
  
  }else if(strstr(reqinfo->resource, ".txt")){//si el recurso es .txt
  		Writeline(conn, "Content-Type: text/plain\r\n", 29);//entonces el Content-Type vale text/plain
  
  }else if(strstr(reqinfo->resource, ".gif")){//si el recurso es .gif
  		Writeline(conn, "Content-Type: image/gif\r\n", 28);//entonces el Content-Type vale image/gif
  
  }else if((strstr(reqinfo->resource, ".jpg"))||( strstr(reqinfo->resource, ".jpeg") )){//si el recurso es .jpg o .jpeg
  		Writeline(conn, "Content-Type: image/jpeg\r\n", 29);//entonces el Content-Type vale image/jpeg
  
  }else if(strstr(reqinfo->resource, ".pdf")){//si el recurso es .pdf
  		Writeline(conn, "Content-Type: application/pdf\r\n", 38);//entonces el Content-Type vale application/pdf
  
  }else {//si el recurso no es ninguno de estos tipos
  		Writeline(conn, "Content-Type: application/octet-stream\r\n", 42);//entonces el Content-Type vale application/octet-stream
  } 
  
 * */


//Poner el Content-length


/* Obtine el tamaño del recurso*/

/* int tamanio;
  char cadena[1000];
  tamanio=Length_Resource (conn, resource, &reqinfo);
  //Content-length
  sprintf(cadena, "Content-Length: %d\r\n",tamanio);
   Writeline(conn, cadena, strlen(cadena));//se agrega el content-length a la cabecera

 * */
    Writeline(conn, "\r\n", 2);

    return 0;
}
