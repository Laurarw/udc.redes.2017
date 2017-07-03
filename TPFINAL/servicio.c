
#include "servicio.h"

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

int evaluandoPeticion(char metodo[5], char recurso[50], char protocolo[9])
{
        FILE *archivo = NULL;
        char punto[50];
        bzero(punto,sizeof(punto));
        punto[0] = '.';
        if (strcmp(recurso,"/") == 0){
				  strcpy(recurso, "/index.html");
		}
        strcat(punto,recurso);
       
        if(strcmp(metodo,"GET") != 0 && strcmp(metodo, "HEAD") != 0)
        {
                return 501;
        }
       
        if(strcmp(protocolo,"HTTP/1.0")!= 0 && strcmp(protocolo,"HTTP/1.1")!= 0)
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
