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
    int* array2 = RandomArray(numelem);
    copyArray(array, array2, numelem);
    printf("La media es %f\n", evenNumbers(array2, numelem));


  return 0;
}
