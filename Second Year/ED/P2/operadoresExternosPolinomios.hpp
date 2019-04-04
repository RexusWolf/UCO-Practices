/*!
	\file operadoresExternosPolinomios.hpp
	\brief Ficheros con operadores de monomios y polinomios
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
	 * @note Operador sobrecargado
	 * @param p1: Polinomio situado a la izquierda del operador
	 * @param p2: Polinomio situado a la derecha del operador
	 * @return true si los monomios de cada polinomio coinciden uno a uno en grado y coeficiente
	 * @return false si ocurre el caso contrario
	 */
	bool operator==(Polinomio const & p1, Polinomio const & p2);

	/**
	 * @brief Operador de igualdad entre un polinomio y un monomio
	 * @note Operador sobrecargado
	 * @param polinomio: Polinomio situado a la izquierda del operador
	 * @param monomio: Monomio situado a la derecha del operador
	 * @return true si el polinomio tiene un único monomio cuyos valores coinciden con los del monomio pasado
	 * @return false si no ocurre el caso expuesto
	 */
	bool operator==(Polinomio const &p, Monomio const & m);

	/**
	 * @brief Operador de igualdad entre un polinomio y un monomio
	 * @note Operador sobrecargado
	 * @param monomio: Monomio situado a la izquierda del operador
	 * @param polinomio: Polinomio situado a la derecha del operador
	 * @return true si el polinomio tiene un único monomio cuyos valores coinciden con los del monomio pasado
	 * @return false si no ocurre el caso expuesto
	 */
	bool operator==(Monomio const & m, Polinomio const &p);

	/**
	 * @brief Operador de igualdad entre un polinomio y un numero real
	 * @note Operador sobrecargado
	 * @param polinomio: Polinomio situado a la izquierda del operador
	 * @param x: Número real situado a la derecha del operador
	 * @return true si el polinomio está formado por un único monomio cuyo grado es 0 y coeficiente = x
	 * @return false si no ocurre el caso expuesto
	 */
	bool operator==(Polinomio const &p, double x);

	/**
	 * @brief Operador de igualdad entre un polinomio y un numero real
	 * @note Operador sobrecargado
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
	 * @note Operador sobrecargado
	 * @param p1: Polinomio situado a la izquierda del operador 
	 * @param p2: Polinomio situado a la derecha del operador
	 * @return true si alguno de los monomios de un polinomio no coincide con el de otro del segundo polinomio
	 * @return false si no ocurre el caso expuesto
	 */
	bool operator!=(Polinomio const & p1, Polinomio const & p2);

	/**
	 * @brief Operador de desigualdad entre un monomio y un polinomio
	 * @note Operador sobrecargado
	 * @param polinomio: Polinomio situado a la izquierda del operador
	 * @param monomio: Monomio situado a la derecha del operador
	 * @return true si el polinomio tiene más de un monomio o el que tiene, cuenta con valores distintos a los del monomio pasado
	 * @return false si no ocurre el caso expuesto
	 */
	bool operator!=(Polinomio const & p, Monomio const & m);

	/**
	 * @brief Operador de desigualdad entre un monomio y un polinomio
	 * @note Operador sobrecargado
	 * @param monomio: Monomio situado a la izquierda del operador
	 * @param polinomio: Polinomio situado a la derecha del operador
	 * @return true si el polinomio tiene más de un monomio o el que tiene, cuenta con valores distintos a los del monomio pasado
	 * @return false si no ocurre el caso expuesto
	 */
	bool operator!=(Monomio const & m, Polinomio const & p);

	/**
	 * @brief Operador de desigualdad entre un número real y un monomio
	 * @note Operador sobrecargado
	 * @param polinomio: Polinomio situado a la izquierda del operador
	 * @param x: Número real situado a la derecha del operador
	 * @return true si el polinomio tiene más de un monomio o el que tiene, cuenta con grado mayor que 0 o su coeficiente es distinto a x
	 * @return false si no ocurre el caso expuesto
	 */
	bool operator!=(Polinomio const & p, double x);
	
	/**
	 * @brief Operador de desigualdad entre un número real y un monomio
	 * @note Operador sobrecargado
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
	 * @note Operador sobrecargado
	 * @param p1: Polinomio situado a la izquierda del operador
	 * @param p2: Polinomio situado a la derecha del operador
	 * @return Polinomio&: Polinomio resultante de la suma de los polinomios
	 */
	Polinomio & operator+(Polinomio const &p1,  Polinomio const &p2);

	/**
	 * @brief Operador binario de la suma entre un monomio y un polinomio
	 * @note Operador sobrecargado
	 * @param polinomio: Polinomio situado a la izquierda del operador
	 * @param monomio: Monomio situado a la derecha del operador
	 * @return Polinomio&: Polinomio resultante de sumar el monomio con el polinomio
	 */
	Polinomio & operator+(Polinomio const &p, Monomio const & m);

	/**
	 * @brief Operador binario de la suma entre un monomio y un polinomio
	 * @note Operador sobrecargado
	 * @param monomio: Monomio situado a la izquierda del operador
	 * @param polinomio: Polinomio situado a la derecha del operador
	 * @return Polinomio&: Polinomio resultante de sumar el monomio con el polinomio
	 */
	Polinomio & operator+(Monomio const & m, Polinomio const &p);

	/**
	 * @brief Operador binario de la suma entre un polinomio y un número real
	 * @note Operador sobrecargado
	 * @param polinomio: Polinomio: Polinomio situado a la izquierda del operador
	 * @param x: Número real situado a la derecha del operador
	 * @return Polinomio&: Polinomio resultante de sumar al polinomio un monomio con coeficiente = x y grado = 0
	 */
	Polinomio & operator+(Polinomio const &p, double x);

	/**
	 * @brief Operador binario de la suma entre un polinomio y un número real
	 * @note Operador sobrecargado
	 * @param x: Número real situado a la izquierda del operador
	 * @param polinomio: Polinomio: Polinomio situado a la derecha del operador
	 * @return Polinomio&: Polinomio resultante de sumar al polinomio un monomio con coeficiente = x y grado = 0
	 */
	Polinomio & operator+(double x, Polinomio const &p);

	//! \name Operadores binarios de la resta

	/**
	 * @brief Operador binario de la resta entre dos polinomios
	 * @note Operador sobrecargado
	 * @param p1: Polinomio situado a la izquierda del operador
	 * @param p2: Polinomio situado a la derecha del operador
	 * @return Polinomio&: Polinomio resultante de la resta de los polinomios
	 */
	Polinomio & operator-(Polinomio const &p1,  Polinomio const &p2);

	/**
	 * @brief Operador binario de la resta entre un monomio y un polinomio
	 * @note Operador sobrecargado
	 * @param polinomio: Polinomio situado a la izquierda del operador
	 * @param monomio: Monomio situado a la derecha del operador
	 * @return Polinomio&: Polinomio resultante de restar al polinomio el monomio
	 */
	Polinomio & operator-(Polinomio const &p, Monomio const & m);

	/**
	 * @brief Operador binario de la resta entre un monomio y un polinomio
	 * @note Operador sobrecargado
	 * @param monomio: Monomio situado a la izquierda del operador
	 * @param polinomio: Polinomio situado a la derecha del operador
	 * @return Polinomio&: Polinomio resultante de restarle al monomio el polinomio
	 */
	Polinomio & operator-(Monomio const & m, Polinomio const &p);

	/**
	 * @brief Operador binario de la resta entre un polinomio y un número real
	 * @note Operador sobrecargado
	 * @param polinomio: Polinomio: Polinomio situado a la izquierda del operador
	 * @param x: Número real situado a la derecha del operador
	 * @return Polinomio&: Polinomio resultante de restarle al polinomio un monomio con coeficiente = x y grado = 0
	 */
	Polinomio & operator-(Polinomio const &p, double x);

	/**
	 * @brief Operador binario de la resta entre un polinomio y un número real
	 * @note Operador sobrecargado
	 * @param x: Número real situado a la izquierda del operador
	 * @param polinomio: Polinomio: Polinomio situado a la derecha del operador
	 * @return Polinomio&: Polinomio resultante de restar al monomio con coeficiente = x y grado = 0 el polinomio
	 */
	Polinomio & operator-(double x, Polinomio const &p);

	///////////////////////////////////////////////////////////////////////////

	//! \name Operadores binarios de la multiplicación

	/**
	 * @brief Operador binario de la multiplicación entre dos polinomios
	 * @note Operador sobrecargado
	 * @param p1: Polinomio situado a la izquierda del operador
	 * @param p2: Polinomio situado a la derecha del operador
	 * @return Polinomio&: Polinomio resultante de la multiplicación de los polinomios
	 */
	Polinomio & operator*(Polinomio const &p1,  Polinomio const &p2);

	/**
	 * @brief Operador binario de la multiplicación entre un monomio y un polinomio
	 * @note Operador sobrecargado
	 * @param polinomio: Polinomio situado a la izquierda del operador
	 * @param monomio: Monomio situado a la derecha del operador
	 * @return Polinomio&: Polinomio resultante de multiplicar el monomio con el polinomio
	 */
	Polinomio & operator*(Polinomio const &p, Monomio const & m);

	/**
	 * @brief Operador binario de la multiplicación entre un monomio y un polinomio
	 * @note Operador sobrecargado
	 * @param monomio: Monomio situado a la izquierda del operador
	 * @param polinomio: Polinomio situado a la derecha del operador
	 * @return Polinomio&: Polinomio resultante de multiplicar el monomio con el polinomio
	 */
	Polinomio & operator*(Monomio const & m, Polinomio const &p);

	/**
	 * @brief Operador binario de la multiplicación entre un polinomio y un número real
	 * @note Operador sobrecargado
	 * @param polinomio: Polinomio: Polinomio situado a la izquierda del operador
	 * @param x: Número real situado a la derecha del operador
	 * @return Polinomio&: Polinomio resultante de multiplicar el polinomio con un monomio con coeficiente = x y grado = 0
	 */
	Polinomio & operator*(Polinomio const &p, double x);

	/**
	 * @brief Operador binario de la multiplicación entre un polinomio y un número real
	 * @note Operador sobrecargado
	 * @param x: Número real situado a la izquierda del operador
	 * @param polinomio: Polinomio: Polinomio situado a la derecha del operador
	 * @return Polinomio&: Polinomio resultante de multiplicar el polinomio con un monomio con coeficiente = x y grado = 0
	 */
	Polinomio & operator*(double x, Polinomio const &p);

	///////////////////////////////////////////////////////////////////////////

	//! \name Operadores binarios de la división

	/**
	 * @brief Operador binario de la división entre dos polinomios
	 * @note Operador sobrecargado
	 * @param p1: Polinomio situado a la izquierda del operador
	 * @param p2: Polinomio situado a la derecha del operador
	 * @return Polinomio&: Polinomio resultante de la división entre los polinomios
	 */
	Polinomio & operator/(Polinomio const &p1,  Polinomio const &p2);

	/**
	 * @brief Operador binario de la división entre un monomio y un polinomio
	 * @note Operador sobrecargado
	 * @param polinomio: Polinomio situado a la izquierda del operador
	 * @param monomio: Monomio situado a la derecha del operador
	 * @return Polinomio&: Polinomio resultante de dividir el polinomio entre el monomio
	 */
	Polinomio & operator/(Polinomio const &p, Monomio const & m);

	/**
	 * @brief Operador binario de la división entre un monomio y un polinomio
	 * @note Operador sobrecargado
	 * @param monomio: Monomio situado a la izquierda del operador
	 * @param polinomio: Polinomio situado a la derecha del operador
	 * @return Polinomio&: Polinomio resultante de dividir el monomio entre el polinomio
	 */
	Polinomio & operator/(Monomio const & m, Polinomio const &p);

	/**
	 * @brief Operador binario de la división entre un polinomio y un número real
	 * @note Operador sobrecargado
	 * @param polinomio: Polinomio: Polinomio situado a la izquierda del operador
	 * @param x: Número real situado a la derecha del operador
	 * @return Polinomio&: Polinomio resultante de dividir el polinomio entre un monomio con coeficiente = x y grado = 0
	 */
	Polinomio & operator/(Polinomio const &p, double x);

	/**
	 * @brief Operador binario de la división entre un polinomio y un número real
	 * @note Operador sobrecargado
	 * @param x: Número real situado a la izquierda del operador
	 * @param polinomio: Polinomio: Polinomio situado a la derecha del operador
	 * @return Polinomio&: Polinomio resultante de dividir el monomio con coeficiente = x y grado = 0 entre el polinomio
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
