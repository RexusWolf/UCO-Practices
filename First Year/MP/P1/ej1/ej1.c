#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {

  int a, *b, **c;
  double d, *e, **f;
  char g, *h, **i;

  printf("Los tamaños de las variables son:\n" );

  printf("a:%ld *b:%ld **c:%ld\n",sizeof(a), sizeof(b),sizeof(c) );
  printf("d:%ld *e:%ld **f:%ld\n", sizeof(d),sizeof(e),sizeof(f) );
  printf("g:%ld *h: %ld **i:%ld\n", sizeof(g),sizeof(h),sizeof(i));
  return 0;
}
