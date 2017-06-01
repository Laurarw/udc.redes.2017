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
    char server_reply[2000];
    
		char message[1000];
    //Create socket
    sock = socket(AF_INET , SOCK_STREAM , 0);
    if (sock == -1)
    {
        printf("No se puede crear el socket");
    }
    puts("Socket creado");
     
    server.sin_addr.s_addr = htonl(INADDR_ANY);
    server.sin_family = AF_INET;
    server.sin_port = htons( PORTNUMBER );
 
    //Connect to remote server
    if (connect(sock , (struct sockaddr *)&server , sizeof(server)) < 0)
    {
        perror("Falló Conexion. Error");
        return 1;
    }
     int u;
    puts("Conectado\n");
     char cadena[50]; 
    //keep communicating with server
    while(1)
    {
		 
        printf("Ingresar Mensaje : ");
        scanf("%s" , message);
         
        //Send some data
        if( send(sock , message , strlen(message) , 0) < 0)
        {
            puts("Falló el envio");
            return 1;
        }
        //read(sock,&cadena,strlen(cadena));
        //read(sock,&cadena,sizeof(cadena));//aca manda todo pero no borra lo anterior
         
        //Receive a reply from the server
        if( (u=recv(sock , &cadena , sizeof(cadena) , 0)) < 0)
        {
            puts("recv falló");
            break;
        }
         cadena[u]='\0';
       
        puts(cadena);
         //puts("Server reply :");
        // printf("\n\nCadena enviada= %s \n", cadena);
    }
     
    close(sock);
    return 0;
}
