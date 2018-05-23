#ifndef FUNCIONES_H
#define FUNCIONES_H

typedef struct Ficha_jugador{
  char nombre[50];
  int dorsal;
  float peso;
  int estatura;
}ficha;

ficha * reservaMemoria (int nJug);
ficha leerJugador(ficha *jugador);
void rellenarVectorJugadores (ficha *jugadores, int nJug);
void imprimirJugadores (ficha *jugadores, int nJug) ;
void imprimirJugador (ficha *jugador);
int borrarJugadores (ficha *jugadores, int nJug, char letra) ;

#endif
