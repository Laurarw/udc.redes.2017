servicio: servicio.o helper.o servreq.o requestHead.o responseHead.o resource.o
	gcc -o servicio servicio.o helper.o servreq.o requestHead.o responseHead.o resource.o -Wall

webserv.o: webserv.c helper.h servreq.h
	gcc -o webserv.o webserv.c -c -ansi -pedantic -Wall

helper.o: helper.c helper.h
	gcc -o helper.o helper.c -c -ansi -pedantic -Wall

servreq.o: servreq.c servreq.h helper.h
	gcc -o servreq.o servreq.c -c -ansi -pedantic -Wall

requestHead.o: requestHead.c requestHead.h servreq.h helper.h
	gcc -o requestHead.o requestHead.c -c -ansi -pedantic -Wall

responseHead.o: responseHead.c responseHead.h helper.h
	gcc -o responseHead.o responseHead.c -c -ansi -pedantic -Wall

resource.o: resource.c resource.h
	gcc -o resource.o resource.c -c -ansi -pedantic -Wall

servidorhhtp: servidorhttp.o
	gcc -o servidorhttp servidorhttp.c
	
