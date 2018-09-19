#Fichero: makefile

a.exe: ejlist.o funciones.o funciones.h
	gcc funciones.o ejlist.o

*.o: ejlist.c funciones.c
	gcc -c ejlist.c
	gcc -c funciones.c
