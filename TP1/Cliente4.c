#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define BUFF 100

#define SERVER "127.0.0.1"
#define PUERTO 12345 
struct sockaddr_in si_other;




void enviarMsj(int s){

	char buf[BUFF];
	char message[BUFF];

	int slen = sizeof(si_other);
		
		message[0] = '\0';
		printf("Ingrese mensaje: \n");
		
		gets(message);

		//Envio de msj.
		if(sendto(s, message, strlen(message), 0, (struct sockaddr *) &si_other, slen) == -1){
			exit(1);
		}
		memset(buf, '\0', BUFF);

		if (recvfrom(s, buf, BUFF, 0, (struct sockaddr *) &si_other, &slen) == -1)
		{
			exit(1);
		}

		puts(buf);
	}


int main(void)
{
	char buf[BUFF];
	char message[BUFF];
	
	int s, slen = sizeof(si_other);
	
		if((s = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) == -1){
			exit (1);
		}
	
	
	memset((char *) &si_other, 0, sizeof(si_other));
	si_other.sin_family = AF_INET;
	si_other.sin_port = htons(PUERTO);

	if(inet_aton(SERVER, &si_other.sin_addr) == 0){
		fprintf(stderr, "inet_aton() FALLO!!!\n" );
		exit(1);
	}

	while(1){
		
		
		printf("Ingrese mensaje: \n");
		gets(message);

		//Envio de msj.
		if(sendto(s, message, strlen(message), 0, (struct sockaddr *) &si_other, slen) == -1){
			
			exit(1);
		}

		if (recvfrom(s, buf, BUFF, 0, (struct sockaddr *) &si_other, &slen) == -1)
		{
	
			exit(1);
		}

		puts(buf);
	}

	return 0;
}
