#include <stdio.h> //printf
#include <string.h>    //strlen
#include <sys/socket.h>    //socket
#include <arpa/inet.h> //inet_addr
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define PORTNUMBER  12345
int recv_to(int fd, char *buffer, int len, int flags, int to);

int main(int argc , char *argv[])
{
    int sock;
    struct sockaddr_in server;
    char server_reply[2000];
    
		char message[1000];
    //Crear cliente
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
   
   int connect_init = 1;
   int r,errno;
    while(1)
    {
		
			//función que reemplaza a recv
		  while( (u=recv_to(sock , cadena , sizeof(cadena) , 0,1)) > 0)
			{
				
				cadena[u]='\0';
				  puts(cadena);
				  
			  
			}
			
	

      printf("Ingresar Mensaje : ");
        //bzero(message, sizeof(message));
		fgets(message, sizeof(message), stdin);
        write(sock , &message , strlen(message)); //en vez de 1 como primer parametro de write, se envia el socket.



 }
    close(sock);
    return 0;
}
/*
   Parametros:
      fd       -  (int) socket 
      buffer - (char*) buffer de la info
      len     - (int) max numero of bytes para recv()
      flags   - (int) flags (como el cuarto parametro para recv() )
      to       - (int) timeout in milliseconds
   Resultados:
      int      - The same as recv, but -2 == TIMEOUT
   Notas:
   * Solo se puede usar en file descriptors que son sockets 
      'to' debe ser diferente a 0
      'buffer' no tiene que se NULL y debe apuntar a suficiente memoria para guardar por lo menos 'len' bytes
      
*/
int recv_to(int fd, char *buffer, int len, int flags, int to) {

   fd_set readset;
   int result, iof = -1;
   struct timeval tv;

   //se necesita inicializar los sets en el ciclo siempre antes de llamar a selec.Es necesario porque selec los modifica.
   FD_ZERO(&readset);
   FD_SET(fd, &readset);
   
   // Inicializa time out struct
   tv.tv_sec = 0;
   tv.tv_usec = to * 1000;
   // select()
   //primer, segundo y tercer parametro seran modificados para reflejar con cual de los ficheros seleccionados esta listo para leer, escribir, errores.
	//readset=empieza en 0 y cambia su valor a 1 si esta recibiendo data
	//selec permite al programa monitorear a multiples sockets por unas actividades (read, write)
   result = select(fd+1, &readset, NULL, NULL, &tv);

   // Check status
   if (result < 0)//error
      return -1;
   else if (result > 0 && FD_ISSET(fd, &readset)) {//result es porque existe un socket y si hay un evento de read en el socket por lo que se trata
      // Set non-blocking mode
      if ((iof = fcntl(fd, F_GETFL, 0)) != -1)
         fcntl(fd, F_SETFL, iof | O_NONBLOCK);
      // receive
      result = recv(fd, buffer, len, flags);
      // set as before
      if (iof != -1)
         fcntl(fd, F_SETFL, iof);
      return result;
   }
   return -2;
}
