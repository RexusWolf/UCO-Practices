/*!
	@file Monomio.hpp
	@brief Definición de la clase Monomio
	@author Francisco Javier Molina Prieto
*/

#ifndef _MONOMIO_HPP_
#define _MONOMIO_HPP_

// Para usar la funciones pow y std::abs (valor absoluto)
#include <cmath>

// Para controlar las pre y post condiciones mediante asertos
#include <cassert>

#define COTA_ERROR 1.0e-6  //!< Cota de error para la comparación números reales

// Se incluye la clase Monomio dentro del espacio de nombre de la asignatura: ed
namespace ed
{
//!  Definición de la clase Monomio:  \f$ coeficiente \hspace{1ex} X^{grado} \f$
class Monomio
{
	//! \name Atributos privados de la clase Monomio
	private:
			double coeficiente_;
			int grado_;

	//! \name Funciones o métodos públicos de la clase Monomio
	public:

	//! \name Constructores de la clase Monomio
			inline Monomio(double coeficiente = 0.0, int grado = 0){
				// Precondiciones
				#ifndef NDEBUG
					assert(grado>=0);
				#endif

				this->setCoeficiente(coeficiente);
				this->setGrado(grado);

				// Postcondiciones
				#ifndef NDEBUG
					assert(std::abs(this->getCoeficiente() - coeficiente) < COTA_ERROR);
					assert(this->getGrado() == grado);
				#endif
			}

			inline Monomio(const Monomio &m){

				this->setCoeficiente(m.getCoeficiente());
				this->setGrado(m.getGrado());

				// Postcondiciones
				#ifndef NDEBUG
					assert(std::abs(this->getCoeficiente() - m.getCoeficiente()) < COTA_ERROR);
					assert(this->getGrado() == m.getGrado());
				#endif
			}

	//! \name Observadores: funciones de consulta de la clase Monomio
			inline double getCoeficiente() const {return coeficiente_;}
			inline int getGrado() const {return grado_;}

	//! \name Funciones de modificación de la clase Monomio
			inline void setCoeficiente(double x){
				coeficiente_ = x;
				// Postcondiciones
				#ifndef NDEBUG
					assert(this->getCoeficiente() == x);
				#endif
			}

			inline void setGrado(int n){
				// Postcondiciones
				#ifndef NDEBUG
						assert(n>=0);
				#endif
				grado_ = n;
				// Postcondiciones
				#ifndef NDEBUG
						assert(this->getGrado() == n);
				#endif
			}

	/////////////////////////////////////////////////

	//! \name Operadores de la clase Monomio

	// Operadores de asignación

	/*!
		@brief Operador para comparación de igualdad de dos monomios.
		@param Objeto tipo Monomio.
	*/
		Monomio & operator=(Monomio const &m);

	/*!
		@brief Operador para comparación de igualdad de un monomio con un nº real.
		@param Número real.
	*/
		Monomio & operator=(double const &x);

	// Operadores aritméticos y asignación

	/*!
		@brief Operador para suma de monomios.
		@param Objeto tipo Monomio.
	*/
		Monomio & operator+=(Monomio const &m);
	/*!
		@brief Operador para resta de monomios.
		@param Objeto tipo Monomio.
	*/
		Monomio & operator-=(ed::Monomio const &m);
	/*!
		@brief Operador para multiplicación de monomios.
		@param Objeto tipo Monomio.
	*/
		Monomio & operator*=(ed::Monomio const &m);
	/*!
		@brief Operador para división de monomios.
		@param Objeto tipo Monomio.
	*/
		Monomio & operator/=(ed::Monomio const &m);
	/*!
		@brief Operador para multiplicación de monomios por números reales.
		@param Objeto tipo Monomio.
	*/
		Monomio & operator*=(double const &x);
	/*!
		@brief Operador para división de monomios entre números reales.
		@param Objeto tipo Monomio.
	*/
		Monomio & operator/=(double const &x);


	/////////////////////////////////////////////////////////////////////////////////////

	//! \name Funciones lectura y escritura de la clase Monomio

/*!
	@brief Función para leer un monomio introducido por teclado.
	@param No hay parámetros.
	@return No devuelve nada.
*/
		  void leerMonomio();
/*!
	@brief Función para mostrar un monomio por pantalla.
	@param No hay parámetros.
	@return No devuelve nada.
*/
		  void escribirMonomio();

	///////////////////////////////////////////////////////////////////////

	//! \name Funciones auxiliares de la clase Monomio

/*!
	@brief Función que calcula el valor de un monomio haciendo sustitución
	de la incógnita por un valor real introducido por teclado.
	@param Número real.
	@return Número real (double).
*/
			double calcularValor(double const &x);


};  // Fin de la definición de la clase Monomio

}  //  Fin de namespace ed.

// _MONOMIO_HPP_
#endif
