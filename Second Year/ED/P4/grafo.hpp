#ifndef __GRAFO_HPP__
#define __GRAFO_HPP__

#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

namespace ed
{

	template <class G_Nodo, class G_Lado>
	class Grafo
	{
	private:

		G_Lado **_lados;
		G_Nodo *_nodos;
		int *_numeroNodos;

	public:

		// constructores
		//Crea un nuevo grafo vacío
		Grafo () {
			_numeroNodos = new int;
			*_numeroNodos = 0;
			_lados = new G_Lado*;
			_nodos = new G_Nodo;
		};

		// Crea un nuevo grafo inicializando las estructuras para almacenar n nodos
		Grafo (int n){
			reservaMemoria(n);			
		}

		// Crea un nuevo grafo a partir de otro grafo.
		Grafo(const Grafo &g){
			*this = g;
		}

		// destructor (Elimina el grafo)
		~Grafo(){
			borrarGrafo();
		};

// Borra el grafo liberando la memoria
		void borrarGrafo(){	// cabecera indicada para que compile
			delete [] _nodos;
			
			for (int i = 0; i < *_numeroNodos; ++i){
				delete [] _lados[i];
			}
			delete [] _lados;
			delete _numeroNodos;
			_numeroNodos = NULL;
			_nodos = NULL;
			_lados = NULL;
		}
	
		void reservaMemoria(int nodenumber) {
			_numeroNodos = new int;
			*_numeroNodos = nodenumber;
			_nodos = new G_Nodo[*_numeroNodos];
			_lados = new G_Lado*[*_numeroNodos]; // Crea una matriz de lados con N lados.
			for(int i=0; i < *_numeroNodos; ++i){
				_lados[i] = new G_Lado[*_numeroNodos];
			}
		}

		// Operador de asignación. Operador que copia el grafo “g” en el grafo actual
		Grafo& operator=(const Grafo& g){
			// Copiamos el número de nodos
			_numeroNodos = new int;
			*_numeroNodos = *g._numeroNodos;

			// Reservamos memoria como en el constructor
			_nodos = new G_Nodo[*_numeroNodos];
			_lados = new G_Lado*[*_numeroNodos];
			for (int i = 0; i < *_numeroNodos; ++i){
				_lados[i] = new G_Lado[*_numeroNodos];
			}

			// Copiamos valores de nodos y lados
			for (int i = 0; i < *_numeroNodos; ++i){
				_nodos[i] = g._nodos[i];
			}

			for (int i = 0; i < *_numeroNodos; ++i){
				for (int j = 0; i < *_numeroNodos; ++j){
					_lados[i][j] = g._lados[i][j];
				}
			}
			return *this;
		}


		// observers & modifiers

		inline G_Lado** getLados() const {return _lados;}
		
		inline int getNumeroNodos() const {return *_numeroNodos;}

		void setNodo(int index, G_Nodo node){
			_nodos[index] = node;
		}


		void setLado(int fila, int columna, G_Lado lado){
			_lados[fila][columna] = lado;
		}
		
		void setNumeroNodos(int numberNodos){
			*_numeroNodos = numberNodos;
		}

		// Función para imprimir matrices
		void printMatrix() const{
		for (int i = 0; i < getNumeroNodos(); ++i) {
			cout << endl;
			for (int j = 0; j < getNumeroNodos(); ++j) {
				cout << _lados[i][j] << " ";
			}
		}
		cout << endl;
		}

		// Función para copia de matrices
		void setMatrix(G_Lado **matrix) const{
		for (int i = 0; i < getNumeroNodos(); ++i) {
			for (int j = 0; j < getNumeroNodos(); ++j) {
				matrix[i][j] = _lados[i][j];
			}
		}
		}

		void printArray() const{
		for (int i = 0; i < getNumeroNodos(); ++i) {
			cout << _nodos[i] << endl;
		}
}
	}; // Llaves de class
}

#endif
