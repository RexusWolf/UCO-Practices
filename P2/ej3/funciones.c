#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"


Ficha * reservaMemoria (int nJug){
Ficha *jugadores;
  if(jugadores=(Ficha *) malloc (nJug*sizeof(Ficha))==NULL){
    printf("Error en la reserva de memoria.");
    exit(-1);
  }
  else{return jugadores;}
}

Ficha leerJugador(Ficha *jugador){
    printf("Introduce nombre del jugador:\n");
    scanf("%s", jugador -> nombre);
    printf("Introduce dorsal del jugador:\n");
    scanf("%i", jugador -> dorsal);
    printf("Introduce peso del jugador:\n");
    scanf("%f", jugador -> peso);
    printf("Introduce estatura del jugador:\n");
    scanf("%i", jugador -> estatura);
  }
}

void rellenarVectorJugadores (Ficha *jugadores, int nJug) {
  for (int i = 0; i < nJug; i++) {
    jugadores[i] = leerJugador (jugadores[i]);
  }
}

void imprimirJugadores (Ficha *jugadores, int nJug) {
  for (int i = 0; i < nJug; i++) {
    printf("Nombre Jugador: %s\n", jugador[i] -> nombre);
    printf("Dorsal: %s\n", jugador[i] -> dorsal);
    printf("Peso: %s\n", jugador[i] -> peso);
    printf("Estatura: %s\n", jugador[i] -> estatura);
  }
}

int borrarJugadores (Ficha *jugadores, int nJug, char letra) {
  for (int i = 0; i < nJug; i++) {
    for (int j = 0; j < 50; j++) {
      if (letra == jugador[i] -> nombre[j]) {
        printf("Caracter encontrado\n");
        nJug--;
        jugador[i] = jugador[nJug]
      }
    }
  }
  jugadores = (Ficha *) realloc (nJug, sizeof(ficha))
}
