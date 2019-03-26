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

ed::Polinomio & ed::Polinomio::operator=(ed::Polinomio const &p)
{
	bool iguales = true;
	std::list<Monomio>::iterator begin;
    std::list<Monomio>::iterator end;

    for(begin = polinomio_.begin(); begin != end; begin++){
      if(begin->getCoeficiente() == p.polinomio_.begin()->getCoeficiente()) return *begin;
    }
	
	// Se devuelve el objeto actual
	return *this;
}


ed::Polinomio & ed::Polinomio::operator=(ed::Monomio const &m)
{
	// COMPLETAR

	// Se devuelve el objeto actual
	return *this;
}


ed::Polinomio & ed::Polinomio::operator=(double const &x)
{
	// COMPLETAR

	// Se devuelve el objeto actual
	return *this;
}

//////////////////////////////////////////////////////////////

ed::Polinomio & ed::Polinomio::operator+=(ed::Polinomio const &p)
{
	// COMPLETAR

	// Se devuelve el objeto actual
	return *this;
}

// COMPLETAR EL RESTO DE OPERADORES



///////////////////////////////////////////////////////////////////////

// Funciones lectura y escritura de la clase Polinomio

// COMPLETAR


///////////////////////////////////////////////////////////////////////

// Funciones auxiliares de la clase Polinomio

// COMPLETAR

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