#ifndef __FUNCIONES_HPP
#define __FUNCIONES_HPP

#include <iostream>
#include <cstring>
#include <cstdlib> //Para usar system
#include <fstream> //Para trabajar con ficheros
#include <cmath>

#include "grafo.hpp"
#include "algoritmosgrafos.hpp"

using namespace std;
using namespace ed;

int menu()
{
  int opcion;

  system("clear");
  cout << "  0. Salir................................\n";
  cout << "  1. Cargar grafo desde fichero...........\n";
  cout << "  2. Algoritmo de Floyd (GD y GND)......\n";

  cout << "Introduzca opcion...:";
  cin >> opcion;

  return opcion;
}

template <class G_Nodo, class G_Lado>
bool cargarGrafo(Grafo<G_Nodo, G_Lado> * &g)
{
  string ficheroMatriz, ficheroEtiquetas, buffer;
  ifstream nodosfile;
  ifstream ladosfile;
  int nodoscounter = 0;
  int index = 0;
  G_Nodo node;
  G_Lado edge;


  cout << "Fichero de la matriz de conexion: ";
  cin >> ficheroMatriz;

  cout << "Fichero de las etiquetas: ";
  cin >> ficheroEtiquetas;

  // Necesitamos reservar memoria para el grafo
  nodosfile.open(ficheroEtiquetas.c_str());
  while(getline(nodosfile, buffer)){
    nodoscounter++;
  }
  nodosfile.close();
  g->reservaMemoria(nodoscounter);
  
  // Vuelvo a abrir el fichero para obtener los nodos del fichero
  nodosfile.open(ficheroEtiquetas.c_str());
  // Recorre el fichero nodos y lo almacena en buffer
  while(getline(nodosfile, buffer)){
    node = buffer;
    g->setNodo(index, node);
    index++;
  }
  nodosfile.close();

  // Haremos lo mismo con la matriz
  ladosfile.open(ficheroMatriz.c_str()); // Abrimos los ficheros en modo escritura.  
  for(int fila = 0; fila < g->getNumeroNodos(); ++fila){
    for(int columna = 0; columna < g->getNumeroNodos() - 1; ++columna){
      getline(ladosfile, buffer, ' ');
      int lado = atoi(buffer.c_str());
      edge = lado;
      g->setLado(fila, columna, edge);      
    }
    getline(ladosfile, buffer, '\n');
    int lado = atoi(buffer.c_str());
    edge = lado;
    g->setLado(fila, g->getNumeroNodos() -1, edge);
  }
  ladosfile.close();
  //g->printMatrix();
  //g->printArray();

  return true;
}


template <class G_Nodo, class G_Lado>
void algoritmoFloyd(const Grafo<G_Nodo, G_Lado> &g)
{
  // Matriz de distancias == matrixaux
  G_Lado **matrixaux;
  matrixaux = new G_Lado*[g.getNumeroNodos()];
  for(int i=0; i < g.getNumeroNodos(); ++i){
				matrixaux[i] = new G_Lado[g.getNumeroNodos()];
	}

  g.setMatrix(matrixaux);

  // Diagonal a 1
  for(int i = 0; i < g.getNumeroNodos(); ++i){
    matrixaux[i][i] = 0;
  }

  for(int i = 0; i < g.getNumeroNodos(); ++i){
    for (int j = 0; j < g.getNumeroNodos(); ++j){
      for (int k = 0; k < g.getNumeroNodos(); ++k){
        if (matrixaux[j][i] + matrixaux[i][k] < matrixaux[j][k]){
          matrixaux[j][k] = matrixaux[j][i] + matrixaux[i][k];
        }
      }
    }
  }

  cout<<"Matriz de distancias:"<<endl;
  for(int i = 0; i < g.getNumeroNodos(); ++i){
     cout<<endl;
    for (int j = 0; j < g.getNumeroNodos(); ++j){
      cout<<matrixaux[i][j]<<" ";
    }
  }

  // Matriz de recorridos
  G_Lado **mrecorridos;
  mrecorridos = new G_Lado*[g.getNumeroNodos()];
  for(int i=0; i < g.getNumeroNodos(); ++i){
				mrecorridos[i] = new G_Lado[g.getNumeroNodos()];
	}

  // Matriz a -1
  cout<< g.getNumeroNodos();
  for(int i = 0; i < g.getNumeroNodos(); ++i){
    for(int j = 0; j < pow(g.getNumeroNodos(), 2); ++j){
      mrecorridos[i][j] = -1;
    }
  }

  g.setMatrix(matrixaux);

  // Diagonal a 0
  for(int i = 0; i < g.getNumeroNodos(); ++i){
    matrixaux[i][i] = 0;
  }

  for(int i = 0; i < g.getNumeroNodos(); ++i){
    for (int j = 0; j < g.getNumeroNodos(); ++j){
      for (int k = 0; k < g.getNumeroNodos(); ++k){
        if (matrixaux[j][i] + matrixaux[i][k] < matrixaux[j][k]){
         matrixaux[j][k] = matrixaux[j][i] + matrixaux[i][k];
         mrecorridos[j][k] = i;
        }
      }
    }
  }

  cout<<'\n'<<endl;
  cout<<"Matriz de recorridos:"<<endl;
  for(int i = 0; i < g.getNumeroNodos(); ++i){
     cout<<endl;
    for (int j = 0; j < g.getNumeroNodos(); ++j){
      cout<<mrecorridos[i][j]<<" ";
    }
  }
}

#endif
