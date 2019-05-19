#ifndef __GRAFO_HPP__
#define __GRAFO_HPP__

#include <cassert>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

namespace ed
{

	template <class G_Nodo, class G_Lado>
	class Grafo
	{
	private:

		G_Lado **_lados;
		G_Nodo *_nodos;
		int *_numeronodos;

	public:

		// constructores
		//Crea un nuevo grafo vacío
		Grafo () {
			_numeronodos = new int;
			*_numeronodos = 0;
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
			
			for (int i = 0; i < *_numeronodos; ++i){
				delete [] _lados[i];
			}
			delete [] _lados;
			delete _numeronodos;
			_numeronodos = NULL;
			_nodos = NULL;
			_lados = NULL;
		}
	
		void reservaMemoria(int nodenumber){
			_numeronodos = new int;
			*_numeronodos = nodenumber;
			_nodos = new G_Nodo[*_numeronodos];
			_lados = new G_Lado*[*_numeronodos]; // Crea una matriz de lados con N lados.
			for(int i=0; i < *_numeronodos; ++i){
				_lados[i] = new G_Lado[*_numeronodos];
			}
		}

		// Operador de asignación. Operador que copia el grafo “g” en el grafo actual
		Grafo& operator=(const Grafo& g){
			// Copiamos el número de nodos
			_numeronodos = new int;
			*_numeronodos = *g._numeronodos;

			// Reservamos memoria como en el constructor
			_nodos = new G_Nodo[*_numeronodos];
			_lados = new G_Lado*[*_numeronodos];
			for (int i = 0; i < *_numeronodos; ++i){
				_lados[i] = new G_Lado[*_numeronodos];
			}

			// Copiamos valores de nodos y lados
			for (int i = 0; i < *_numeronodos; ++i){
				_nodos[i] = g._nodos[i];
			}

			for (int i = 0; i < *_numeronodos; ++i){
				for (int j = 0; i < *_numeronodos; ++j){
					_lados[i][j] = g._lados[i][j];
				}
			}
			return *this;
		}


		// observers & modifiers

		
		inline int getNumeroNodos(){return *_numeronodos;}

		void setNodo(int index, G_Nodo node){
			_nodos[index] = node;
		}


		void setLado(int fila, int columna, G_Lado lado){
			_lados[fila][columna] = lado;
		}
		
		void setNumeroNodos(int numberNodos){
			*_numeronodos = numberNodos;
		}

		void printMatrix() {
		for (int i = 0; i < getNumeroNodos(); ++i) {
			cout << endl;
			for (int j = 0; j < getNumeroNodos(); ++j) {
				cout << _lados[i][j] << " ";
			}
		}
		cout << endl;
		}

		void printArray() {
		for (int i = 0; i < getNumeroNodos(); ++i) {
			cout << _nodos[i] << endl;
		}
}
	}; // Llaves de class
}

#endif
