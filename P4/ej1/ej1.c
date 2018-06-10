#include "funciones.h"


int main(int argc, char const *argv[]) {

  int N;
  char functionchosen[5];
  printf("Introduce N para intervalo: ");
  scanf("%f", &N);
  printf("Introduce funcion a evaluar: ");
  scanf("%s", functionchosen);
  void (*cf)(float N);
  cf = &fx;
  (*cf)(N);

  return 0;
}
