#include <stdlib.h>
#include <stdio.h>

int min (int a, int b, int *resultado){
  if (a<b) resultado = a;
  else resultado=b;
  return resultado;
}

int main(int argc, char const *argv[]) {
int a,b,res=0;
  printf("Introduce 1 número entero:\n");
  scanf("%d",&a);
  printf("Introduce otro:\n");
  scanf("%d",&b);

  printf("El menor de los dos es %d.", min(a,b,&res) );
  return 0;
}
