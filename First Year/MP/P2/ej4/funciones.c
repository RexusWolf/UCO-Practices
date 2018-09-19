#include "ej4_funciones.h"

int ** reservarMemoria (int nFil, int nCol) {
  int **matriz;
  matriz = (int**) calloc (nFil, sizeof(int *));
  for (int i = 0; i < nFil; i++) {
    matriz[i] = (int *) calloc (nCol, sizeof(int));
  }
  if (matriz == NULL) printf("Fallo en la reserva de memoria\n");
  else return matriz;
}

void rellenaMatriz (int** matriz, int nFil, int nCol) {
  srand(time(NULL));
  for (int i = 0; i < nFil; i++) {
    for (int j = 0; j < nCol; j++) {
      matriz[i][j] = (rand() % 20) + 1;
    }
  }
}

void imprimeMatriz (int **matriz, int nFil, int nCol) {
  for (int i = 0; i < nFil; i++) {
    printf("\n");
    for (int j = 0; j < nCol; j++) {
      printf("%i\t", *(*(matriz+i)+j));
    }
  }
}

int * minCol (int **matriz, int nFil, int nCol) {
  int *vMins;
  vMins = (int *) calloc (nCol, sizeof(int));
  for (int i = 0; i < nCol; i++) {
    vMins[i] = matriz[0][i];
    for (int j = 1; j < nFil; j++) {
      if(vMins[i] > matriz[j][i]) vMins[i] = matriz[j][i];
    }
  }
  return vMins;
}

void liberarMemoria (int **matriz, int nFil) {
  for (int i = 0; i < nFil; i++) {
    free (matriz[i]);
  }
  free (matriz);
}
