#Fichero: makefile

#Construye una biblioteca (libMemoria.a) a partir de los ficheros objetos de reservaMemoria.c y liberaMemoria.c.
libMemoria.a:	reservaMemoria.c liberaMemoria.c
		gcc -c -o reservaMemoria.o reservaMemoria.c
		gcc -c -o liberaMemoria.o liberaMemoria.c
		ar rsv libMemoria.a liberaMemoria.o reservaMemoria.o

#Construye el ejecutable crucigrama.x a partir de la biblioteca y los ficheros objetos de main.c, ficheros.c y crucigrama.c
crucigrama.x:	libMemoria.a main.c ficheros.c crucigrama.c
		gcc -c main.c
		gcc -c crucigrama.c
		gcc -c ficheros.c
	 	gcc -o crucigrama.x main.o ficheros.o crucigrama.o libMemoria.a

#Elimina los ficheros objetos generados.
clean:
		rm *.o
