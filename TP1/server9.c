#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define BUFF 100
#define PUERTO 12345

struct sockaddr_in si_me, si_other;

void service(int s){
	int slen = sizeof(si_other), recv_len;
	char buf[BUFF] = "/0";
	
		printf("Datos... \n");
		fflush(stdout);

		if ((recv_len = recvfrom(s, buf, BUFF, 0, (struct sockaddr *) &si_other, &slen)) == -1)
		{
			exit (1);
		}
		
		printf("Recibido : %s\n", buf );
		 
		if(sendto(s, buf, recv_len, 0, (struct sockaddr*) &si_other, slen) == -1){
			exit (1);
		}
	
}

int main(void){
	
	int s;	
	
	//Creación de socket UDP
	if((s = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) == -1){
			exit (1);
		}
		
	memset((char *) &si_me, 0, sizeof(si_me));
	
	si_me.sin_family = AF_INET;
	si_me.sin_port = htons(PUERTO);
	si_me.sin_addr.s_addr = htonl(INADDR_ANY);

	if(bind(s, (struct sockaddr*)&si_me, sizeof(si_me)) == -1){
		exit (1);
	}
	
	while(1){
		service(s);
	}
	return 0;
}
