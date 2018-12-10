#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>

double counter = 0;

#define ITER	1000 // Define un interador a 1000
#define NHILOS	4  // Define el número de hilos que crearemos.

int main()
{
    pthread_t hilos[NHILOS]; // Array de hebras/hilos
    int status, i, v[NHILOS]; // Declara el status, i, y un vector de enteros.
    void *adder(void *);
    double *r_value; // Declara return value, tipo double.

    // Variables globales compartidas
    extern double counter; // Declara counter, una variable global de tipo double.
    extern bool eligiendo[NHILOS];
    int numero[NHILOS];

    // Inicialización de variables
    bool eligiendo[NHILOS] = {false, false, false, false};
    int numero[NHILOS] = {0, 0 , 0 , 0};

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

void *adder(void *p)
{
    double l, *to_return; // Declara l, tipo double, y to_return, puntero a double.
    extern double counter; // Declara la variable global counter.
    int *id, i; // Declara un puntero a entero id e i.
    id = (int *) p; // Asigna al puntero id el puntero de enteros pasado como arg.

    extern bool eligiendo[NHILOS];
    extern int numero[NHILOS];
    int j;

    while(true){
      eligiendo[p[i]] = true;
      numero[p[i]] = max(numero[0], numero[1], numero[2], numero[3]) + 1;
      eligiendo[p[i]] = false;
      for (j=0; j<N; j++){
        while (eligiendo[j]);
        while ((numero[j] != 0)  (numero[j], j) < (numero[p[i]], p[i]))
      }


        for (i = 0; i < ITER; i++) { // Comienza el bucle.
        	l = counter; // Asigna el valor de counter a l.
        	fprintf(stdout, "Hilo %d: %f\n", *id, counter); // Imprime la id del hilo y el counter.
        	l++; // Aumenta el valor de l.
        	counter = l; // Asigna l, cuyo valor es el de counter al inicio + 1000 iteraciones.
        }

        numero[p[i]] = 0;
    }

    to_return = malloc(sizeof(double)); // Reserva memoria para un puntero a double.

    *to_return = counter; // Asigna el valor de counter al puntero que retorna el hilo.

    pthread_exit((void *) to_return);
}


  /* La suma total (counter) no es correcta, ya que son dos o más hilos los que
  entren simultáneamente a la sección crítica, por lo que la variable global counter
  es tomada por los hilos con un valor inicial distinto al esperado por el usuario,
  es decir, al ejecutarse un hilo comienza a aumentar el valor de counter pero puede
  darse el caso de que este hilo se bloquee y comience a ejecutarse otro, cuya
  variable counter tendrá el valor que el hilo anteriormente ejecutado asignó a esta.
  */
