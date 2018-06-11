#include "funciones.h"

int* reservaMemoria (int n){
int *vector;
  if ((vector = (int*)malloc(n*sizeof(int)))==NULL){
    printf("Error en la reserva de memoria.");
  }
  return vector;
}

void leerVector(int *vector, int n){
  for(int i=0; i<n; i++){
    printf("Introduce elemento número %i:\n",i );
    scanf("%d", &vector[i]);
  }
}

void escribeVector (int *vector, int n){
  for(int i=0; i<n; i++){
    printf("%d\n", vector[i] );
  }
}

void mayoritario(int *vector, int n, int elem){
  int c= 0;
    for(int i = 0; i<n; i++){
          if(vector[i]==elem) c++;
    }
  if ((c)>=n/2){
    printf("%d Es mayoritario.\n", elem );
  }

}
