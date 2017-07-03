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
 
#define PUERTO 8000
#define N 500
#define TAM 900000
#define MIMETYPE "mime-types.tsv"

char *obtenerTipoArchivo(char objeto_leido[]);
int evaluandoPeticion(char cadena1[5], char cadena2[50], char cadena3[9]);

char * get_mime_type(char *name) {
	char *ext = strrchr(name, '.');
  char delimiters[] = " ";
	char *mime_type = NULL;
	mime_type = malloc (128 * sizeof(char)) ;
	char line[128];
	char *token;
	int line_counter = 1;
	ext++; // skip the '.';
	FILE *mime_type_file = fopen(MIMETYPE, "r");
	if (mime_type_file != NULL) {
		while(fgets(line, sizeof line, mime_type_file) != NULL) {
			if (line_counter > 1)
			{
				if((token = strtok(line,delimiters)) != NULL) {
					if(strcmp(token,ext) == 0) {
						token = strtok(NULL, delimiters);
						strcpy(mime_type, token);
						break;
					}else{
						strcpy(mime_type, "application/octet-stream");
					}
				}
			}
			line_counter++;
		}
		fclose( mime_type_file );
	} else {
		perror("open");
	}
	return mime_type;
}



int main(void)
{
        time_t tiempo = time(0);
        struct tm *tlocal = localtime(&tiempo);
        char output[128];
       
        char gerror[500];
        bzero(gerror,500);
       
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
             }
               while(request[strlen(request)-1] != '\n' || request[strlen(request)-2] != '\r' ||
				request[strlen(request)-3] != '\n' || request[strlen(request)-4] != '\r')
		{
			n = read(0, buffer, sizeof(buffer));
			buffer[n] = '\0';
			strcat(request, buffer);
		}
                if (sscanf(request, "%s %s %s", peticion, objeto, version)==3)
                {  // Si la Peticion esta completa
					bzero(request, N);
					printf("\n%s",request);
					estado = evaluandoPeticion(peticion, objeto, version);
					printf("\n%s %s %s\n",peticion, objeto, version);
				}
                strftime(output,128,"%a, %C %b %Y %H:%M:%S %Z",tlocal);
                
                
                switch(estado)
                {
                        case 200:
                                        bzero(punto,sizeof(punto));
                                        punto[0] = '.';
                                        strcat(punto,objeto);
                                        printf("\n\nobjetooo: &s", objeto);
                                        *mime = get_mime_type(objeto);
                                        fp = fopen(punto,"rb");
                                        i = fread(pagina,sizeof(char),TAM,fp);
                                        sprintf(cabecera,"%s 200 OK\r\nContent-Type: %s \r\nContent-Length: %d\r\nContent-Language: es\r\nServer: UDC\r\nDate: %s\r\n\r\n", version, *mime,i,output);                                        
                                printf("\n\n%s\n\n",cabecera);
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
                 if(strcmp(peticion,"HEAD") == 0 && estado==200)
                        {
                                  write(0,cabecera,strlen(cabecera) + i);
                                  return 0;
                         }
                memcpy(cabecera + strlen(cabecera),pagina, i); 
                write(0,cabecera,strlen(cabecera) + i);
                 return 0;
}

//      Funcion que evalua la peticion en busca de errores
//      y devuelve un entero a modo de estado.
 
int evaluandoPeticion(char cadena1[5], char cadena2[50], char cadena3[9])
{
        FILE *archivo = NULL;
        char punto[50];
        bzero(punto,sizeof(punto));
        punto[0] = '.';
        if (strcmp(cadena2,"/") == 0){
				  strcpy(cadena2, "/index.html");
		}
        strcat(punto,cadena2);
       
        if(strcmp(cadena1,"GET") != 0 && strcmp(cadena1, "HEAD") != 0)
        {
                return 501;
        }
       
        if(strcmp(cadena3,"HTTP/1.0")!= 0 && strcmp(cadena3,"HTTP/1.1")!= 0)
        {
                return 505;
        }
       
        archivo = fopen(punto,"rb");
       
        if(archivo == NULL)
        {
                return 404;
        }
       
        return 200;
}
 
// Funcion que devuelve el tipo de archivo del objeto recibido
 
char *obtenerTipoArchivo(char objeto_leido[])
{
		char *objeto [50];
       // sscanf(objeto, ".%s", objeto_leido);
        *objeto= strtok (objeto_leido,".");
		*objeto= strtok (NULL,"/0");       
        if(strcmp(*objeto, "htm") == 0 || strcmp(*objeto, "html") == 0)
			return "text/html";
		else{if(strcmp(*objeto, "txt") == 0)
				return "text/plain";
			else{ if(strcmp(*objeto, "css") == 0)
					return "text/css";
				else{ if(strcmp(*objeto, "gif") == 0)
						return "image/gif";
					else{ if(strcmp(*objeto, "png") == 0)
							return "image/png";
						else{ if(strcmp(*objeto, "jpg") == 0 || strcmp(*objeto, "jpeg") == 0)
							return "image/jpeg";
							else{ if(strcmp(*objeto, "pdf") == 0)
									return "application/pdf";
								else return "application/octet-stream";
								}
							}
						}
					}
				}	
		}
}
