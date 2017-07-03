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

#include "servicio.h"
 
#define PUERTO 8000
#define N 500
#define TAM 900000
#define MIMETYPE "mime-types.tsv"


int main(void)
{
        time_t tiempo = time(0);
        struct tm *tlocal = localtime(&tiempo);
        char output[128];
       
       
        char buffer[N];
        bzero(buffer, N);
       
        char request[N];
        bzero(request, N);     
       
        char pagina[TAM];
        bzero(pagina,TAM);
       
        char cabecera[TAM];
        bzero(cabecera,TAM);
       
        int i,n;
        int tamanio = 0;
        char punto[50];
       
        char peticion[5];
        char objeto[50];
        i = strlen(objeto);
        objeto[i+1] = '\0';
        char version[9];
       char *mime[20];
		int estado;
        FILE *fp;
        if((n =read(0, buffer, sizeof(buffer))) > 0)
        {      
                strcpy(request, buffer);
                strcpy(buffer, "");
                while(request[strlen(request)-1] != '\n' || request[strlen(request)-2] != '\r' ||
				request[strlen(request)-3] != '\n' || request[strlen(request)-4] != '\r')
					{
						n = read(0, buffer, sizeof(buffer));
						buffer[n] = '\0';
						strcat(request, buffer);
					}
					printf("\nREQUEST: %s",request);
          }
          
                if (sscanf(request, "%s %s %s", peticion, objeto, version)==3)
                {  // Si la Peticion esta completa
					bzero(request, N);
					printf("\n%s",request);
					estado = evaluandoPeticion(peticion, objeto, version);
					//printf("\n%s %s %s\n",peticion, objeto, version);
				}
                strftime(output,128,"%a, %C %b %Y %H:%M:%S %Z",tlocal);
                
                puts(objeto);
                switch(estado)
                {
                        case 200:
                                        bzero(punto,sizeof(punto));
                                        punto[0] = '.';
                                        strcat(punto,objeto);
                                        printf("\nPUNTOOOOOOOOO%s",punto);
                                        *mime = get_mime_type(objeto);
                                        fp = fopen(punto,"rb");
                                        i = fread(pagina,sizeof(char),TAM,fp);
                                        sprintf(cabecera,"%s 200 OK\r\nContent-Type: %s \r\nContent-Length: %d\r\nContent-Language: es\r\nServer: UDC\r\nDate: %s\r\n\r\n", version, *mime,i,output);                                        
                                
                                break;
                        case 505:
										fp = fopen("./505.html","rb");
                                        i = fread(pagina,1,sizeof(pagina),fp);
                                        tamanio = strlen(pagina);      
                                        sprintf(cabecera,"%s 505 HTTP version not supported\r\nContent-Type: text/html\r\nContent-Length: %d\r\nContent-Language: es\r\nServer: UDC\r\nDate: %s\r\n\r\n", version,tamanio,output);
                                 break;
                        case 404:
                                        fp = fopen("./404.html","rb");
                                        i = fread(pagina,1,sizeof(pagina),fp);
                                        tamanio = strlen(pagina);
                                        sprintf(cabecera,"%s 404 NotFound\r\nContent-Type: text/html\r\nContent-Length: %d\r\nContent-Language: es\r\nServer: UDC\r\nDate: %s\r\n\r\n", version,tamanio,output);
                                break;
                        case 501:
                                        fp = fopen("./501.html","rb");
                                        i = fread(pagina,1,sizeof(pagina),fp);
                                        tamanio = strlen(pagina);
                                        sprintf(cabecera,"%s 501 NotImplement\r\nContent-Type: text/html\r\nContent-Length: %d\r\nContent-Language: es\r\nServer: UDC\r\nDate: %s\r\n\r\n", version,tamanio,output);
                                break;
                         default:
										fp = fopen("./400.html","rb");
                                        i = fread(pagina,1,sizeof(pagina),fp);
                                        tamanio = strlen(pagina);
                                        sprintf(cabecera,"HTTP/1.0 400 Bad Request\r\nContent-Type: text/html\r\nContent-Length: %d\r\nContent-Language: es\r\nServer: UDC\r\nDate: %s\r\n\r\n",tamanio,output);
                                break;
                }
                printf("\n\n%s\n\n",cabecera);
                 if(strcmp(peticion,"HEAD") == 0 && estado==200)
                        {
                                  write(0,cabecera,strlen(cabecera) + i);
                                  return 0;
                         }
                memcpy(cabecera + strlen(cabecera),pagina, i); 
                write(0,cabecera,strlen(cabecera) + i);
                 return 0;
}

 

