#include <stdlib.h>
#include <stdio.h>


void leerVector(double vector[]){
  for(int i=0; i<10; i++){
    printf("Introduce elemento número %i:\n",i );
    scanf("%lf", &vector[i]);
  }

}

void escribeVector (double vector[]){
  for(int i=0; i<10; i++){
    printf("%f\n", vector[i] );
  }
}
int sumaPositivos (double vector[]){

int suma=0;

for(int i=0; i<10; i++){
  if(vector[i]>0) suma += vector[i];
}
  return suma;
}


int main(int argc, char const *argv[]) {

  double vector[10];
  leerVector(vector);
  escribeVector(vector);
  printf("La suma es %i\n", sumaPositivos(vector));




  return 0;
}
