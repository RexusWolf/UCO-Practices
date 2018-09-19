#include "funciones.h"

struct pila * nuevoElemento(int n){
  return ((struct pila *)malloc(n*sizeof(struct pila)));
}

int vacia (struct pila *cabeza){
  if (cabeza == NULL){
    return 1;
    return 0;
  }
}

void verCima(struct pila *cabeza, char* nombre){
  strcpy(nombre, cabeza->contenedor);
}

void liberarMemoria (struct pila *pila){
  free(pila);
}
