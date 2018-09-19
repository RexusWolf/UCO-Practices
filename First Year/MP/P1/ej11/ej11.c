#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int es_sufijo (char *cadena, char *prefijo){
  int* ptr;

 if(strstr(cadena, prefijo)) return 1;

 return 0;

}

int main(int argc, char const *argv[]) {

  char cadena[]={"Hola amigo."};
  char prefijo[]={"Hola"};
  printf("%i\n", es_sufijo(cadena, prefijo));
  return 0;
}
