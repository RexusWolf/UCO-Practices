#ifndef FUNCIONES_H
#define FUNCIONES_H

    #include <stdio.h>
    #include <stdlib.h> //Permite usar malloc()
    #include <time.h>
    #include <string.h>
    void addFile (char *namefile, int* array, int numelem);
    int* RandomArray(int numelem);
    int* writeOnArray (int* array, int numelem, int N, int M);

/*------------------------------------------------------------------------------
Codifica un programa en C que, utilizando funciones, cree un fichero binario con números
enteros generados aleatoriamente en un intervalo especificado por el usuario. El programa
guardará los números en un vector dinámico antes de volcarlo a disco. El programa recibirá 4
parámetros como argumentos en la línea de órdenes: nombre del fichero a crear, número de
elementos que contendrá el fichero y los extremos superior e inferior del intervalo.
------------------------------------------------------------------------------*/

#endif
