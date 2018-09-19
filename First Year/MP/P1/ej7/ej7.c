#include <stdlib.h>
#include <stdio.h>

void estadisticasVector (int v[], int *nelem){
  float media = 0;
  float suma = 0;
  printf("%i\n", *nelem);
  for(int i=0; i<(*nelem);i++){
    suma += v[i];
  }
  media = suma/(*nelem);
  printf("La media es: %f\n", media);

}
int main(int argc, char const *argv[]) {

int vector[10]={0,1,2,3,4,5,6,7,8,9};
int tam = 10;
estadisticasVector(vector, &tam);
  return 0;
}
