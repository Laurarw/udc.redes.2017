package socket;

//Servidor que anda con el cliente java del tp1


import java.io.*;
import java.net.*;


//-------------------
//|		SOCKET		|
//-------------------

class MyStreamSocket extends Socket {
	private Socket  socket; //socket de atencion al cliente
	private String recibe;//lo que el cliente manda/recibe el servidor
	
	//constructor del socket que tiene como parametro otro socket
	MyStreamSocket(Socket socket)  throws IOException {
		this.socket = socket;
	}

	public void enviar(String recibe) throws IOException{
		DataOutputStream outStream = new DataOutputStream(socket.getOutputStream());
		
		//imprime la respuesta por la salida, es decir se lo manda al cliente
		outStream.writeUTF(recibe);
		
	}//Finaliza el envio del mensaje al cliente
	public String recibir() throws IOException{
		
		DataInputStream inStream = new DataInputStream(socket.getInputStream());
	    recibe = inStream.readUTF();//se lee lo que recibe y lo guarda en un buffer
	   return recibe;
	}//Finaliza la recepcion del mensaje que envio el cliente al servidor
	
} //Termina clase socket de atencion




//--------------------------
//|		SERVIDOR ECHO		|
//--------------------------


public class Server {
  
	public static final String CERRAR = "."; 	//indica con que caracter se termina la conexion
	public static final int PUERTO=12345; 		// numero de puerto donde se presta el servicio
  
	
	//inicia el main del servidor
	public static void main(String[] args) {
	        
	    try {
	    	//se instancia un socket para aceptar conexiones
	    	ServerSocket s = new ServerSocket(PUERTO); 
	    	System.out.println("Se inicio el servidor.");  
	    	while (true) {  //bucle infinito
	    		//se espera una conexion 
	    		System.out.println("Se espera una conexion.");
	    		//conexion aceptada
	    		MyStreamSocket ns = new MyStreamSocket (s.accept( ));//nuevo socket de atencion
	    		System.out.println("Conexion Aceptada");
		    		
	    //---------------------------
	    //|		Servicio echo		|
	    //---------------------------
	    		Echo(ns);
	    		
	    	} //Termina bucle infinito
	    } // end try
	    catch (Exception ex) {
	       ex.printStackTrace( );
	    }
	} //Termina Main Server
	
	
	
	
    //---------------------------
    //|		SERVICIO ECHO		|
    //---------------------------
	

public static void Echo(MyStreamSocket ns) throws IOException{
		
		boolean finalizar = false;//no finalizo la conexion
		 String mensaje;//mensaje 
		 
		//se le informa al cliente como debe cerrar la conexion
		//ns.sendMessage("Para cerra la conexion enviar . "+CERRAR);
		
		//hacer mientras la conexion no finalice
		while (!finalizar) {
			//recibe el mensaje
			
			mensaje = ns.recibir( );//se recibe el mensaje desde el cliente
			ns.enviar(mensaje);	//se contesta al cliente con el echo
			ns.close( );//se cierra conexion
			finalizar = true;//finalizar ahora es verdadero para poder salir del bucle

		} //Termina bucle while(!finalizar) por que finalizar es verdadero
		//se deja de atender al cliente
		
	}//Termina metodo Echo 
	
	
	
} // Termina clase Server