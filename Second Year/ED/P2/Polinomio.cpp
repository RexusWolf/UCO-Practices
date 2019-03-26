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
  std::list<ed::Monomio>::iterator begin = this->polinomio_.begin();
	std::list<ed::Monomio>::iterator end = this->polinomio_.end();;
	for(begin; begin != end; begin++){
      if(begin->getCoeficiente() != p.polinomio_.begin()->getCoeficiente()) exit(-1);
  }
	// Se devuelve el objeto actual
	return *this;
		
}


ed::Polinomio & ed::Polinomio::operator=(ed::Monomio const &m){
	//Crea un polinomio vacío. Se le asigna un monomio vacío.
	Polinomio new_p;
	new_p.polinomio_.begin()->setCoeficiente(0.0);
	new_p.polinomio_.begin()->setGrado(0);
	*this = new_p;
	// Se devuelve el objeto actual
	return *this;
}


ed::Polinomio & ed::Polinomio::operator=(double const &x){
	// Asigno el número real x como coeficiente de un polinomio vacío.
	Polinomio p;
	// El monomio existente al crear el polinomio, tendrá grado 0.
	p.polinomio_.begin()->setGrado(0);
	p.polinomio_.begin()->setCoeficiente(x);
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

/*
 std::list<ed::Monomio> ordenaPolinomio(ed::Polinomio const &p){
    std::list<ed::Monomio>::iterator end;
	std::list<ed::Monomio>::iterator it;
	std::list<ed::Monomio>::iterator itj;
	ed::Monomio aux;
	for(it = p.polinomio_.begin()+1; it != end-1; it++){
		for(itj = p.polinomio_.begin(); itj != end; itj++){
			if(*itj > *it){
				aux = *itj;
				*itj = *it;
				*it = aux;
			}
		}
	}
 }

  std::list<ed::Monomio> getPolinomio (ed::Polinomio const &p){
	  return this->polinomio_;
  }
	*/