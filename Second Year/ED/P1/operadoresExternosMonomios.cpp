/*!
  @file  operadoresExternosMonomios.cpp
	@brief Ficheros con el código de los operadores externos de la clase Monomio
	@author Francisco Javier Molina Prieto
*/


//  Ficheros de cabecera
#include <iostream>
#include <string>
#include <cstdlib>
using std::ostream;
using std::getline;
using std::string;
#include "operadoresExternosMonomios.hpp"


//  Se incluyen los operadores sobrecargados dentro del espacio de nombres ed
namespace ed
{
	// Operadores de igualdad

	bool operator==(ed::Monomio const & m1, ed::Monomio const & m2){
			bool equalGrado = m1.getGrado() == m2.getGrado();
			bool equalCoeficiente = (std::abs(m1.getCoeficiente() - m2.getCoeficiente()) < COTA_ERROR);
			if(equalGrado && equalCoeficiente)	return true;
			else return false;
	}

	bool operator==(ed::Monomio const & m, double const & x){
			if( (abs(m.getCoeficiente() - x) < COTA_ERROR) && m.getGrado() == 0) return true;
			return false;
	}

	bool operator==(double const & x, ed::Monomio const & m){
			if( (abs(m.getCoeficiente() - x) < COTA_ERROR) && m.getGrado() == 0) return true;
			return false;
	}

	// Operadores de desigualdad

	bool operator!=(ed::Monomio const & m1, ed::Monomio const & m2){
			if(m1 == m2) return false;
			return true;
	}

	bool operator!=(ed::Monomio const & m, double const & x){
			if(m == x) return false;
			return false;
	}

	bool operator!=(double const & x, ed::Monomio const & m)
	{
			if(m == x) return false;
			return false;
	}

	////////////////////////////////////////////////////////////

	// Operadores unarios prefijos

	ed::Monomio & operator+(ed::Monomio const & m){
			Monomio *nuevo = new Monomio(m.getCoeficiente(), m.getGrado());
			return *nuevo;
	}

			// COMPLETAR EL OTRO OPERADOR UNARIO PREFIJO: resta

	ed::Monomio & operator-(ed::Monomio const & m){
			Monomio *nuevo = new Monomio((-1 * m.getCoeficiente()), m.getGrado());
			return *nuevo;
	}

	////////////////////////////////////////////////////////////

	// Operadores aritméticos binarios

	// Suma
	ed::Monomio & operator+ (ed::Monomio const &m1, ed::Monomio const &m2){
			#ifndef NDEBUG
				assert(m1.getGrado() == m2.getGrado());
			#endif
			// Se crea un nuevo objeto
			ed::Monomio *nuevo = new ed::Monomio(m1.getCoeficiente() + m2.getCoeficiente(), m1.getGrado());
			// Se devuelve el resultado
			return *nuevo;
	}


	////////////
	// Resta
	ed::Monomio & operator- (ed::Monomio const &m1, ed::Monomio const &m2){
		#ifndef NDEBUG
			assert(m1.getGrado() == m2.getGrado());
		#endif
		// Se crea un nuevo objeto
		ed::Monomio *nuevo = new ed::Monomio(m1.getCoeficiente() - m2.getCoeficiente(), m1.getGrado());
		// Se devuelve el resultado
		return *nuevo;
	}

	// Multiplicación
	ed::Monomio & operator*(ed::Monomio const &m1, ed::Monomio const &m2){
			int new_grado = m1.getGrado() + m2.getGrado();
			double new_coeficiente = m1.getCoeficiente() * m2.getCoeficiente();
			//Se crea un nuevo objeto
			Monomio *nuevo = new Monomio(new_coeficiente, new_grado);
			// Se devuelve el resultado
			return *nuevo;
	}

	ed::Monomio & operator*(ed::Monomio const &m, double const &x){
			// Se crea un nuevo objeto
			Monomio *nuevo = new Monomio( m.getCoeficiente() * x, m.getGrado());
			// Se devuelve el resultado
			return *nuevo;
	}

	ed::Monomio & operator*(double const &x, ed::Monomio const &m){
			// Se crea un nuevo objeto
			Monomio *nuevo = new Monomio( m.getCoeficiente() * x, m.getGrado());
			// Se devuelve el resultado
			return *nuevo;
	}

	// División

	ed::Monomio & operator/(ed::Monomio const &m1, ed::Monomio const &m2){
			#ifndef NDEBUG
					assert(m1.getGrado() >= m2.getGrado());
					assert(abs(m2.getCoeficiente() - 0.0) > COTA_ERROR);
			#endif
			int new_grado = m1.getGrado() - m2.getGrado();
			double new_coeficiente = m1.getCoeficiente() / m2.getCoeficiente();
			// Se crea un nuevo objeto
			Monomio *nuevo = new Monomio(new_coeficiente, new_grado);
			// Se devuelve el resultado
			return *nuevo;
	}


	ed::Monomio & operator/(ed::Monomio const &m, double const &x){
			#ifndef NDEBUG
					assert(abs(x - 0.0) > 0);
			#endif
			//Se crea un nuevo objeto
			Monomio *nuevo = new Monomio(m.getCoeficiente() / x, m.getGrado());
			// Se devuelve el resultado
			return *nuevo;
	}

	ed::Monomio & operator/(double const &x, ed::Monomio const &m){
			#ifndef NDEBUG
						assert(m.getGrado() == 0);
						assert(abs(m.getCoeficiente() - 0.0) > COTA_ERROR);
			#endif
			// Se crea un nuevo objeto
			Monomio *nuevo = new Monomio(m.getCoeficiente() / x, m.getGrado());
			// Se devuelve el resultado
			return *nuevo;
	}

	/////////////////////////////////////////////////////////////////////////////

	//  Sobrecarga del operador de entrada
	istream &operator>>(istream &stream, ed::Monomio &m){
			string cadena_aux;
			getline(stream, cadena_aux, ' ');
			m.setCoeficiente(atof(cadena_aux.c_str()));
			getline(stream, cadena_aux); //El valor de separacion es \n
			m.setGrado(atoi(cadena_aux.c_str()));
	   	// Se devuelve el flujo de entrada
			return stream;
	}

	//  Sobrecarga del operador de salida
	ostream &operator<<(ostream &stream, ed::Monomio const &m){
			stream << m.getCoeficiente() << " " << m.getGrado();
			// Se devuelve el flujo de salida
			return stream;
	}


}  // namespace ed
