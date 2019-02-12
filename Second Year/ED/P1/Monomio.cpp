/*!
   \file  Monomio.cpp
   \brief Fichero que contiene el código de las funciones de la clase Monomio
*/


//  Ficheros de cabecera
#include <iostream>

#include "Monomio.hpp"

// Operadores de asignación

// COMPLETAR

ed::Monomio & ed::Monomio::operator=(ed::Monomio const &m)
{
	// COMPLETAR
			this->setCoeficiente(m.getCoeficiente());
			this->setGrado(m.getGrado());

			#ifndef NDEBUG
				assert(std::abs(this->getCoeficiente() - m.getCoeficiente()) < COTA_ERROR);
				assert(this->getGrado() == m.getGrado());
			#endif

	// Se devuelve el objeto actual
	return *this;
}


ed::Monomio & ed::Monomio::operator=(double const &x)
{
	// COMPLETAR
			this->setCoeficiente(x);
			this->setGrado(0);

			#ifndef NDEBUG
				assert(std::abs(this->getCoeficiente() - x) < COTA_ERROR);
				assert(this->getGrado() == 0);
			#endif
	// Se devuelve el objeto actual
	return *this;
}



//////////////////////////////////////////////////////////////

// Operadores aritméticos y asignación

// COMPLETAR

ed::Monomio & ed::Monomio::operator+=(ed::Monomio const &m)
{
	// COMPLETAR
	#ifndef NDEBUG
			assert(this->getGrado() == m.getGrado());
	#endif
			double auxcoef = this->getCoeficiente();
			int auxgrado = this->getGrado();
			this->setCoeficiente(this->getCoeficiente() + m.getCoeficiente());

	#ifndef NDEBUG
			assert(std::abs(this->getCoeficiente() - (auxcoef + m.getCoeficiente())) < COTA_ERROR);
			assert(this->getGrado() == m.getGrado());
			assert(this->getGrado() == auxgrado);
	#endif

	// Se devuelve el objeto actual
	return *this;
}



// COMPLETAR EL RESTO DE OPERADORES
ed::Monomio & ed::Monomio::operator-=(ed::Monomio const &m)
{
	// COMPLETAR
	#ifndef NDEBUG
			assert(this->getGrado() == m.getGrado());
	#endif
			double auxcoef = this->getCoeficiente();
			int auxgrado = this->getGrado();
			this->setCoeficiente(this->getCoeficiente() - m.getCoeficiente());

	#ifndef NDEBUG
			assert(std::abs(this->getCoeficiente() - (auxcoef - m.getCoeficiente())) < COTA_ERROR);
			assert(this->getGrado() == m.getGrado());
			assert(this->getGrado() == auxgrado);
	#endif

	// Se devuelve el objeto actual
	return *this;
}

ed::Monomio & ed::Monomio::operator*=(ed::Monomio const &m)
{
	// COMPLETAR

			double auxcoef = this->getCoeficiente();
			int auxgrado = this->getGrado();
			this->setCoeficiente(this->getCoeficiente() * m.getCoeficiente());
			this->setGrado(this->getGrado() + m.getGrado());
	#ifndef NDEBUG
			assert(std::abs(this->getCoeficiente() - (auxcoef * m.getCoeficiente())) < COTA_ERROR);
			assert(std::abs(this->getGrado() - (auxgrado + m.getGrado())) == 0);

	#endif

	// Se devuelve el objeto actual
	return *this;
}

ed::Monomio & ed::Monomio::operator/=(ed::Monomio const &m)
{
	// COMPLETAR
	#ifndef NDEBUG
			assert(this->getGrado()>=m.getGrado());
			assert(m.getCoeficiente() != 0.0);
	#endif
			double auxcoef = this->getCoeficiente();
			int auxgrado = this->getGrado();
			this->setCoeficiente(this->getCoeficiente() / m.getCoeficiente());
			this->setGrado(this->getGrado() - m.getGrado());
	#ifndef NDEBUG
			assert(std::abs(this->getCoeficiente() - (auxcoef / m.getCoeficiente())) < COTA_ERROR);
			assert(std::abs(this->getGrado() - (auxgrado - m.getGrado())) == 0);

	#endif

	// Se devuelve el objeto actual
	return *this;
}

ed::Monomio & ed::Monomio::operator*=(double const &x)
{
	// COMPLETAR
			double auxcoef = this->getCoeficiente();
			int auxgrado = this->getGrado();
			this->setCoeficiente(this->getCoeficiente() * x);
			this->setGrado(this->getGrado() + m.getGrado());
	#ifndef NDEBUG
			assert(std::abs(this->getCoeficiente() - (auxcoef * x)) < COTA_ERROR);
			assert(std::abs(this->getGrado() - auxgrado) == 0);

	#endif

	// Se devuelve el objeto actual
	return *this;
}

ed::Monomio & ed::Monomio::operator/=(double const &x)
{
	// COMPLETAR
	#ifndef NDEBUG
			assert(x != 0.0);
	#endif
			double auxcoef = this->getCoeficiente();
			int auxgrado = this->getGrado();
			this->setCoeficiente(this->getCoeficiente() / x);
	#ifndef NDEBUG
			assert(std::abs(this->getCoeficiente() - (auxcoef / x)) < COTA_ERROR);
			assert(std::abs(this->getGrado() - auxgrado) == 0);

	#endif

	// Se devuelve el objeto actual
	return *this;
}



///////////////////////////////////////////////////////////////////////

// Funciones lectura y escritura de la clase Monomio

// COMPLETAR


///////////////////////////////////////////////////////////////////////

// Funciones auxiliares de la clase Monomio

// COMPLETAR
