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
  scanf("%d", &opcion );
  if(opcion == 1){ comparacion = &esmayor;}
  if(opcion == 2){ comparacion = &esmenor;}
  ordenavector(vector, N , comparacion);
  imprimevector(vector,N);
  free(vector);

  return 0;
}
