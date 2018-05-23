#ifndef FUNCIONES_H
#define FUNCIONES_H

typedef struct Ficha_jugador {
  char nombre[50];
  int dorsal;
  float peso;
  int estatura;
}Ficha;

Ficha * reservaMemoria (int nJug);

Ficha leerJugador(Ficha *jugador);

void rellenarVectorJugadores (Ficha *jugadores, int nJug);

void imprimirJugadores (Ficha *jugadores, int nJug) ;

int borrarJugadores (Ficha *jugadores, int nJug, char letra) ;


#endif
