/*!
   \file Polinomio.cpp
   \brief Fichero que contiene el código de las funciones de la clase Polinomio
*/


// Ficheros de cabecera
#include <iostream>

#include "Polinomio.hpp"

// Operadores de asignación

// COMPLETAR


/////////////////////////////////////////////////////////////

ed::Polinomio & ed::Polinomio::operator=(ed::Polinomio const &p){
	bool iguales = true;
  std::vector<ed::Monomio>::iterator begin = this->getMonomios().begin();
	std::vector<ed::Monomio>::iterator end = this->getMonomios().end();;
	for(begin; begin != end; begin++){
      if(begin->getCoeficiente() != p.getMonomios().begin()->getCoeficiente()) exit(-1);
  }
	// Se devuelve el objeto actual
	return *this;
		
}


ed::Polinomio & ed::Polinomio::operator=(ed::Monomio const &m){
	//Crea un polinomio vacío. Se le asigna un monomio vacío.
	Polinomio new_p;
	new_p.getMonomios().begin()->setCoeficiente(0.0);
	new_p.getMonomios().begin()->setGrado(0);
	*this = new_p;
	// Se devuelve el objeto actual
	return *this;
}


ed::Polinomio & ed::Polinomio::operator=(double const &x){
	// Asigno el número real x como coeficiente de un polinomio vacío.
	Polinomio p;
	// El monomio existente al crear el polinomio, tendrá grado 0.
	p.getMonomios().begin()->setGrado(0);
	p.getMonomios().begin()->setCoeficiente(x);
	// Se devuelve el objeto actual
	return *this;
}

//////////////////////////////////////////////////////////////

//Operadores aritméticos y de asignación

//Suma
ed::Polinomio & ed::Polinomio::operator+=(ed::Polinomio const &p){
	
	// Se devuelve el objeto actual
	return *this;
}

ed::Polinomio & ed::Polinomio::operator+=(ed::Monomio const &m){
	
	// Se devuelve el objeto actual
	return *this;
}

ed::Polinomio & ed::Polinomio::operator+=(double const &x){
	
	// Se devuelve el objeto actual
	return *this;
}

//Resta

ed::Polinomio & ed::Polinomio::operator-=(ed::Polinomio const &p){
	
	return *this;
}

ed::Polinomio & ed::Polinomio::operator-=(ed::Monomio const &m){
	
	return *this;
}

ed::Polinomio & ed::Polinomio::operator-=(double const &x){

	return *this;
}

//Multiplicación

ed::Polinomio & ed::Polinomio::operator*=(ed::Polinomio const &p){
	
	return *this;
}

ed::Polinomio & ed::Polinomio::operator*=(ed::Monomio const &m){
	
	return *this;
}

ed::Polinomio & ed::Polinomio::operator*=(double const &x){

	return *this;
}

//División

ed::Polinomio & ed::Polinomio::operator/=(ed::Polinomio const &p){
	
	return *this;
}

ed::Polinomio & ed::Polinomio::operator/=(ed::Monomio const &m){
	
	return *this;
}

ed::Polinomio & ed::Polinomio::operator/=(double const &x){

	return *this;
}

///////////////////////////////////////////////////////////////////////

// Funciones lectura y escritura de la clase Polinomio

// COMPLETAR


///////////////////////////////////////////////////////////////////////

// Funciones auxiliares de la clase Polinomio

// COMPLETAR

// Función de ordenación de polinomio
void ed::Polinomio::ordenaPolinomio(){
	// Creamos un monomio auxiliar con un grado muy grande.
	Monomio aux;
	aux.setGrado(9999999);
	// Creamos un vector (polinomio) auxiliar en el que ordenar el polinomio inicial
	std::vector<Monomio> aux_polinomio;
	std::vector<Monomio>::iterator it;

	// Recorremos el polinomio actual y lo ordenamos.
	for(int i = 0; i < this->getNumeroMonomios(); i++){
		for( it = this->getMonomios().begin(); it != this->getMonomios().end(); it++){
			if ( it->getGrado() < aux.getGrado()){
				aux = *it;
			}
		}
		aux_polinomio.push_back(aux);
	}
	this->getMonomios() = aux_polinomio;
}