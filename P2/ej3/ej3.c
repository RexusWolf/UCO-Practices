#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"


int main(int argc, char const *argv[]) {
int nJug;
printf("Introduce número de jugadores:");
scanf("%d\n",&nJug);
Ficha *jugadores;
reservaMemoria(nJug);
leerJugador(jugadores);
int opcion;
char letra;
printf("Elige opcion: ");
printf("1.Listar jugadores.");
printf("2. Rellenar lista jugadores.\n");
printf("3.Borrar jugadores con una a en el nombre.");
printf("0. Salir.");
scanf("%d\n", &opcion);

      switch (opcion) {
        case 0: exit(-1);
                break;
        case 1: imprimirJugadores(jugadores,nJug);
                break;
        case 2: rellenarVectorJugadores(jugadores,nJug);
                break;
        case 3:
        printf("Introduce una letra:");
        scanf("%c\n", &letra );
        borrarJugadores(jugadores,nJug, letra);
        break;
      }

        return 0;
      }
