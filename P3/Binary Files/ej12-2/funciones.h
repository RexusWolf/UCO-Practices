#ifndef FUNCIONES_H
#define FUNCIONES_H

    #include <stdlib.h>
    #include <stdio.h>
    #include <string.h>
    typedef struct Libro{
      char title[50];
      char author[50];
      float price;
      int stock;
    }Libro;


      void clearBooks (char *namefile);
      FILE * openread (char* namefile);
      void changeChar(char *namechar);
      Libro newbook();
      void addBook(char *namefile);
      int countBooks(char *namefile);
      int checkBook (char *namefile, char *title);
      Libro * filetoArray(char *namefile);
      void listBooks (char *namefile);
      void sellBook (char *namefile, char *title);
      int compare(char* name1, char* name2);
#endif
