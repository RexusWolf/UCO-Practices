#include "funciones.h"


int main(int argc, char const *argv[]) {

  float N;
  char functionchosen[5];
  printf("Introduce N para intervalo: ");
  scanf("%f", &N);
  printf("Introduce funcion a evaluar: ");
  scanf("%s", functionchosen);

  void (*cf)(float N);
  if (strcmp(functionchosen,"fx")==0){ //Compara la cadena "functionchosen" con el nombre de la función.
    cf = &fx; //Asigna la dirección de la función fx al puntero a función.
    (*cf)(N);} //Entra en la función y realiza su secuencia.
  if (strcmp(functionchosen,"gx")==0){
    cf = &gx;
    (*cf)(N);}
  if (strcmp(functionchosen,"zx")==0){
    cf = &zx;
    (*cf)(N);}

  return 0;
}
