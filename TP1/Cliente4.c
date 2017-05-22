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
     int longitudCliente = sizeof(server);
    //Create socket
    sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock == -1)
    {
        printf("Could not create socket");
    }
    puts("Socket created");
     
    server.sin_addr.s_addr = htonl(INADDR_ANY);
    server.sin_family = AF_INET;
    server.sin_port = htons( PORTNUMBER );
 bzero(&(server.sin_zero), 8);
   
     
    puts("Connected\n");
     
    //keep communicating with server
    while(1)
    {
        printf("Enter message : ");
        scanf("%s" , message);
         
        //Send some data
        if( (sendto (sock, (char *)&message, sizeof(message), 0, (struct sockaddr *)&server, longitudCliente)) < 0)
        {
            puts("Send failed");
            return 1;
        }
         
        //Receive a reply from the server
        /*if( recv(sock , server_reply , 2000 , 0) < 0)
        {
            puts("recv failed");
            break;
        }
         */
        //puts("Server reply :");
        //puts(server_reply);
        
    }
      close(sock);
   
    return 0;
}

