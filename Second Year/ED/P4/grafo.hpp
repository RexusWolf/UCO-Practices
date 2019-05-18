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

		int _numeronodos;

	public:

		// constructores
		//Crea un nuevo grafo vacío
		Grafo () {};

		// Crea un nuevo grafo inicializando las estructuras para almacenar n nodos
		Grafo (int n){
			reservaMemoria(n);			
		}

		// Crea un nuevo grafo a partir de otro grafo.
		Grafo(const Grafo &g){
			_nodos = g._nodos;
			_lados = g._lados;
		}

		// destructor (Elimina el grafo)
		~Grafo(){};

		// observers
		vector<G_Lado> getLados(){ return _lados;}
		vector<G_Nodo> getNodos(){ return _nodos;}

		// Borra el grafo liberando la memoria
		void borrarGrafo(){	// cabecera indicada para que compile
			delete _nodos;
			
			for (int i = 0; i < _numeronodos; ++i){
				delete [] _lados[i];
			}
			delete [] _lados;
			_nodos = NULL;
			_lados = NULL;
		}
	
		void reservaMemoria(int n){
			_numeronodos = n;
			_lados = new G_Lado*[n]; // Crea una matriz de lados con N lados.
			for(int i=0; i<n; ++i){
				_lados[i] = new G_Lado[n];
			}
			_nodos = new G_Nodo[n]; // Crea un vector de nodos con n nodos.
		}

		// Operador de asignación. Operador que copia el grafo “g” en el grafo actual
		Grafo& operator=(const Grafo &g){
			// Copiamos el número de nodos
			_numeronodos = g._numeronodos;

			// Reservamos memoria como en el constructor
			_nodos = new G_Nodo[_numeronodos];
			_lados = new G_Lado*[_numeronodos];
			for (int i = 0; i < _numeronodos; ++i){
				_lados = new G_Lado[_numeronodos];
			}

			// Copiamos valores de nodos y lados
			for (int i = 0; i < _numeronodos; ++i){
				_nodos[i] = g._nodos[i];
			}

			for (int i = 0; i < _numeronodos; ++i){
				for (int j = 0; i < _numeronodos; ++j){
					_lados[i][j] = g._lados[i][j];
				}
			}
			return *this;
		}
		
		void setNodos(vector<G_Nodo> vectornodos){
			for(int i = 0; i < _numeronodos; i++){
				getNodos()[i] = vectornodos[i];
			}
		}

		void setLados(vector<G_Lado> vectorlados){
			for(int i = 0; i < _numeronodos; i++){
				for(int j = 0; j < _numeronodos; j++){
				getLados()[i][j] = vectorlados[i][j];
				}
			}
		}

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

		while(getline(nodosfile, buffer)){
			nodoscounter++;
		}

		reservaMemoria(nodoscounter);
		nodosfile.close();
		nodosfile.open(ficheroEtiquetas.c_str());

		// Recorre el fichero nodos y lo almacena en buffer
		// Inserta en el vector nodos todos los nodos del fichero
		while(getline(nodosfile, buffer)){
			g->getNodos().pushback(buffer.substr(0,buffer.size()-1)); // Quitamos el \n
		}

		
		vector<G_Lado> vectorlados; // Un vector de lados para cada elemento de la matriz
		G_Lado valorlado; // El valor de cada elemento del vector creado
	
		while(getline(ladosfile, buffer)){
			vectorlados.clear(); // Removemos los elementos actuales del vector
			while(buffer.find(' ') != string::npos){ // npos = "until the end of the string"
				valorlado = atoi(buffer.substr(0, buffer.find(' ')).c_str()); // Transformamos el substring a int.
				buffer = buffer.substr(buffer.find(' ') + 1, buffer.size()); // Reasignamos el buffer al siguiente elemento.
				vectorlados.push_back(valorlado); // Introducimos el valor obtenido en el vector lados.
			}

			valorlado = atoi(buffer.substr(0, buffer.find('\n')).c_str());
			vectorlados.push_back(valorlado);

			
			g->getLados().push_back(vectorlados);
			
		}
	
		nodosfile.close();
		ladosfile.close();

		return true;
		
		}
				

			
	}; // Llaves de class
}

#endif
