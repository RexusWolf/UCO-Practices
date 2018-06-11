#include "funciones.h"

int main(int argc, char const *argv[]) {
  int n, elem;

    printf("Introduce tamaño vector:");
    scanf("%d", &n);
    int *vector=reservaMemoria(n);
    leerVector(vector, n);
    escribeVector(vector, n);
    printf("Introduce elemento:");
    scanf("%d", &elem);
    mayoritario(vector, n, elem);
    free(vector);

  return 0;
}
