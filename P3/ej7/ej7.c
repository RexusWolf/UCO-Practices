#include "funciones.h"

int main(int argc, char const *argv[]) {
    char file[30];
    printf("Introduce nombre de archivo de texto: ");
    //  scanf("%s\n", file);
      fgets (file, 30, stdin);
    //fgets() permite introducirr una cadena con espacios en blanco, no como scanf()
        //Para quitar el '\n'
          for (int i = 0; i < strlen(file) + 1; i++) {
              if (file[i] == '\n') file[i] = '\0';
          }

      addFile(file);

    return 0;
}
