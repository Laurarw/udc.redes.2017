#include <unistd.h>
#include <fcntl.h>

#include <string.h>
#include <stdio.h>

#include "resource.h"
#include "requestHead.h"
#include "helper.h"


/* Directorio que usa el servidor para encontrar y obtener los requerimientos 
 * Ejemplo: al servidor le llega una peticion de /index, entonces
 * este va a buscar /home/usuario/Escritorio/webserv/index.html
 * para obtenerlo
 */

static char server_root[1000] = "/home/usuario/Escritorio/webserv";

/*
 * */
/*int Length_Resource (int conn, int resource, struct ReqInfo * reqinfo){

    char c;
    int  i;
	int contador=0;
    while ( (i = read(resource, &c, 1)) ) {//lee el recurso
		if ( i < 0 )//si i es menor a 0 lanza un error de lectura
			Error_Quit("Error reading from file.");
		contador++;
	}

    return contador;//retorna 0 si no hubo ningun error
}
 * */
/* Funcion que devuelve el recurso(resource)  */

int Return_Resource(int conn, int resource, struct ReqInfo * reqinfo) {

    char c;
    int  i;

    while ( (i = read(resource, &c, 1)) ) {//lee el recurso
	if ( i < 0 )//si i es menor a 0 lanza un error de lectura
	    Error_Quit("Error reading from file.");
	if ( write(conn, &c, 1) < 1 )//se le devuelve el recurso al cliente
	    Error_Quit("Error sending file.");//si no se puede mandar el recurso lanza un error indicando que no se pudo enviar
    }

    return 0;//retorna 0 si no hubo ningun error
}


/* Intenta abrir un recurso. 
 * Se usa para verificar si se puede obtener un recurso. 
 */

int Check_Resource(struct ReqInfo * reqinfo) {

    /*  Se limpia la URL del resource para saber cual es el recurso que se necesita    */
    CleanURL(reqinfo->resource);

    
    /*  Concatena la ruta del servidor con el resource para encontrar el recurso requerido*/

    strcat(server_root, reqinfo->resource);
    return open(server_root, O_RDONLY);/*Abre el recurso y devuelve si se pudo obtener el recurso, o un error de que no se pudo*/
}


/*  Retornar el mensaje de error  */

int Return_Error_Msg(int conn, struct ReqInfo * reqinfo) {
    
    char buffer[100];

    sprintf(buffer, "<HTML>\n<HEAD>\n<TITLE>Error en el Servidor %d</TITLE>\n"
	            "</HEAD>\n\n", reqinfo->status);
    Writeline(conn, buffer, strlen(buffer));

    sprintf(buffer, "<BODY>\n<H1>Error en el Servidor %d</H1>\n", reqinfo->status);
    Writeline(conn, buffer, strlen(buffer));

    sprintf(buffer, "<P>El requerimiento no se pudo completar.</P>\n"
	            "</BODY>\n</HTML>\n");
    Writeline(conn, buffer, strlen(buffer));

    return 0;

}
