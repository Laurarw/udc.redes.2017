/* 

  9)Modificar el Server6.c para que cambie el servicio 
  * por uno que devuelva la suma de dos parámetros enteros o una leyenda de error en parámetros 
  * si estos no son enteros y guardelo como Server7.c. 
  * Tips: Usar la función sscanf() y snprintf(). 
  * Cree el cliente correspondiente y guardelo como  Cliente2.c.



*/
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <signal.h>
#include <sys/wait.h>//libreria para que reconozca el waitpid
 #include <ctype.h>
 
#define PORTNUMBER  12345

void atender_cliente(int socket);
void sig_chld(int signo);
int esNumero(char string[]);

int main(void){
    
    int s, ns, len,proceso;
    struct sockaddr_in direcc;
   
    s = socket(AF_INET, SOCK_STREAM, 0);

    bzero((char *) &direcc, sizeof(direcc));
    direcc.sin_family = AF_INET;
    direcc.sin_port = htons(PORTNUMBER);
    direcc.sin_addr.s_addr = htonl(INADDR_ANY);

    len = sizeof(struct sockaddr_in);
    bind(s, (struct sockaddr *) &direcc, len);
    listen(s, 5);
    
    signal(SIGCHLD, sig_chld);
    puts("Servidor corriendo");
    
    while(1){
		 ns = accept(s, (struct sockaddr *) &direcc, &len);
		 
		 proceso=fork();//crea procesos hijos
		 switch(proceso){
			 case -1://es error en el fork()
			printf("fork() error");
        		break;
			case 0: //es un proceso hijo
				close(s);
				printf("Conectando con %s\tPuerto:%d\n", inet_ntoa(direcc.sin_addr),htons(direcc.sin_port));
				atender_cliente(ns);
				close(ns);		
				printf("Finalizando con %s\tPuerto:%d\n", inet_ntoa(direcc.sin_addr),htons(direcc.sin_port));
				exit(0);
			default://es el padre. mayor a cero
				close(ns);

		 }
		 
	}  
         
    close(s);
    exit(0);
}
/*
 Atiende la petición del cliente.
 Función que recibe como parámetro el socket en el que se conecta el cliente.
 No devuelve nada.
 * */
void atender_cliente(int socket){
	char buf[111];
	int n;
	char num1[81], num2[81],respuesta[600];
	int numero1,numero2,suma;
	
	
	 while ((n = recv(socket, buf, sizeof(buf), 0)) > 0){//si o si sizeof para que pase el buff completo
			  
			  buf[n]='\0';//se le agrega el null acá porque sino te manda la basura que queda del array
			  sscanf( buf,"%s %s", num1, num2 );// las palabras separadas por espacios se le asignaran a las variables num1 y num2 respectivamente
						 		  
			//la funcion esNumero determina si es valido o no lo que el cliente mandó
			   if((esNumero(num1) == -1) || (esNumero(num1) == -1)){//si no lo es se le manda el error
				//snprintf guarda en el array (respuesta) el string formado.  
				snprintf(respuesta,sizeof(respuesta),"Error.Ingreso: %s, %s. Solo se permiten numeros enteros",num1,num2);
				write(socket,respuesta, sizeof(respuesta));//mando respuesta
				   
			  }else{//si son ambos validos, lo convierten a int con atoi para sumarlos
				   numero1=atoi(num1);
			       numero2=atoi(num2);
				  suma=numero1+numero2;
				  snprintf(respuesta,sizeof(respuesta),"%d + %d = %d",numero1,numero2,suma);//lo mismo que lo anterior: armo la respuesta a mandar
				  write(socket,respuesta, strlen(respuesta));
				  
				
			  }
			  //se limpian cadenas
			  memset(num1,'\0',strlen(num1));
		      memset(num2,'\0',strlen(num2));
		  
		 }    
}
/*
  Función que muestra cuando un proceso hijo a finalizado
 * 
 * */
void sig_chld(int signo){
	pid_t	pid;
	int	stat;

	while ( (pid = waitpid(-1, &stat, WNOHANG)) > 0)
		printf("   Hijo %d ha terminado\n", pid);
	return;
}
/*
 * Determina si la cadena enviada es un entero.
 * El parametro que recibe es el string a analizar.
 * en caso de que la primera posicion sea un guion '-', sigue bucle ya que se tomaria como un  numero negativo.
 * Si se encuentra en alguna posición un no-digito retorna -1. Si la totalidad de las posiciones resultan tener digitos retorna 0.
 * **/
int esNumero(char palabra[]){
	int letra;
	for(letra=0;letra<strlen(palabra);letra++){
		if(palabra[0]=='-'){
			continue;
		}else if(isdigit(palabra[letra])==0){
											
						return -1;
			  
					}
					
				}
	return 0;
}





