/*!
 * @file operadoresExternosPolinomios.hpp
 * @author Francisco Javier Molina Prieto
 * @brief Fichero de implementación de los operadores externos de la clase polinomio
 * @version 0.5
 */

#ifndef _OperadoresPolinomios_HPP_
#define _OperadoresPolinomios_HPP_

// Facilita la entrada y salida
#include <iostream>

#include "Polinomio.hpp"

using std::istream;
using std::ostream;

// Espacio de nombre de la asignatura: ed
namespace ed
{

//! \name Operadores de igualdad

	/**
	 * @brief Operador lógico de igualdad entre dos polinomios
	 * @param p1: Polinomio situado a la izquierda del operador
	 * @param p2: Polinomio situado a la derecha del operador
	 * @return true si los monomios de cada polinomio coinciden
	 * @return false en caso contrario
	 */
	bool operator==(Polinomio const & p1, Polinomio const & p2);

	/**
	 * @brief Operador de igualdad entre un polinomio y un monomio
	 * @param polinomio: Polinomio situado a la izquierda del operador
	 * @param monomio: Monomio situado a la derecha del operador
	 * @return true si el polinomio tiene un único monomio cuyos valores coinciden con los del monomio que se pasa
	 * @return false si no ocurre el caso expuesto
	 */
	bool operator==(Polinomio const &p, Monomio const & m);

	/**
	 * @brief Operador de igualdad entre un polinomio y un monomio
	 * @param monomio: Monomio situado a la izquierda del operador
	 * @param polinomio: Polinomio situado a la derecha del operador
	 * @return true si el polinomio tiene un único monomio cuyos valores coinciden con los del monomio que se pasa
	 * @return false si no ocurre el caso expuesto
	 */
	bool operator==(Monomio const & m, Polinomio const &p);

	/**
	 * @brief Operador de igualdad entre un polinomio y un numero real
	 * @param polinomio: Polinomio situado a la izquierda del operador
	 * @param x: Número real situado a la derecha del operador
	 * @return true si el polinomio está formado por un único monomio cuyo grado es 0 y coeficiente = x
	 * @return false si no ocurre el caso expuesto
	 */
	bool operator==(Polinomio const &p, double x);

	/**
	 * @brief Operador de igualdad entre un polinomio y un numero rea
	 * @param x: Número real situado a la izquierda del operador
	 * @param polinomio: Polinomio situado a la derecha del operador
	 * @return true si el polinomio está formado por un único monomio cuyo grado es 0 y coeficiente = x
	 * @return false si no ocurre el caso expuesto
	 */
	bool operator==(double x, Polinomio const &p);

	////////////////////////////////////////////////////////////////////////////////////

	//! \name Operadores de desigualdad

	/**
	 * @brief Operador de desigualdad entre dos polinomios
	 * @param p1: Polinomio situado a la izquierda del operador 
	 * @param p2: Polinomio situado a la derecha del operador
	 * @return true si alguno de los monomios de un polinomio no coincide con el de otro del segundo polinomio
	 * @return false si no ocurre el caso expuesto
	 */
	bool operator!=(Polinomio const & p1, Polinomio const & p2);

	/**
	 * @brief Operador de desigualdad entre un monomio y un polinomio
	 * @param polinomio: Polinomio situado a la izquierda del operador
	 * @param monomio: Monomio situado a la derecha del operador
	 * @return true si el polinomio tiene más de un monomio o el que tiene, cuenta con valores distintos a los del monomio pasado
	 * @return false si no ocurre el caso expuesto
	 */
	bool operator!=(Polinomio const & p, Monomio const & m);

	/**
	 * @brief Operador de desigualdad entre un monomio y un polinomio
	 * @param monomio: Monomio situado a la izquierda del operador
	 * @param polinomio: Polinomio situado a la derecha del operador
	 * @return true si el polinomio tiene más de un monomio o el que tiene, cuenta con valores distintos a los del monomio pasado
	 * @return false si no ocurre el caso expuesto
	 */
	bool operator!=(Monomio const & m, Polinomio const & p);

	/**
	 * @brief Operador de desigualdad entre un número real y un monomio
	 * @param polinomio: Polinomio situado a la izquierda del operador
	 * @param x: Número real situado a la derecha del operador
	 * @return true si el polinomio tiene más de un monomio o el que tiene, cuenta con grado mayor que 0 o su coeficiente es distinto a x
	 * @return false si no ocurre el caso expuesto
	 */
	bool operator!=(Polinomio const & p, double x);
	
	/**
	 * @brief Operador de desigualdad entre un número real y un monomio
	 * @param x: Número real situado a la izquierda del operador
	 * @param polinomio: Polinomio situado a la derecha del operador
	 * @return true si el polinomio tiene más de un monomio o el que tiene, cuenta con grado mayor que 0 o su coeficiente es distinto a x
	 * @return false si no ocurre el caso expuesto
	 */
	bool operator!=(double x, Polinomio const & p);

//////////////////////////////////////////////////////////////////////////////////////

	//! \name Operadores unarios

	/**
	 * @brief Operador unario + para un polinomio
	 * @param polinomio: Polinomio a la derecha del operador
	 * @return Polinomio&: una copia del polinomio pasado
	 */
	Polinomio & operator+(Polinomio const & p);

	/**
	 * @brief Operador unario - para un polinomio
	 * @param polinomio: Polinomio a la derecha del operador
	 * @return Polinomio&: Copia del polinomio pasado con el coeficiente opuesto de todos sus monomios
	 */
	Polinomio & operator-(Polinomio const & p);

//////////////////////////////////////////////////////////////////////////////////////

	//! \name Operadores binarios de la suma

	/**
	 * @brief Operador binario de la suma entre dos polinomios
	 * @param p1: Polinomio situado a la izquierda del operador
	 * @param p2: Polinomio situado a la derecha del operador
	 * @return Polinomio&: Polinomio resultante
	 */
	Polinomio & operator+(Polinomio const &p1,  Polinomio const &p2);

	/**
	 * @brief Operador binario de la suma entre un monomio y un polinomio
	 * @param polinomio: Polinomio situado a la izquierda del operador
	 * @param monomio: Monomio situado a la derecha del operador
	 * @return Polinomio&: Polinomio resultante
	 */
	Polinomio & operator+(Polinomio const &p, Monomio const & m);

	/**
	 * @brief Operador binario de la suma entre un monomio y un polinomio
	 * @param monomio: Monomio situado a la izquierda del operador
	 * @param polinomio: Polinomio situado a la derecha del operador
	 * @return Polinomio&: Polinomio resultante
	 */
	Polinomio & operator+(Monomio const & m, Polinomio const &p);

	/**
	 * @brief Operador binario de la suma entre un polinomio y un número real
	 * @param polinomio: Polinomio: Polinomio situado a la izquierda del operador
	 * @param x: Número real situado a la derecha del operador
	 * @return Polinomio&: Polinomio resultante
	 */
	Polinomio & operator+(Polinomio const &p, double x);

	/**
	 * @brief Operador binario de la suma entre un polinomio y un número real
	 * @param x: Número real situado a la izquierda del operador
	 * @param polinomio: Polinomio: Polinomio situado a la derecha del operador
	 * @return Polinomio&: Polinomio resultante
	 */
	Polinomio & operator+(double x, Polinomio const &p);

	//! \name Operadores binarios de la resta

	/**
	 * @brief Operador binario de la resta entre dos polinomio
	 * @param p1: Polinomio situado a la izquierda del operador
	 * @param p2: Polinomio situado a la derecha del operador
	 * @return Polinomio&: Polinomio resultante
	 */
	Polinomio & operator-(Polinomio const &p1,  Polinomio const &p2);

	/**
	 * @brief Operador binario de la resta entre un monomio y un polinomio
	 * @param polinomio: Polinomio situado a la izquierda del operador
	 * @param monomio: Monomio situado a la derecha del operador
	 * @return Polinomio&: Polinomio resultante
	 */
	Polinomio & operator-(Polinomio const &p, Monomio const & m);

	/**
	 * @brief Operador binario de la resta entre un monomio y un polinomio
	 * @pqram monomio: Monomio situado a la izquierda del operador
	 * @param polinomio: Polinomio situado a la derecha del operador
	 * @return Polinomio&: Polinomio resultante
	 */
	Polinomio & operator-(Monomio const & m, Polinomio const &p);

	/**
	 * @brief Operador binario de la resta entre un polinomio y un número real
	 * @param polinomio: Polinomio: Polinomio situado a la izquierda del operador
	 * @param x: Número real situado a la derecha del operador
	 * @return Polinomio&: Polinomio resultante
	 */
	Polinomio & operator-(Polinomio const &p, double x);

	/**
	 * @brief Operador binario de la resta entre un polinomio y un número real
	 * @param x: Número real situado a la izquierda del operador
	 * @param polinomio: Polinomio: Polinomio situado a la derecha del operador
	 * @return Polinomio&: Polinomio resultante
	 */
	Polinomio & operator-(double x, Polinomio const &p);

	///////////////////////////////////////////////////////////////////////////

	//! \name Operadores binarios de la multiplicación

	/**
	 * @brief Operador binario de la multiplicación entre dos polinomios
	 * @param p1: Polinomio situado a la izquierda del operador
	 * @param p2: Polinomio situado a la derecha del operador
	 * @return Polinomio&: Polinomio resultante
	 */
	Polinomio & operator*(Polinomio const &p1,  Polinomio const &p2);

	/**
	 * @brief Operador binario de la multiplicación entre un monomio y un polinomio
	 * @param polinomio: Polinomio situado a la izquierda del operador
	 * @param monomio: Monomio situado a la derecha del operador
	 * @return Polinomio&: Polinomio resultante
	 */
	Polinomio & operator*(Polinomio const &p, Monomio const & m);

	/**
	 * @brief Operador binario de la multiplicación entre un monomio y un polinomio
	 * @param monomio: Monomio situado a la izquierda del operador
	 * @param polinomio: Polinomio situado a la derecha del operador
	 * @return Polinomio&: Polinomio resultante
	 */
	Polinomio & operator*(Monomio const & m, Polinomio const &p);

	/**
	 * @brief Operador binario de la multiplicación entre un polinomio y un número real
	 * @param polinomio: Polinomio: Polinomio situado a la izquierda del operador
	 * @param x: Número real situado a la derecha del operador
	 * @return Polinomio&: Polinomio resultante
	 */
	Polinomio & operator*(Polinomio const &p, double x);

	/**
	 * @brief Operador binario de la multiplicación entre un polinomio y un número real
	 * @param x: Número real situado a la izquierda del operador
	 * @param polinomio: Polinomio: Polinomio situado a la derecha del operador
	 * @return Polinomio&: Polinomio resultante
	 */
	Polinomio & operator*(double x, Polinomio const &p);

	///////////////////////////////////////////////////////////////////////////

	//! \name Operadores binarios de la división

	/**
	 * @brief Operador binario de la división entre dos polinomios
	 * @param p1: Polinomio situado a la izquierda del operador
	 * @param p2: Polinomio situado a la derecha del operador
	 * @return Polinomio&: Polinomio resultante
	 */
	Polinomio & operator/(Polinomio const &p1,  Polinomio const &p2);

	/**
	 * @brief Operador binario de la división entre un monomio y un polinomio
	 * @param polinomio: Polinomio situado a la izquierda del operador
	 * @param monomio: Monomio situado a la derecha del operador
	 * @return Polinomio&: Polinomio resultante
	 */
	Polinomio & operator/(Polinomio const &p, Monomio const & m);

	/**
	 * @brief Operador binario de la división entre un monomio y un polinomio
	 * @param monomio: Monomio situado a la izquierda del operador
	 * @param polinomio: Polinomio situado a la derecha del operador
	 * @return Polinomio&: Polinomio resultante
	 */
	Polinomio & operator/(Monomio const & m, Polinomio const &p);

	/**
	 * @brief Operador binario de la división entre un polinomio y un número real
	 * @param polinomio: Polinomio: Polinomio situado a la izquierda del operador
	 * @param x: Número real situado a la derecha del operador
	 * @return Polinomio&: Polinomio resultante
	 */
	Polinomio & operator/(Polinomio const &p, double x);

	/**
	 * @brief Operador binario de la división entre un polinomio y un número real
	 * @param x: Número real situado a la izquierda del operador
	 * @param polinomio: Polinomio: Polinomio situado a la derecha del operador
	 * @return Polinomio&: Polinomio resultante
	 */
	Polinomio & operator/(double x, Polinomio const &p);

	/////////////////////////////////////////////////////////////////////////////

    //! \name Sobrecarga de los operadores de flujo de la clase Polinomio.

    /**
     * @brief Sobrecarga del operador de flujo de entrada
     * @param stream: Flujo de entrada
     * @param polinomio: Polinomio que se escribe por el flujo de entrada
     */
    ostream &operator<<(ostream &stream, Polinomio const &);

    /**
     * @brief Sobrecarga del operador de flujo de salida
     * @param stream: Flujo de salida
     * @param polinomio: Polinomio que lee el flujo de salida
     */
	istream &operator>>(istream &stream, Polinomio &p);

}  // Fin de namespace ed.

#endif // _OperadoresPolinomios_HPP_
