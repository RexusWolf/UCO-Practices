/*!
   \file  operadoresExternosMonomios.cpp
	\brief Ficheros con el código de los operadores externos de la clase Monomio
*/


//  Ficheros de cabecera
#include <iostream>

#include "operadoresExternosMonomios.hpp"


//  Se incluyen los operadores sobrecargados dentro del espacio de nombres ed
namespace ed
{
	// Operadores de igualdad

	// COMPLETAR

	bool operator==(ed::Monomio const & m1, ed::Monomio const & m2)
	{
		// COMPLETAR Y MODIFICAR
		if(m1.getCoeficiente()!=m2.getCoeficiente()) return false;
		if(m1.getGrado()!=m2.getGrado()) return false;

		#ifndef NDEBUG
			assert(std::abs(m1.getCoeficiente() - m2.getCoeficiente()) < COTA_ERROR);
			assert(m1.getGrado() == m2.getGrado());
		#endif
		// MODIFICAR: SE DEVUELVE UN VALOR ARBITRARIO PARA NO GENERAR AVISOS AL COMPILAR
		return true;
	}

	// COMPLETAR LOS OTROS OPERADORES DE IGUALDAD

	bool operator==(ed::Monomio const & m, double const & x)
	{
		// COMPLETAR Y MODIFICAR
		if( std::abs(m.getCoeficiente()-x) < COTA_ERROR && m.getGrado() == 0) return true;

		#ifndef NDEBUG
			assert(std::abs(m.getCoeficiente()-x) < COTA_ERROR && m.getGrado() == 0);
		#endif

		// MODIFICAR: SE DEVUELVE UN VALOR ARBITRARIO PARA NO GENERAR AVISOS AL COMPILAR
		return false;
	}

	bool operator==(double const & x, ed::Monomio const & m)
	{
		// COMPLETAR Y MODIFICAR
		if( std::abs(m.getCoeficiente()-x) < COTA_ERROR && m.getGrado() == 0) return true;

		#ifndef NDEBUG
			assert(std::abs(m.getCoeficiente()-x) < COTA_ERROR && m.getGrado() == 0);
		#endif

		// MODIFICAR: SE DEVUELVE UN VALOR ARBITRARIO PARA NO GENERAR AVISOS AL COMPILAR
		return false;
	}

	// Operadores de desigualdad

	// COMPLETAR
	bool operator!=(ed::Monomio const & m1, ed::Monomio const & m2)
	{
		// COMPLETAR Y MODIFICAR
		if(m1.getCoeficiente()!=m2.getCoeficiente()){
			if(m1.getGrado()!=m2.getGrado()) return false;
		}
		else if (m1.getGrado()!=m2.getGrado()) return false;

		#ifndef NDEBUG
			assert((std::abs(m1.getCoeficiente() - m2.getCoeficiente()) > COTA_ERROR) || m1.getGrado() != m2.getGrado());
		#endif
		// MODIFICAR: SE DEVUELVE UN VALOR ARBITRARIO PARA NO GENERAR AVISOS AL COMPILAR
		return true;
	}

	bool operator!=(ed::Monomio const & m, double const & x)
	{
		// COMPLETAR Y MODIFICAR
		if( std::abs(m.getCoeficiente()-x) > COTA_ERROR || m.getGrado() != 0) return true;

		#ifndef NDEBUG
			assert( std::abs(m.getCoeficiente()-x) > COTA_ERROR || m.getGrado() != 0);
		#endif

		// MODIFICAR: SE DEVUELVE UN VALOR ARBITRARIO PARA NO GENERAR AVISOS AL COMPILAR
		return false;
	}

	bool operator!=(double const & x, ed::Monomio const & m)
	{
		// COMPLETAR Y MODIFICAR
		if( std::abs(m.getCoeficiente()-x) > COTA_ERROR || m.getGrado() != 0) return true;

		#ifndef NDEBUG
			assert( std::abs(m.getCoeficiente()-x) > COTA_ERROR || m.getGrado() != 0);
		#endif

		// MODIFICAR: SE DEVUELVE UN VALOR ARBITRARIO PARA NO GENERAR AVISOS AL COMPILAR
		return false;
	}

	// COMPLETAR LOS OTROS OPERADORES DE DESIGUALDAD


	////////////////////////////////////////////////////////////

	// Operadores unarios prefijos

	// COMPLETAR
	ed::Monomio & operator+(ed::Monomio const & m)
	{
		// COMPLETAR Y MODIFICAR
		#ifndef NDEBUG
				assert(this->getGrado() == m.getGrado());
		#endif

				double auxcoef = this->getCoeficiente();
				int auxgrado = this->getGrado();
				this->setCoeficiente(this->getCoeficiente() + m.getCoeficiente());

		// Se crea un nuevo objeto
		ed::Monomio *nuevo = new ed::Monomio();
		nuevo = this;

		#ifndef NDEBUG
				assert(std::abs(this->getCoeficiente() - (auxcoef + m.getCoeficiente())) < COTA_ERROR);
				assert(this->getGrado() == m.getGrado());
				assert(this->getGrado() == auxgrado);
		#endif

		// Se devuelve el resultado
		return *nuevo;
	}

	// COMPLETAR EL OTRO OPERADOR UNARIO PREFIJO: resta
	ed::Monomio & operator-(ed::Monomio const & m)
	{
		// COMPLETAR Y MODIFICAR

		#ifndef NDEBUG
				assert(this->getGrado() == m.getGrado());
		#endif

				double auxcoef = this->getCoeficiente();
				int auxgrado = this->getGrado();
				this->setCoeficiente(this->getCoeficiente() - m.getCoeficiente());

		// Se crea un nuevo objeto
		ed::Monomio *nuevo = new ed::Monomio();
		nuevo = this;

		#ifndef NDEBUG
				assert(std::abs(this->getCoeficiente() - (auxcoef - m.getCoeficiente())) < COTA_ERROR);
				assert(this->getGrado() == m.getGrado());
				assert(this->getGrado() == auxgrado);
		#endif

		// Se devuelve el resultado
		return *nuevo;
	}

	////////////////////////////////////////////////////////////
	// Operadores aritméticos binarios

	// Suma
	ed::Monomio & operator+ (ed::Monomio const &m1, ed::Monomio const &m2)
	{
		// COMPLETAR Y MODIFICAR
		// Se crea un nuevo objeto
		ed::Monomio *nuevo = new ed::Monomio();

		#ifndef NDEBUG
				assert(m1.getGrado() == m2.getGrado());
		#endif
				double auxcoef = m1.getCoeficiente();
				int auxgrado = m1.getGrado();
				nuevo.setCoeficiente(m1.getCoeficiente() + m2.getCoeficiente());

		#ifndef NDEBUG
				assert(std::abs(m1.getCoeficiente() - (auxcoef + m2.getCoeficiente())) < COTA_ERROR);
				assert(m1.getGrado() == m2.getGrado());
				assert(nuevo.getGrado() == auxgrado);
		#endif

		nuevo = this;


		// Se devuelve el resultado
		return *nuevo;
	}


	////////////
	// Resta
	ed::Monomio & operator- (ed::Monomio const &m1, ed::Monomio const &m2)
	{
		// COMPLETAR Y MODIFICAR
		// Se crea un nuevo objeto
		ed::Monomio *nuevo = new ed::Monomio();

		#ifndef NDEBUG
				assert(m1.getGrado() == m2.getGrado());
		#endif
				double auxcoef = m1.getCoeficiente();
				int auxgrado = m1.getGrado();
				m1.setCoeficiente(m1.getCoeficiente() - m2.getCoeficiente());

		#ifndef NDEBUG
				assert(std::abs(m1.getCoeficiente() - (auxcoef - m2.getCoeficiente())) < COTA_ERROR);
				assert(m1.getGrado() == m2.getGrado());
				assert(m1.getGrado() == auxgrado);
		#endif

		nuevo = this;

		// Se devuelve el resultado
		return *nuevo;
	}
	// COMPLETAR


	//////////////////
	// Multiplicación
	ed::Monomio & operator*(ed::Monomio const &m1, ed::Monomio const &m2){

		// Se crea un nuevo objeto
		ed::Monomio *nuevo = new ed::Monomio();

		double auxcoef = m1.getCoeficiente();
		int auxgrado = m1.getGrado();
		this->setCoeficiente(m1.getCoeficiente() * m2.getCoeficiente());
		this->setGrado(m1.getGrado() + m2.getGrado());
	#ifndef NDEBUG
		assert(std::abs(m1.getCoeficiente() - (auxcoef * m2.getCoeficiente())) < COTA_ERROR);
		assert(std::abs(m1.getGrado() - (auxgrado + m2.getGrado())) == 0);
	#endif

			nuevo = this;

			// Se devuelve el resultado
			return *nuevo;
		}

		ed::Monomio & operator*(ed::Monomio const &m, double const &x){

			// Se crea un nuevo objeto
			ed::Monomio *nuevo = new ed::Monomio();


			this->setCoeficiente(m.getCoeficiente() * x);

				nuevo = this;

				// Se devuelve el resultado
				return *nuevo;
			}
	// COMPLETAR


	ed::Monomio & operator*(double const &x, ed::Monomio const &m){

				// Se crea un nuevo objeto
				ed::Monomio *nuevo = new ed::Monomio();

					double auxcoef = this->getCoeficiente();
					int auxgrado = this->getGrado();
					this->setCoeficiente(this->getCoeficiente() * x);
						#ifndef NDEBUG
						assert(std::abs(this->getCoeficiente() - (auxcoef * x)) < COTA_ERROR);
						assert(std::abs(this->getGrado() - auxgrado) == 0);
						#endif
				// Se devuelve el objeto actuif(this->getCoeficiente()==1){
					std::cout<<this->getCoeficiente()<<"X^"<<this->getGrado()<<std::endl;
					nuevo = this;
						// Se devuelve el resultado
					return *nuevo;
			}
	////////////
	// División
	// COMPLETAR
	ed::Monomio & operator/(ed::Monomio const &m1, ed::Monomio const &m2){

			// Se crea un nuevo objeto
			ed::Monomio *nuevo = new ed::Monomio();

			double auxcoef = m1.getCoeficiente();
			int auxgrado = m1.getGrado();
			this->setCoeficiente(m1.getCoeficiente() / m2.getCoeficiente());
			this->setGrado(m1.getGrado() - m2.getGrado());
			#ifndef NDEBUG
				assert(std::abs(m1.getCoeficiente() - (auxcoef / m2.getCoeficiente())) < COTA_ERROR);
				assert(std::abs(m1.getGrado() - (auxgrado - m2.getGrado())) == 0);
			#endif

			nuevo = this;

			// Se devuelve el resultado
			return *nuevo;
		}


ed::Monomio & operator/(ed::Monomio const &m, double const &x){

			// Se crea un nuevo objeto
			ed::Monomio *nuevo = new ed::Monomio();

				double auxcoef = this->getCoeficiente();
				int auxgrado = this->getGrado();
				this->setCoeficiente(this->getCoeficiente() / x);
		#ifndef NDEBUG
				assert(std::abs(this->getCoeficiente() - (auxcoef / x)) < COTA_ERROR);
				assert(std::abs(this->getGrado() - auxgrado) == 0);

		#endif

		// Se devuelve el objeto actuif(this->getCoeficiente()==1){
				std::cout<<this->getCoeficiente()<<"X^"<<this->getGrado()<<std::endl;

				nuevo = this;

				// Se devuelve el resultado
				return *nuevo;
		}

		ed::Monomio & operator/(double const &x, ed::Monomio const &m){

					// Se crea un nuevo objeto
					ed::Monomio *nuevo = new ed::Monomio();

						double auxcoef = this->getCoeficiente();
						int auxgrado = this->getGrado();
						this->setCoeficiente(this->getCoeficiente() / x);
				#ifndef NDEBUG
						assert(std::abs(this->getCoeficiente() - (auxcoef / x)) < COTA_ERROR);
						assert(std::abs(this->getGrado() - auxgrado) == 0);

				#endif

				// Se devuelve el objeto actuif(this->getCoeficiente()==1){
						std::cout<<this->getCoeficiente()<<"X^"<<this->getGrado()<<std::endl;

						nuevo = this;

						// Se devuelve el resultado
						return *nuevo;
		}

	/////////////////////////////////////////////////////////////////////////////

	//  Sobrecarga del operador de entrada
	istream &operator>>(istream &stream, ed::Monomio &m)
	{
		// COMPLETAR

   		// Se devuelve el flujo de entrada
		return stream;
	}


	//  Sobrecarga del operador de salida
	ostream &operator<<(ostream &stream, ed::Monomio const &m)
	{
		// COMPLETAR

		// Se devuelve el flujo de salida
		return stream;
	}


}  // namespace ed
