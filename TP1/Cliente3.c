#include <stdio.h> //printf
#include <string.h>    //strlen
#include <sys/socket.h>    //socket
#include <arpa/inet.h> //inet_addr
#include <unistd.h>
#include <stdlib.h>
#include <ctype.h>
 typedef struct Suma
{
	int num1;
	int num2;
	int resultado;
	int flag;//-1 si no es valido. 0 si es valido
	char mje_error[100];
	
} s_suma;

#define PORTNUMBER  12345

/*DECLARACIÓN DE FUNCIONES
 * */
int esNumero(char palabra[]);

/*
 * BLOQUE MAIN
 * */
int main(int argc , char *argv[])
{
    int sock,u;
    s_suma suma, suma_rcv;
    struct sockaddr_in server;
    char message[1000],num1[81], num2[81];
   
    
    //Create socket
    sock = socket(AF_INET , SOCK_STREAM , 0);
    if (sock == -1)
    {
        printf("No se puede crear Socket");
    }
    
     
    server.sin_addr.s_addr = htonl(INADDR_ANY);
    server.sin_family = AF_INET;
    server.sin_port = htons( PORTNUMBER );
 
    //se conecta con el server remoto
    if (connect(sock , (struct sockaddr *)&server , sizeof(server)) < 0)
    {
        perror("Conección falló. Error");
        return 1;
    }
     
    puts("Conectado");
     puts("\tSERVIDOR SUMA...\n");

    //mantener la comunicación con el server
   
   
    while(1)
    {
		 memset(num1,'\0',strlen(num1));
		 memset(num2,'\0',strlen(num2));
		 memset(message,'\0',strlen(message));
		puts("Ingrese dos numeros enteros separados por un espacio. La falta de uno de ellos se toma como cero . Ej: 4 4");	
    
      
        fgets(message,sizeof(message),stdin);		
		sscanf( message,"%s %s", num1, num2 );
		
		
		/*BLOQUE DE WRITE
		 * depende de lo que el cliente ingrese se carga la estructura correspondiente a enviar al server
		 * 
		 * */
		if((esNumero(num1) == -1) || (esNumero(num2) == -1)){//si lo que ingresa el cliente no son numeros enteros
				
			suma.num1=0;
			suma.num2=0;
			suma.flag=-1;//se le manda este valor para que el server sepa tratar el error
			suma.resultado=0;
			memset(suma.mje_error,'\0',strlen(suma.mje_error));
			write (sock, &suma, sizeof(s_suma));
			
		}else{//si ingresa solo numeros
			
			//sscanf( message,"%d %d", &suma.num1, &suma.num2 );
			suma.num1=atoi(num1);
			suma.num2=atoi(num2);
			suma.flag=0;
			suma.resultado=0;
			memset(suma.mje_error,'\0',strlen(suma.mje_error));
			write (sock, &suma, sizeof(s_suma));
			
		}
		
		/*
		 * BLOQUE DE RECV
		 * Lo que se reciba en suma_rcv.flag determinará que se mostrará en pantalla
		 * */
		 	u=recv(sock, &suma_rcv, sizeof(s_suma), 0);		 	
		 	if(suma_rcv.flag==0){
				
				printf("La respuesta de %d + %d = %d\n\n",suma.num1,suma.num2,suma_rcv.resultado);  
			}else{
				printf("Error: %s\n\n",suma_rcv.mje_error);  
			}
		
    }
     
    close(sock);
    return 0;
}

/*
 * Determina si la cadena enviada es un entero.
 * El parametro que recibe es el string a analizar.
 * en caso de que la primera posicion sea un guion '-', sigue bucle ya que se tomaria como un  numero negativo.
 * Si se encuentra en alguna posición un no-digito retorna -1. Si la totalidad de las posiciones resultan tener digitos retorna 0.
 * **/
int esNumero(char palabra[]){
	
	for(int letra=0;letra<strlen(palabra);letra++){
		if(palabra[0]=='-'){
			
			continue;
		}else if(isdigit(palabra[letra])==0){
										
						return -1;
			  
					}
					
				}
				
	return 0;
}

