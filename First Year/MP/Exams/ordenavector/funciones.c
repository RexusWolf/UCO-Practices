#include "funciones.h"
#include <time.h>

Fraccion * reservavector(Fraccion *vector, int size){
  vector = (Fraccion*)malloc(size*sizeof(Fraccion));
  return vector;
}

void escribevector(Fraccion *vector, int size){
  srand(time(NULL));
  for(int i = 0; i<size; i++){
    vector[i].numerador = rand () % 100 + 1;
    vector[i].denominador = rand () % 100 + 1;
  }
}

void imprimevector(Fraccion *vector, int size){
  for(int i = 0; i<size; i++){
    printf("Elemento %i: %d/%d\n", i, vector[i].numerador, vector[i].denominador );
  }
}


void ordenavector(Fraccion *vector, int size, int(*comparacion)(Fraccion, Fraccion)  ){
  int i, j;
  Fraccion aux;
  for(int i =1; i<size; i++){
    for(j = 0; j<size-1;j++){
      if( (*comparacion)(vector[j], vector[j+1]) ){
        aux = vector[j];
        vector[j] = vector[j+1];
        vector[j+1] = aux;
      } //Llave if
    } //Llave for j
  } //Llave for i
} //Llave fin de función.


int esmayor(Fraccion a, Fraccion b){
  float valora;
  float valorb;
  valora = a.numerador / a.denominador;
  valorb = b.numerador / b.denominador;
  if (valora>valorb) return 1;
  return 0;
}

int esmenor( Fraccion a, Fraccion b){
  float valora;
  float valorb;
  valora = a.numerador / a.denominador;
  valorb = b.numerador / b.denominador;
  if (valora<valorb) return 1;
  return 0;
}
/*
void ordenavector(Fraccion *vector, int izda, int dcha, int(*comparacion)(Fraccion, Fraccion)  ){
  int i, j;
  Fraccion aux;
  for(i = izda + 1; i <= dcha; i++) {
    for(j = dcha; j >= i; j--) {
      if( (*comparacion)(vector[j], vector[j-1]) ){
        aux = vector[j];
        vector[j] = vector[j-1];
        vector[j-1] = aux;
      } //Llave if
    } //Llave for j
  } //Llave for i
} //Llave fin de función.
*/
