#include <stdio.h> //printf
#include <string.h>    //strlen
#include <sys/socket.h>    //socket
#include <arpa/inet.h> //inet_addr
#include <unistd.h>
#include <stdlib.h>

 typedef struct Suma
{
	char num1[100];
	char num2[100];
	long int resultado;
} s_suma;

#define PORTNUMBER  12345

int main(int argc , char *argv[])
{
    int sock;
    s_suma suma;
    struct sockaddr_in server;
    char message[1000] , server_reply[2000];
     
    //Create socket
    sock = socket(AF_INET , SOCK_STREAM , 0);
    if (sock == -1)
    {
        printf("No se puede crear Socket");
    }
    puts("Socket creado");
     
    server.sin_addr.s_addr = htonl(INADDR_ANY);
    server.sin_family = AF_INET;
    server.sin_port = htons( PORTNUMBER );
 
    //se conecta con el server remoto
    if (connect(sock , (struct sockaddr *)&server , sizeof(server)) < 0)
    {
        perror("Conección falló. Error");
        return 1;
    }
     
    puts("Conectado\n");

    //mantener la comunicación con el server
    char cadena[50]; 
    int u,nBytes;
    char num1[81], num2[81],respuesta[60];
    char *data;
    
    while(1)
    {
		 //se limpian cadenas
			  memset(suma.num1,'\0',strlen(suma.num1));
		      memset(suma.num2,'\0',strlen(suma.num2));
		puts("Ingrese dos numeros enteros separados por un espacio. La falta de uno de ellos se toma como cero . Ej: 4 4");	
        printf("Números: ");
      
        fgets(message,sizeof(message),stdin);
		
		sscanf( message,"%s %s", suma.num1, suma.num2 );
		//printf("\n%s + %s\n", suma.num1, suma.num2);
	
		
		write (sock, &suma, sizeof(s_suma));
		
		
		u=recv(sock, &suma, sizeof(s_suma), 0);
	

		printf("La respuesta es: %ld\n\n",suma.resultado);   
			
       
       
    }
     
    close(sock);
    return 0;
}


