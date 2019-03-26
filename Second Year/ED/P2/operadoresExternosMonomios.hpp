/*!
	@file operadoresExternosMonomios.hpp
	@brief Ficheros con los prototipos de los operadores externos de la clase Monomio
	@author Francisco Javier Molina Prieto
*/

#ifndef _OperadoresExternosgetMonomios()HPP_
#define _OperadoresExternosgetMonomios()HPP_

// Facilita la entrada y salida
#include <iostream>

#include "Monomio.hpp"

// Para la sobrecarga de los operadores de flujo: << y >>
using std::istream;
using std::ostream;

// Espacio de nombre de la asigantura: ed
namespace ed
{
//////////////////////////////////////////////////////////////////////////////////////
	// Operadores externos que no pertenecen a la clase Monomio

	//! \name Operadores de igualdad

	/*!
		@brief Función que compara dos monomios.
		@param1 Objeto tipo Monomio.
		@param2 Objeto tipo Monomio.
		@return Valor booleano. Si es igual devuelve TRUE.
	*/
		bool operator==(ed::Monomio const & m1, ed::Monomio const & m2);

	/*!
		@brief Función que compara un monomio con un número real.
		@param1 Objeto tipo Monomio.
		@param2 Número real.
		@return Valor booleano. Si es igual devuelve TRUE.
	*/
		bool operator==(ed::Monomio const & m, double const & x);
	/*!
		@brief Función que compara un monomio con un número real.
		@param1 Número real.
		@param2 Objeto tipo Monomio.
		@return Valor booleano. Si es igual devuelve TRUE.
	*/
		bool operator==(double const & x, ed::Monomio const & m);

	//! \name Operadores de desigualdad

	/*!
		@brief
		@param1 Objeto tipo Monomio.
		@param2 Objeto tipo Monomio.
		@return Valor booleano. Si es desigual devuelve TRUE.
	*/
		bool operator!=(ed::Monomio const & m1, ed::Monomio const & m2);
	/*!
		@brief Función que compara un monomio con un número real.
		@param1 Objeto tipo Monomio.
		@param2 Número real.
		@return Valor booleano. Si es desigual devuelve TRUE.
	*/
		bool operator!=(ed::Monomio const & m, double const & x);
	/*!
		@brief
		@param1 Número real.
		@param2 Objeto tipo Monomio.
		@return Valor booleano. Si es desigual devuelve TRUE.
	*/
		bool operator!=(double const & x, ed::Monomio const & m);

	//! \name Operadores unarios prefijos

	/*!
		@brief Función que devuelve una copia del Monomio “m”: +m
		@param Objeto tipo Monomio.
		@return Copia del Monomio “m”: +m
	*/
	ed::Monomio & operator+(ed::Monomio const & m);
	/*!
		@brief Función que devuelve el opuesto del Monomio “m”: -m
		@param Objeto tipo Monomio.
		@return Opuesto del Monomio “m”: -m
	*/
	ed::Monomio & operator-(ed::Monomio const & m);

	//! \name Operador binario de la suma

	/*!
		@brief Función que suma dos objetos tipo monomio.
		@param1 Objeto tipo Monomio.
		@param2 Objeto tipo Monomio.
		@return Objeto tipo Monomio resultado de la suma m1 + m2.
	*/
	 ed::Monomio & operator+ (ed::Monomio const &m1, ed::Monomio const &m2);

	//! \name Operador binario de la resta
	/*!
		@brief Función que resta dos objetos tipo monomio.
		@param1 Objeto tipo Monomio.
		@param2 Objeto tipo Monomio.
		@return Objeto tipo Monomio resultado de la resta m1 - m2.
	*/
	 ed::Monomio & operator- (ed::Monomio const &m1, ed::Monomio const &m2);

	//! \name Operadores binarios de la multiplicación
	/*!
		@brief Función que multiplica dos objetos tipo monomio.
		@param1 Objeto tipo Monomio.
		@param2 Objeto tipo Monomio.
		@return Objeto tipo Monomio resultado del producto m1 * m2.
	*/
	 ed::Monomio & operator*(ed::Monomio const &m1, ed::Monomio const &m2);
	 /*!
 		@brief Función que multiplica un objeto tipo monomio por un número real. (sufijo)
 		@param1 Objeto tipo Monomio.
 		@param2 Número real.
 		@return Objeto tipo Monomio resultado del producto m * x.
 	*/
	 ed::Monomio & operator*(ed::Monomio const &m, double const &x);
	 /*!
 		@brief Función que multiplica un objeto tipo monomio por un número real. (prefijo)
 		@param1 Número real.
 		@param2 Objeto tipo Monomio.
 		@return Objeto tipo Monomio resultado del producto x * m.
 	*/
	 ed::Monomio & operator*(double const &x, ed::Monomio const &m);

	///////////////////////////////////////////////////////////////////////////

	//! \name Operadores binarios de la división
	/*!
		@brief Función que divide dos objetos tipo monomio.
		@param1 Objeto tipo Monomio.
		@param2 Objeto tipo Monomio.
		@return Objeto tipo Monomio resultado de la división m1 / m2.
	*/
	 ed::Monomio & operator/(ed::Monomio const &m1, ed::Monomio const &m2);
	 /*!
 		@brief Función que multiplica un objeto tipo monomio por un número real. (sufijo)
 		@param1 Objeto tipo Monomio.
 		@param2 Número real.
 		@return Objeto tipo Monomio.
 	*/
	 ed::Monomio & operator/(ed::Monomio const &m, double const &x);
	 /*!
 		@brief Función que divide un objeto tipo monomio entre un número real. (prefijo)
 		@param1 Número real.
 		@param2 Objeto tipo Monomio.
 		@return Objeto tipo Monomio.
 	*/
	 ed::Monomio & operator/(double const &x, ed::Monomio const &m);

	/////////////////////////////////////////////////////////////////////////////

	//! \name Sobrecarga de los operadores de entrada y salida

	/*!
		@brief Función que lee desde el flujo de entrada los atributos de un monomio separados por espacios.
		@param1 Stream.
		@param2 Objeto tipo Monomio.
		@return Flujo de entrada.
	*/
	 istream &operator>>(istream &stream, ed::Monomio &m);

	 /*!
 		@brief Función que escribe en el flujo de salida los atributos del monomio separados por espacios.
 		@param1 Stream.
 		@param2 Objeto tipo Monomio.
 		@return Flujo de salida.
 	*/
	 ostream &operator<<(ostream &stream, ed::Monomio const &m);

}  // Fin de namespace ed.

#endif // _OperadoresExternosgetMonomios()HPP_
