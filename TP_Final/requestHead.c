#include <sys/time.h>             /*  For select()  */

#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include "requestHead.h"
#include "servreq.h"
#include "helper.h"


/* Convierte en una cadena(string) el requerimiento   */

int Parse_HTTP_Header(char * buffer, struct ReqInfo * reqinfo) {

    static int first_header = 1;
    char      *temp;
    char      *endptr;
    int        len;


    if ( first_header == 1 ) {

	/* Si la primera cabecera es 0 entonces es la primera linea del request HTTP
	 *  
	 * If first_header is 0, this is the first line of
	    the HTTP request, so this should be the request line.  */


	/*  Se fija que metodo se envia en el requerimiento.
	 * El servidor solo soporta los metodos GET Y HEAD
	 */

	if ( !strncmp(buffer, "GET ", 4) ) {/*Si el metodo es GET */
	    reqinfo->method = GET;/*guarda en el method de la estructura reqinfo que es GET*/
	    buffer += 4;/*y se desplaza hasta la pocicion 4 del buffer*/
	}
	else if ( !strncmp(buffer, "HEAD ", 5) ) {/*Si el metodo es HEAD*/
	    reqinfo->method = HEAD;/*guarda en el method de la estructura reqinfo que es HEAD*/
	    buffer += 5;/*y se desplaza hasta la pocision 5 del buffer*/
	}
	else {/*Si el metodo no es ninguno de los soportados entonces*/
	    reqinfo->method = UNSUPPORTED;/*se guarda en el method del reqinfo que es UNNSOPORTED(no soportado)*/
	    reqinfo->status = 501;/*y el status del reqinfo pasa a ser 501*/
	    return -1;/*provocando que se le devuelva al cliente el error 501 de metodo no soportado*/
	}


	/*  Recorre hasta el inicio del recurso  */

	while ( *buffer && isspace(*buffer) )
	    buffer++;


	/* Calcula la longitud del nombre del recurso... */

	endptr = strchr(buffer, ' ');
	if ( endptr == NULL )
	    len = strlen(buffer);
	else
	    len = endptr - buffer;
	if ( len == 0 ) {
	    reqinfo->status = 400;
	    return -1;
	}

	/*  ...Y lo guarda en el resource de la estructura de informacion del requerimiento.  */

	reqinfo->resource = calloc(len + 1, sizeof(char));
	strncpy(reqinfo->resource, buffer, len);

	
	/* Prueba ver si hay alguna informacion de la version HTTP 
	 * Si no la hay entonces es un SIMPLE requerimiento HTTP, y no lee mas headers
	   Por simplicidad no se verifica si es valida la version de HTTP, 
	   se  asume que si se le pone la version entonces es un request FULL
	   
	   For simplicity, we don't bother checking the validity of the HTTP version
	   information supplied - we just assume that if it is
	   supplied, then it's a full request.                        */

	if ( strstr(buffer, "HTTP/") )
	/*Ver si poniendo esto solo manda http version 1.0
	 * if ( strstr(buffer, "HTTP/1.0") )*/
	    reqinfo->type = FULL;
	else
	    reqinfo->type = SIMPLE;

	first_header = 0;
	return 0;
    }


    /*  Si es HTTP FULL entonces sigue leyendo la cabecera del requerimiento.  */

    /*  HTTP field names are case-insensitive, so make an
	upper-case copy of the field name to aid comparison.
	We need to make a copy of the header up until the colon.
	If there is no colon, we return a status code of 400
	(bad request) and terminate the connection. Note that
	HTTP/1.0 allows (but discourages) headers to span multiple
	lines if the following lines start with a space or a
	tab. For simplicity, we do not allow this here.              */

    endptr = strchr(buffer, ':');
    if ( endptr == NULL ) {
	reqinfo->status = 400;
	return -1;
    }

    temp = calloc( (endptr - buffer) + 1, sizeof(char) );
    strncpy(temp, buffer, (endptr - buffer));
    StrUpper(temp);


    /*  Increment buffer so that it now points to the value.
	If there is no value, just return.                    */

    buffer = endptr + 1;
    while ( *buffer && isspace(*buffer) )
	++buffer;
    if ( *buffer == '\0' )
     	return 0;


    /*  Now update the request information structure with the
	appropriate field value. This version only supports the
	"Referer:" and "User-Agent:" headers, ignoring all others.  */

    if ( !strcmp(temp, "USER-AGENT") ) {
	    reqinfo->useragent = malloc( strlen(buffer) + 1 );
	    strcpy(reqinfo->useragent, buffer);
    }
    else if ( !strcmp(temp, "REFERER") ) {
	    reqinfo->referer = malloc( strlen(buffer) + 1 );
	    strcpy(reqinfo->referer, buffer);
    }

    free(temp);
    return 0;
}




ssize_t WriteRequestHead(int sockd, void *vptr, size_t maxlen) {
    ssize_t n, rc;
    char    c, *buffer;
	char b[2000];
    buffer = vptr;

    for ( n = 1; n < maxlen; n++ ) {
	
		if ( (rc = read(sockd, &c, 1)) == 1 ) {
			*buffer++ = c;
			if ( c == '\n' ){
				/*strcat(b,c);*/

				write(1,"\n",1);
				break;
			}write(1,c,1);
		}
		else if ( rc == 0 ) {
			if ( n == 1 )
			return 0;
			else
			break;
		}
		else {
			if ( errno == EINTR )
			continue;
			Error_Quit("Error in Readline()");
		}
    }
	/*write(1,b,n);*/
    *buffer = 0;
    return n;
}

/* Obtiene los headers del request 
 * Gets request headers. A CRLF terminates a HTTP header line,
    but if one is never sent we would wait forever. Therefore,
    we use select() to set a maximum length of time we will
    wait for the next complete header. If we timeout before
    this is received, we terminate the connection.               */

int Get_Request(int conn, struct ReqInfo * reqinfo) {

    char   buffer[MAX_REQ_LINE] = {0};
    int    rval;
    fd_set fds;
    struct timeval tv;


    /*  Set timeout to 10 seconds  */

    tv.tv_sec  = 10;
    tv.tv_usec = 0;


    /*  Loop through request headers. If we have a simple request,
	then we will loop only once. Otherwise, we will loop until
	we receive a blank line which signifies the end of the headers,
	or until select() times out, whichever is sooner.                */

    do {

	/*  Reset file descriptor set  */

	FD_ZERO(&fds);
	FD_SET (conn, &fds);


	/*  Wait until the timeout to see if input is ready  */

	rval = select(conn + 1, &fds, NULL, NULL, &tv);


	/*  Take appropriate action based on return from select()  */

	if ( rval < 0 ) {
	    Error_Quit("Error calling select() in get_request()");
	}
	else if ( rval == 0 ) {

	    /*  input not ready after timeout  */

	    return -1;

	}
	else {

	    /*  We have an input line waiting, so retrieve it  */

	    Readline(conn, buffer, MAX_REQ_LINE - 1);
	    
	    Trim(buffer);
/*	    printf("%s\n",buffer);//Para imprimir en la consola del servidor la cabecera enviada por el cliente */
		WriteRequestHead(conn, buffer, MAX_REQ_LINE - 1);
	    if ( buffer[0] == '\0' )
		break;

	    if ( Parse_HTTP_Header(buffer, reqinfo) )
		break;
	}
    } while ( reqinfo->type != SIMPLE );

    return 0;
}


/*  Inicializacion de la estructura de informacion del requerimiento */

void InitReqInfo(struct ReqInfo * reqinfo) {
    reqinfo->useragent = NULL;
    reqinfo->referer   = NULL;
    reqinfo->resource  = NULL;
    reqinfo->method    = UNSUPPORTED;
    reqinfo->status    = 200;          
}


/*  Liberar la memoria asignada a la estructura de informacion del requerimiento */

void FreeReqInfo(struct ReqInfo * reqinfo) {
    if ( reqinfo->useragent )
	free(reqinfo->useragent);
    if ( reqinfo->referer )
	free(reqinfo->referer);
    if ( reqinfo->resource )
	free(reqinfo->resource);
}

