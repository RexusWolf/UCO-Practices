/*
Francisco Javier Molina Prieto
P2 Ejercicio 2.
Algoritmo de Lamport
*/

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define ITER	1000 // Define un interador a 1000
#define NHILOS	4  // Define el número de hilos que crearemos.

double counter = 0;
int eligiendo[NHILOS];
int numero[NHILOS];

int main()
{
    pthread_t hilos[NHILOS]; // Array de hebras/hilos
    int status, i, v[NHILOS]; // Declara el status, i, y un vector de enteros.
    void *adder(void *);
    double *r_value; // Declara return value, tipo double.

    // Variables globales compartidas
    extern double counter; // Declara counter, una variable global de tipo double.
    extern int eligiendo[NHILOS];
    extern int numero[NHILOS];

    for(int i = 0; i<NHILOS; i++){
      eligiendo[i] = 0;
      numero[i] = 0;
    }


    // Create NHILOS threads
    for (i = 0; i < NHILOS; i++) {
	v[i] = i; // Asigna al vector de enteros los índices del hilo.
	if ((status = pthread_create(&hilos[i], NULL, adder, (void *) &v[i])))
	    exit(status); // Se crea el hilo, que ejecutará la función adder.
                   // Esta función recibe un casting del vector de enteros.
    }

    // Wait threads
    for (i = 0; i < NHILOS; i++) {
	pthread_join(hilos[i], (void **) &r_value);
	printf("Value returned by %lu thread: %lf\n", hilos[i], *r_value);
    }

    // Final result
    fprintf(stdout, "%f\n", counter);

    return 0;
}

int mayorVector(int *numero){
  int mayor = 0;
  for(int i = 0; i < NHILOS; i++){
    if (numero[i] > mayor){
      mayor = numero[i];
    }
  }
  return mayor;
}

void *adder(void *p)
{
    double l, *to_return; // Declara l, tipo double, y to_return, puntero a double.
    extern double counter; // Declara la variable global counter.
    int *id, i; // Declara un puntero a entero id e i.
    id = (int *) p; // Asigna al puntero id el puntero de enteros pasado como arg.

    extern int eligiendo[NHILOS];
    extern int numero[NHILOS];
    int j;

    for(i = 0; i < ITER; i++){
      eligiendo[*id] = 1;
      numero[*id] = mayorVector(numero) + 1;
      eligiendo[*id] = 0;
      for(j = 0; j < NHILOS; j++){
        while(eligiendo[j]);
        while((numero[j] != 0) && ((numero[j] < numero[*id]) || ((numero[j] == numero[*id]) && ((j < *id)))));
      }


        // Comienza la SECCIÓN CRÍTICA.
        	l = counter; // Asigna el valor de counter a l.
        	fprintf(stdout, "Hilo %d: %f\n", *id, counter); // Imprime la id del hilo y el counter.
        	l++; // Aumenta el valor de l.
        	counter = l; // Asigna l, cuyo valor es el de counter al inicio + 1000 iteraciones.
        // Termina la SECCIÓN CRÍTICA

        numero[*id] = 0;
    }

    to_return = malloc(sizeof(double)); // Reserva memoria para un puntero a double.

    *to_return = counter; // Asigna el valor de counter al puntero que retorna el hilo.

    pthread_exit((void *) to_return);
}
