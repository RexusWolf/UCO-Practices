#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
//Credits to @cyberh99
int main(int argc, char const *argv[]) {
ficha *jugadores;
int nJug;
printf("Introduce número de jugadores:");
scanf("%d",&nJug);
jugadores = reservaMemoria(nJug);
for(int i=0;i<nJug;i++){
  leerJugador(jugadores+i);
}

int opcion;
char letra;
printf("Elige opcion: ");
printf("1.Listar jugadores.");
printf("2. Rellenar lista jugadores.");
printf("3.Borrar jugadores con una a en el nombre.");
printf("0. Salir.");
scanf("%d", &opcion);

      switch (opcion) {

        case 1: imprimirJugadores(jugadores,nJug);
                break;

        case 3:
        printf("Introduce una letra:");
        scanf("%c\n", &letra );
        borrarJugadores(jugadores,nJug, letra);
        break;
        case 0: exit(-1);
                break;
      }

        return 0;

        free(jugadores);
      }
