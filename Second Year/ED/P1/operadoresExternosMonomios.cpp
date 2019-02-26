/*!
   \file  operadoresExternosMonomios.cpp
	\brief Ficheros con el código de los operadores externos de la clase Monomio
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

	// COMPLETAR

	bool operator==(ed::Monomio const & m1, ed::Monomio const & m2)
	{
		// COMPLETAR Y MODIFICAR
		bool equalGrado = m1.getGrado() == m2.getGrado();
		bool equalCoeficiente = (std::abs(m1.getCoeficiente() - m2.getCoeficiente()) < COTA_ERROR);
		if(equalGrado && equalCoeficiente)	return true;
		else return false;
	}

	// COMPLETAR LOS OTROS OPERADORES DE IGUALDAD

	bool operator==(ed::Monomio const & m, double const & x)
	{
		// COMPLETAR Y MODIFICAR
		if( (abs(m.getCoeficiente() - x) < COTA_ERROR) && m.getGrado() == 0) return true;

		// MODIFICAR: SE DEVUELVE UN VALOR ARBITRARIO PARA NO GENERAR AVISOS AL COMPILAR
		return false;
	}

	bool operator==(double const & x, ed::Monomio const & m)
	{
		// COMPLETAR Y MODIFICAR
		if( (abs(m.getCoeficiente() - x) < COTA_ERROR) && m.getGrado() == 0) return true;

		// MODIFICAR: SE DEVUELVE UN VALOR ARBITRARIO PARA NO GENERAR AVISOS AL COMPILAR
		return false;
	}

	// Operadores de desigualdad

	// COMPLETAR
	bool operator!=(ed::Monomio const & m1, ed::Monomio const & m2)
	{
		// COMPLETAR Y MODIFICAR
		if(m1 == m2) return false;
		// MODIFICAR: SE DEVUELVE UN VALOR ARBITRARIO PARA NO GENERAR AVISOS AL COMPILAR
		return true;
	}

	bool operator!=(ed::Monomio const & m, double const & x)
	{
		// COMPLETAR Y MODIFICAR
		if(m == x) return false;

		// MODIFICAR: SE DEVUELVE UN VALOR ARBITRARIO PARA NO GENERAR AVISOS AL COMPILAR
		return false;
	}

	bool operator!=(double const & x, ed::Monomio const & m)
	{
		// COMPLETAR Y MODIFICAR
		if(m == x) return false;

		// MODIFICAR: SE DEVUELVE UN VALOR ARBITRARIO PARA NO GENERAR AVISOS AL COMPILAR
		return false;
	}

	// COMPLETAR LOS OTROS OPERADORES DE DESIGUALDAD


	////////////////////////////////////////////////////////////

	// Operadores unarios prefijos

	// COMPLETAR

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
	ed::Monomio & operator+ (ed::Monomio const &m1, ed::Monomio const &m2)
	{
		// COMPLETAR Y MODIFICAR
		// Se crea un nuevo objeto

		#ifndef NDEBUG
				assert(m1.getGrado() == m2.getGrado());
		#endif
				double auxcoef = m1.getCoeficiente();
				int auxgrado = m1.getGrado();

				ed::Monomio *nuevo = new ed::Monomio(m1);
				*nuevo += m2;

		#ifndef NDEBUG
				assert(std::abs(m1.getCoeficiente() - (auxcoef + m2.getCoeficiente())) < COTA_ERROR);
				assert(m1.getGrado() == m2.getGrado());
				assert(nuevo->getGrado() == auxgrado);
		#endif


		// Se devuelve el resultado
		return *nuevo;
	}


	////////////
	// Resta
	ed::Monomio & operator- (ed::Monomio const &m1, ed::Monomio const &m2)
	{
		// COMPLETAR Y MODIFICAR
		// Se crea un nuevo objeto

		#ifndef NDEBUG
				assert(m1.getGrado() == m2.getGrado());
		#endif
				double auxcoef = m1.getCoeficiente();
				int auxgrado = m1.getGrado();
				ed::Monomio *nuevo = new ed::Monomio(m1);
				*nuevo -= m2;

		#ifndef NDEBUG
				assert(std::abs(m1.getCoeficiente() - (auxcoef - m2.getCoeficiente())) < COTA_ERROR);
				assert(m1.getGrado() == m2.getGrado());
				assert(m1.getGrado() == auxgrado);
		#endif

		// Se devuelve el resultado
		return *nuevo;
	}
	// COMPLETAR


	//////////////////
	// Multiplicación
	ed::Monomio & operator*(ed::Monomio const &m1, ed::Monomio const &m2){

		// Se crea un nuevo objeto

		double auxcoef = m1.getCoeficiente();
		int auxgrado = m1.getGrado();
		ed::Monomio *nuevo = new Monomio(m1);
		*nuevo *= m2;
		#ifndef NDEBUG
			assert(std::abs(m1.getCoeficiente() - (auxcoef * m2.getCoeficiente())) < COTA_ERROR);
			assert(std::abs(m1.getGrado() - (auxgrado + m2.getGrado())) == 0);
		#endif


			// Se devuelve el resultado
			return *nuevo;
		}

		ed::Monomio & operator*(ed::Monomio const &m, double const &x){

			// Se crea un nuevo objeto
			ed::Monomio *nuevo = new Monomio(m);
			*nuevo *= x;

				// Se devuelve el resultado
				return *nuevo;
			}
	// COMPLETAR


		ed::Monomio & operator*(double const &x, ed::Monomio const &m){

			// Se crea un nuevo objeto
			ed::Monomio *nuevo = new Monomio(m);
			*nuevo *= x;

				// Se devuelve el resultado
				return *nuevo;
			}

	////////////
	// División
	// COMPLETAR
	ed::Monomio & operator/(ed::Monomio const &m1, ed::Monomio const &m2){

			// Se crea un nuevo objeto

			double auxcoef = m1.getCoeficiente();
			int auxgrado = m1.getGrado();
			ed::Monomio *nuevo = new Monomio(m1);
			*nuevo /= m2;
			#ifndef NDEBUG
				assert(std::abs(m1.getCoeficiente() - (auxcoef / m2.getCoeficiente())) < COTA_ERROR);
				assert(std::abs(m1.getGrado() - (auxgrado - m2.getGrado())) == 0);
			#endif

			// Se devuelve el resultado
			return *nuevo;
		}


ed::Monomio & operator/(ed::Monomio const &m, double const &x){

			// Se crea un nuevo objeto

				double auxcoef = m.getCoeficiente();
				int auxgrado = m.getGrado();
				ed::Monomio *nuevo = new Monomio(m);
				*nuevo /= x;

		#ifndef NDEBUG
				assert(std::abs(m.getCoeficiente() - (auxcoef / x)) < COTA_ERROR);
				assert(std::abs(m.getGrado() - auxgrado) == 0);

		#endif

		// Se devuelve el objeto actuif(this->getCoeficiente()==1){
				std::cout<<m.getCoeficiente()<<"X^"<<m.getGrado()<<std::endl;

				// Se devuelve el resultado
				return *nuevo;
		}

		ed::Monomio & operator/(double const &x, ed::Monomio const &m){

					// Se crea un nuevo objeto
						double auxcoef = m.getCoeficiente();
						int auxgrado = m.getGrado();
						ed::Monomio *nuevo = new Monomio(m);
						*nuevo /= x;
				#ifndef NDEBUG
						assert(std::abs(m.getCoeficiente() - (auxcoef / x)) < COTA_ERROR);
						assert(std::abs(m.getGrado() - auxgrado) == 0);

				#endif

				// Se devuelve el objeto actuif(this->getCoeficiente()==1){
						std::cout<<m.getCoeficiente()<<"X^"<<m.getGrado()<<std::endl;

						// Se devuelve el resultado
						return *nuevo;
		}

	/////////////////////////////////////////////////////////////////////////////

	//  Sobrecarga del operador de entrada
	istream &operator>>(istream &stream, ed::Monomio &m)
	{
		// COMPLETAR
		string cadena_aux;
		getline(stream, cadena_aux, ' ');
		m.setCoeficiente(atof(cadena_aux.c_str()));
		getline(stream, cadena_aux); //El valor por defecto de separacion es \n
		m.setGrado(atoi(cadena_aux.c_str()));

   		// Se devuelve el flujo de entrada
		return stream;
	}


	//  Sobrecarga del operador de salida
	ostream &operator<<(ostream &stream, ed::Monomio const &m)
	{
		// COMPLETAR
		stream << m.getCoeficiente() << " " << m.getGrado();
		// Se devuelve el flujo de salida
		return stream;
	}


}  // namespace ed
