#include "funciones.h"

int main(int argc, char const *argv[]) {
  if (argc != 5){
    printf("Usage: fichero.dat Nelementos Ninferior Nsuperior\n");
    exit(-1);
  }

    char namefile[100];
    strcpy (namefile, argv[1]);
    int numelem = atoi(argv[2]);
    int inf = atoi(argv[3]);
    int sup = atoi(argv[4]);
    FILE * f;
    int* array = RandomArray(numelem);
    writeOnArray(array, numelem, sup, inf);
    addFile(namefile, array, numelem);



  return 0;
}
