/*!
   \file  Monomio.cpp
   \brief Fichero que contiene el código de las funciones de la clase Monomio
*/


//  Ficheros de cabecera
#include <iostream>

#include "Monomio.hpp"

using namespace std;

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
	#ifndef NDEBUG
			assert(std::abs(this->getCoeficiente() - (auxcoef * x)) < COTA_ERROR);
			assert(std::abs(this->getGrado() - auxgrado) == 0);

	#endif

	// Se devuelve el objeto actuif(this->getCoeficiente()==1){
			cout<<this->getCoeficiente()<<"X^"<<this->getGrado()<<endl;

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
	void ed::Monomio::leerMonomio(){
		double coeficiente;
		int grado;
		cout<<"Introduce coeficiente:"<<endl;
		cin>>coeficiente;
		cout<<"Introducir grado:"<<endl;
		cin>>grado;
		while(grado<0){
		cout<<"ERROR: Grado no válido."<<endl;
		cout<<"Introducir nuevo grado:"<<endl;
		cin>>grado;
		}
		Monomio(coeficiente,grado);
	}

	void ed::Monomio::escribirMonomio(){
		if( this->getCoeficiente() != 1 ){
				cout<<this->getCoeficiente();
		}
			else if(not (this->getCoeficiente() -1 < COTA_ERROR)){
				cout<<"-";
			}

		if(not(this->getGrado() < COTA_ERROR)	){ 
			cout<<"X";
		}
			else if( not (this->getGrado() -1 < COTA_ERROR) ){
				cout<<"^"<<this->getGrado()<<endl;
			}
	}
///////////////////////////////////////////////////////////////////////

// Funciones auxiliares de la clase Monomio

// COMPLETAR
 	double ed::Monomio::calcularValor(double const &x){
		double valor;
		valor = this->getCoeficiente()*pow(x,this->getGrado());
		return valor;
	}
