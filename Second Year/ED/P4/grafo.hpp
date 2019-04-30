#ifndef __GRAFO_HPP__
#define __GRAFO_HPP__

#include <cassert>
#include <iostream>

using namespace std;

namespace ed
{

	template <class G_Nodo, class G_Lado>
	class Grafo
	{
	private:

		G_Lado **_lados;

		G_Nodo *_nodos;

	public:

		// constructores
		//Crea un nuevo grafo vacío
		Grafo (){
			_nodos = {};
			_lados = {};
		}
		// Crea un nuevo grafo inicializando las estructuras para almacenar n nodos
		Grafo (int n){
			_lados = new G_Lado*[n];
			for(int i=0; i<n; i++){
				_lados[i] = new G_Lado;
			}
			_nodos = nodos[n];
		}
		// Crea un nuevo grafo a partir de otro grafo.
		Grafo (Grafo &g){
			_nodos = g._nodos;
			_lados = g._lados;
		}

		// destructor (Elimina el grafo)
		~Grafo(){
			_nodos = {};
			_lados = {};
		}

		// observers
		G_Lado getLados(){ return _lados;}
		G_Nodo getNodos(){ return _nodos;}
		
		// modififers
		void setLados(G_Lado lados){ _lados = lados;}
		void setNodos(G_Nodo nodos){ _nodos = nodos;}
		// Borra el grafo liberando la memoria
		void borrarGrafo() {	// cabecera indicada para que compile
			delete(this);
		}
		// Operador de asignación. Operador que copia el grafo “g” en el grafo actual
		Grafo operador=(Grafo &g){
			_lados = g._lados;
			_nodos = g._nodos;
			return this;
		}

		void insertNodo(G_Nodo &n){
			
		}
		// Carga un grafo desde fichero
		bool cargarGrafo(char matrizfile, char nodofile){
			std::ofstream f;
			f.open(matrizfile, std:ios::out); // Abrimos los ficheros en modo escritura.
			f.open(nodofile, std:ios::out);
			std::istream_iterator<G_Nodo> itnodo;
			for(itnodo = nodofile.begin(); itnodo = nodofile.end(); itnodo++){
				;
			}
		}

	
	};
}

#endif
