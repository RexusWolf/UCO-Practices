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
    printf("Introduce numerador para este nodo:\n");
    scanf("%d", &i->dato.numerador );

    printf("Introduce denominador para este nodo:\n");
    scanf("%d", &i->dato.denominador );
  }


  imprimeNodo();

  int opcion;
  printf("1. Imprimir mayor.\n");
  printf("2. Imprimir menor.\n");
  scanf("%d", &opcion );
  Nodo *a;

  if(opcion==1){
    Fraccion mayor = mayornodo(a);
    printf("Mayor: %d/%d\n", mayor.numerador, mayor.denominador );
  }

  else{
    if(opcion==2){
      Fraccion menor = menornodo(a);
      printf("Menor: %d/%d\n", menor.numerador, menor.denominador ) ;
    }
    else{
    printf("Opcion no valida.");
    }
  }
  liberaNodo();

  return 0;
}
