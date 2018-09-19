#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"


ficha* reservaMemoria (int nJug){
ficha *jugadores;
jugadores = malloc (nJug*sizeof(ficha));
  if(jugadores==NULL){
    printf("Error en la reserva de memoria.");
    exit(-1);
  }
  else {
    return jugadores;
  }
}

ficha leerJugador(ficha *jugador){
  char nombre[50];
	int dorsal,estatura;
  float peso;
    printf("Introduce el nombre del jugador\n");
      setbuf(stdin,NULL);
      gets(nombre);
        strcpy(jugador->nombre,nombre);
    printf("Introduce dorsal del jugador:\n");
    scanf("%i", &dorsal );
      jugador -> dorsal = dorsal;
    printf("Introduce peso del jugador:\n");
    scanf("%f", &peso);
      jugador -> peso = peso;
    printf("Introduce estatura del jugador:\n");
    scanf("%i", &estatura);
      jugador -> estatura = estatura;
  }


void rellenarVectorJugadores (ficha *jugadores, int nJug) {
  for (int i = 0; i < nJug; i++) {
    leerJugador (jugadores+i);
  }
}
void imprimirJugadores (ficha *jugadores, int nJug) {
  for (int i = 0;i<nJug;i++){
    imprimirJugador((jugadores+i));
    printf("\n");
  }
}

void imprimirJugador (ficha *jugador) {
    printf("Nombre Jugador: %s\n", jugador -> nombre);
    printf("Dorsal: %d\n", jugador -> dorsal);
    printf("Peso: %f\n", jugador -> peso);
    printf("Estatura: %d\n", jugador -> estatura);

}

int borrarJugadores (ficha *jugadores, int nJug, char letra) {
  for (int i = 0;i<nJug;i++){
    if (strchr(((jugadores+i)->nombre),letra)){
      printf("Caracter found\n");
      printf("%s\n",(jugadores+i)->nombre );
      jugadores = jugadores - 1;
      for (int j = i; j<nJug;j++){
        *(jugadores+j) = *(jugadores+1);
      }
      i = i-1;
    }

    printf("\n");
  }
  jugadores = (ficha *)realloc(jugadores,nJug);

  return (nJug);
}
