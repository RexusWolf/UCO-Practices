#ifndef __FUNCIONES_HPP
#define __FUNCIONES_HPP

#include <iostream>
#include <cstring>
#include <cstdlib> //Para usar system
#include <fstream> //Para trabajar con ficheros

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
  string ficheroMatriz, ficheroEtiquetas;

  cout << "Fichero de la matriz de conexion: ";
  cin >> ficheroMatriz;

  cout << "Fichero de las etiquetas: ";
  cin >> ficheroEtiquetas;

  int nodoscounter = 0;
  ifstream nodosfile;
  ifstream ladosfile;

  ladosfile.open(ficheroMatriz.c_str()); // Abrimos los ficheros en modo escritura.
  nodosfile.open(ficheroEtiquetas.c_str());
  string buffer;
  vector<G_Nodo> vectorauxnodos;


  while(getline(nodosfile, buffer)){
    nodoscounter++;
  }
  g->reservaMemoria(nodoscounter);
  nodosfile.close();
  nodosfile.open(ficheroEtiquetas.c_str());

  // Recorre el fichero nodos y lo almacena en buffer
  // Inserta en el vector nodos todos los nodos del fichero
  while(getline(nodosfile, buffer)){
    vectorauxnodos.push_back(buffer.substr(0,buffer.size()-1)); // Quitamos el \n
  }
  g->setNodos(vectorauxnodos);

  
  vector<G_Lado> vectorlados; // Un vector de lados para cada elemento de la matriz
  G_Lado valorlado; // El valor de cada elemento del vector creado

  while(getline(ladosfile, buffer)){
    vectorlados.clear();
    while(buffer.find(' ') != string::npos){
      valorlado = atoi(buffer.substr(0, buffer.find(' ')).c_str()); // Transformamos el substring a int.
      buffer = buffer.substr(buffer.find(' ') + 1, buffer.size()); // Reasignamos el buffer al siguiente elemento.
      vectorlados.push_back(valorlado); // Introducimos el valor obtenido en el vector lados.
    }

    valorlado = atoi(buffer.substr(0, buffer.find('\n')).c_str());
    vectorlados.push_back(valorlado);

    
    g->setLados(vectorlados);
    
  }
  nodosfile.close();
  ladosfile.close(); 

  return true;
		
}


template <class G_Nodo, class G_Lado>
void algoritmoFloyd(const Grafo<G_Nodo, G_Lado> &g)
{
  // TODO
}

#endif
