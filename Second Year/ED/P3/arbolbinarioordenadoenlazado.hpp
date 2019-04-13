#ifndef __ARBOLBINARIOORDENADO_HPP__
#define __ARBOLBINARIOORDENADOENLAZADO_HPP__

#include <iostream>
#include <cassert>
#include "arbolbinarioordenado.hpp"
#include "operadornodo.hpp"

using namespace std;
/*!
\brief Espacio de nombres para la asignatura Estructura de datos.
*/
namespace ed
{
	/*!\brief Interfaz para definir un ArbolBinario ordenado.

	Define una interfaz para definir un ArbolBinarioOrdenado.

	\arg G define el campo de información a contener en el arbol.
	\pre G debe tener definidos los operadores < y ==.
	*/
	template<class G>
	class ArbolBinarioOrdenadoEnlazado:public ArbolBinarioOrdenado<G>
	{
	private:

		/*!\brief Define un nodo del arbol binario.*/
		class NodoArbolBinario
		{
		private:
			G _info;  //Valor informativo almacenado en el nodo
			NodoArbolBinario * _izquierdo;  //Puntero al hijo izquierdo
			NodoArbolBinario * _derecho;  //Puntero al hijo derecho

		public:
			NodoArbolBinario (const G &info)
			{
				_info = info;
				#ifndef NDEBUG
					assert(getIzquierdo() == NULL);
					assert(getDerecho() == NULL);
				#endif
			}

			NodoArbolBinario (const NodoArbolBinario &n)
			{
				*this = n;
				#ifndef NDEBUG
					assert(getInfo() == n.getInfo());
				#endif
			}

			/*!\brief Observadores.*/
			const G & getInfo() const
			{
				return _info;
			}

			NodoArbolBinario *getIzquierdo() const
			{
				return _izquierdo;
			}

			NodoArbolBinario *getDerecho() const
			{
				return _derecho;
			}

			bool esHoja() const
			{
				if((getIzquierdo() != NULL) || (getDerecho() != NULL)) return true;
				return false;
			}

			void recorridoPreOrden (OperadorNodo<G> &operador) const
			{
				operador.aplicar();
				if(getIzquierdo() != NULL) getIzquierdo()->recorridoPreOrden(&operador);
				if(getDerecho() != NULL) getDerecho()->recorridoPreOrden(&operador);				

			}

			void recorridoPostOrden (OperadorNodo<G> &operador) const
			{
				if(getIzquierdo() != NULL) getIzquierdo()->recorridoPostOrden(&operador);
				if(getDerecho() != NULL) getDerecho()->recorridoPostOrden(&operador);
				operador.aplicar();	
			}

			void recorridoInOrden (OperadorNodo<G> &operador) const
			{
				if(getIzquierdo() != NULL) getIzquierdo()->recorridoInOrden(&operador);
				operador.aplicar();
				if(getDerecho() != NULL) getDerecho()->recorridoInOrden(&operador);
			}

			/*!\brief Modificadores. */
			void setInfo(const G &info)
			{
				_info = info;
			}

			void setIzquierdo(NodoArbolBinario *n)
			{
				_izquierdo = n;
			}

			void setDerecho(NodoArbolBinario *n)
			{
				_derecho = n;
			}

			NodoArbolBinario & operator=(const NodoArbolBinario &n)
			{
				#ifndef NDEBUG
					assert(getIzquierdo() != n.getIzquierdo());
					assert(getDerecho() != n.getDerecho());
				#endif
				setIzquierdo(n.getIzquierdo());
				setDerecho(n.getDerecho());
				#ifndef NDEBUG
					assert(getIzquierdo() == n.getIzquierdo());
					assert(getDerecho() == n.getDerecho());
				#endif
			}

		}; //Fin clase NodoArbolBinario

		//Implementación de la raíz
		NodoArbolBinario * _raiz; /*!<La raiz del árbol*/
		NodoArbolBinario * _actual; /*!<Cursor al nodo actual*/
		NodoArbolBinario * _padre; /*!<Cursor al nodo actual*/

	public:

		ArbolBinarioOrdenadoEnlazado ()
		{
			_raiz = NULL;
			_actual = NULL;
			_padre = NULL;
			#ifndef NDEBUG
				assert(estaVacio());
			#endif
		}

		ArbolBinarioOrdenadoEnlazado (const ArbolBinarioOrdenadoEnlazado<G>& a)
		{
			*this = a;
		}

		~ArbolBinarioOrdenadoEnlazado ()
		{
			if (not estaVacio())
			borrarArbol();
			cout << "Destructor Usado \n";
		}

		ArbolBinarioOrdenadoEnlazado &operator=(const ArbolBinarioOrdenadoEnlazado& a)
		{
			// TODO
		}

		bool insertar(const G &x)
		{
			// TODO
			return false;
		}

		void borrarArbol()
		{
			// TODO
		}

		bool borrar()
		{
			#ifndef NDEBUG
				assert(_actual != NULL);
			#endif
			// TODO
			return false;
		}

		void recorridoPreOrden (OperadorNodo<G> &operador) const
		{
			operador.aplicar();
			if(getIzquierdo() != NULL) getIzquierdo()->recorridoPreOrden(&operador);
			if(getDerecho() != NULL) getDerecho()->recorridoPreOrden(&operador);
			// REVISAR
		}

		void recorridoPostOrden (OperadorNodo<G> &operador) const
		{
			if(getIzquierdo() != NULL) getIzquierdo()->recorridoPostOrden(&operador);			
			if(getDerecho() != NULL) getDerecho()->recorridoPostOrden(&operador);
			operador.aplicar();
			// REVISAR
		}

		void recorridoInOrden (OperadorNodo<G> &operador) const
		{
			if(getIzquierdo() != NULL) getIzquierdo()->recorridoInOrden(&operador);
			operador.aplicar();
			if(getDerecho() != NULL) getDerecho()->recorridoInOrden(&operador);
			// REVISAR
		}

		bool buscar(const G& x) const
		{
			// Recorreríamos y almacenariamos en un vector todos los nodos del árbol.
			recorridoInOrden(&AlmacenarNodo);
			// Comprobaríamos si existe el nodo x en algún nodo del árbol, recorriendo el vector.
		
			// Si lo encuentra, actualizamos el cursos de _actual y _padre.

			#ifndef NDEBUG
				assert(_actual == x);
			#endif

			return false;
		}

		bool estaVacio() const
		{
			if(_raiz == NULL) return true;
			return false;
		}

		G raiz() const
		{
			#ifndef NDEBUG
				assert(estaVacio() == false);
			#endif
			return getInfo(_raiz);
		}

		bool existeActual() const
		{
			#ifndef NDEBUG
				assert(estaVacio() == false);
			#endif
			if(_actual != NULL) return true;
			return false;
		}

		G actual() const
		{
			#ifndef NDEBUG
				assert(_actual != NULL);
			#endif
			return getInfo(_actual);
		}

		/*!@}*/
	};

} //namespace ed

#endif //__ARBOLORDENADO_HPP__
