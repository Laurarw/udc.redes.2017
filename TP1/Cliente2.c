#include <stdio.h> //printf
#include <string.h>    //strlen
#include <sys/socket.h>    //socket
#include <arpa/inet.h> //inet_addr
#include <unistd.h>


#define PORTNUMBER  12345

int main(int argc , char *argv[])
{
    int sock;
    struct sockaddr_in server;
    char message[1000] , server_reply[2000];
     
    //Crear socket
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
  
    
    char cadena[50]; 
    int u,nBytes;
    char num1[81], num2[81],respuesta[60];
    //mantener la comunicación con el server
    while(1)
    {
		
		  //2147483647
		puts("Ingrese dos numeros enteros separados por un espacio . Ej: 4 4");
        printf("Números: ");
      
        fgets(message,sizeof(message),stdin);

		

		nBytes = strlen(message);//acá estaba el +1

		send(sock,message,nBytes,0);

		u=recv(sock, message, sizeof(message), 0);
		message[u]='\0';

		printf("Respuesta del server: %s\n\n",message);   
			
       
       
    }
     
    close(sock);
    return 0;
}

