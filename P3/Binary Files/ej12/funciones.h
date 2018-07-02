#ifndef FUNCIONES_H
#define FUNCIONES_H

    #include <stdlib.h>
    #include <stdio.h>
    #include <string.h>
    typedef struct Libro{
      char title[50];
      char author[50];
      float cost;
      int stock;
    }Libro;
    Libro newBook();
    void addBook(char *namefile);
    void changeChar(char *namechar);
    FILE* openread (char *namefile);
    char* rline(char* dst, FILE* stream);
    int checkBook (char *namefile, char* title);
    int compare(char* name1, char* name2);
    int countBooks (char* namefile);
    void listBooks(char* namefile);
    Libro* libraryArray(char* namefile, int size);
    void sellBook(char* namefile, char* title);
    void clear(char* namefile);

#endif
