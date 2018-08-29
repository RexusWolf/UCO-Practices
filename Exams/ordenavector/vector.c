#include "funciones.h"


int main(int argc, char const *argv[]) {
  int N;
  printf("Introduce numero de elementos del vector:\n");
  scanf("%d", &N );


  Fraccion* vector = reservavector(vector,N);
  escribevector(vector,N);
  imprimevector(vector,N);
  int (*comparacion) (Fraccion, Fraccion);
  int opcion;
  printf("Elige la ordenacion deseada:\n");
    printf("1. Ascendente.\n");
    printf("2. Descendente\n");
  scanf("%d\n", &opcion );
  //if(opcion == 1){ comparacion = &esmenor;}
  //if(opcion == 2){ comparacion = &esmayor;}
  //ordenavector(vector, N, comparacion);
  if(opcion == 1){ ordenavector(vector, 0, N-1, &esmenor);}
  imprimevector(vector,N);
  free(vector);

  return 0;
}
