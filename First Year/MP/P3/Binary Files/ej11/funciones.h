#ifndef FUNCIONES_H
#define FUNCIONES_H

    #include <stdio.h>
    #include <stdlib.h> //Permite usar malloc()
    #include <time.h>
    #include <string.h>
    void addFile (char *namefile, int* array, int numelem);
    int* RandomArray(int numelem);
    int* writeOnArray (int* array, int numelem, int N, int M);
    float evenNumbers(int* array, int numelem);
    int* copyArray (int* array, int* array2, int numelem);
/*------------------------------------------------------------------------------
Codifica un programa en C que, utilizando funciones, lea números enteros desde un fichero
binario generado en el ejercicio anterior, almacene sus valores en un vector dinámico y, a
continuación, calcule la media de los números pares. El nombre del fichero se le preguntará al
usuario.
------------------------------------------------------------------------------*/

#endif
