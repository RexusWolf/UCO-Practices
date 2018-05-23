#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int estadisticasCadena (char* cadena){
int i = 0;
for(i = 0; ; i++){
  if (cadena[i]=='\0'){return i;}
}

return i;
    }
int main(int argc, char const *argv[]) {
      char cadena[] = {'H','o','l','a'};

      printf("El tamaño es: %d", estadisticasCadena(cadena) );
    return 0;
  }
