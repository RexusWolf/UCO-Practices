#include <stdlib.h>
#include <stdio.h>
int minimo (int a, int b){
  if (a<b) return a;
  else return b;
}

int main(int argc, char const *argv[]) {
int a,b;
  printf("Introduce 1 número entero:\n");
  scanf("%d",&a);
  printf("Introduce otro:\n");
  scanf("%d",&b);

  printf("El menor de los dos es %d.", minimo(a,b) );
  return 0;
}
