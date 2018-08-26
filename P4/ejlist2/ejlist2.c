#include <stdio.h>
#include <stdlib.h>
#include "listas.h"

int main(int argc, char const *argv[]) {

  int N;

  printf("¿Cuantos nodos quieres crear?\n");
  scanf("%d",&N );

  for(int i = 0; i<N; i++){
    if(i==0){
      Nodo *primero = reservaNodo();
      nuevoNodo(primero);
    }
    Nodo *i = reservaNodo();
    nuevoNodo(i);
    printf("Introduce dato para este nodo:\n");
    scanf("%d", &(i->dato) );

  }

  Nodo *a = *(primero);
  while(a!=NULL){
    printf("%d\n", a->dato );
    a = a->sgte;
  }

  Nodo *b = *(primero);
  while(b!=NULL){
    liberaNodo(b);
    b = b -> sgte;
  }
  return 0;
}
