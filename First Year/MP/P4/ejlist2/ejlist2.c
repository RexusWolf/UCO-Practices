#include <stdio.h>
#include <stdlib.h>
#include "listas.h"

int main(int argc, char const *argv[]) {

  int N;

  printf("¿Cuantos nodos quieres crear?\n");
  scanf("%d",&N );

  for(int i = 0; i<N; i++){
    Nodo *i = reservaNodo();
    nuevoNodo(i);
    printf("Introduce dato para este nodo:\n");
    scanf("%d", &(i->dato) );
  }

  imprimeNodo();
  liberaNodo();

  return 0;
}
