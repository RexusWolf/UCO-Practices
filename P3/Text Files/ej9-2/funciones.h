#ifndef FUNCIONES_H
#define FUNCIONES_H

    typedef struct Libro{
      char title[50];
      char author[50];
      float cost;
      int stock;
    }Libro;

    #include <stdlib.h>
    #include <stdio.h>
    #include <string.h>

    int countBooks(char *namefile);
    int checkBook (char *namefile, char *title);
    int compare(char *tittle, char *aux);
    FILE* openread(char *namefile);
    void changeChar(char *namechar);
    void listBooks(char *namefile);
    void sellBook(char *namefile, char *title);
    void clearBooks (char *namefile);
    Libro* fileToArray(char *namefile, int size);
    void addBook(char *namefile);
    Libro newBook();
    char* rline(char* dst, FILE* stream);
#endif
