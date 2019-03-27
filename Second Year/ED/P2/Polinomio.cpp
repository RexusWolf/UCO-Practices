/*!
   \file Polinomio.cpp
   \brief Fichero que contiene el código de las funciones de la clase Polinomio
*/


// Ficheros de cabecera
#include <iostream>
using namespace std;

#include "Polinomio.hpp"

// Operadores de asignación

// COMPLETAR


/////////////////////////////////////////////////////////////

ed::Polinomio & ed::Polinomio::operator=(ed::Polinomio const &p){
	#ifndef NDEBUG
		assert(this->getMonomios() != p.getMonomios());
	#endif

	this->setMonomios(p.getMonomios());

	#ifndef NDEBUG
		assert(this->getMonomios() == p.getMonomios());
	#endif

	// Se devuelve el objeto actual
	return *this;		
}


ed::Polinomio & ed::Polinomio::operator=(ed::Monomio const &m){
	std::vector<Monomio> aux_vector;
	aux_vector.push_back(m);

	this->setMonomios(aux_vector);

	#ifndef NDEBUG
		assert(this->getMonomios() == aux_vector);
	#endif
	return *this;
}


ed::Polinomio & ed::Polinomio::operator=(double const &x){
	// Asigno el número real x como coeficiente de un polinomio vacío.
	std::vector<Monomio> aux_vector;
	ed::Monomio m(x, 0);
	aux_vector.push_back(m);
	// El monomio existente al crear el polinomio, tendrá grado 0.
	this->setMonomios(aux_vector);
	// Se devuelve el objeto actual

	#ifndef NDEBUG
		assert(this->getMonomios() == aux_vector);
	#endif

	return *this;
}

//////////////////////////////////////////////////////////////

//Operadores aritméticos y de asignación

//Suma
ed::Polinomio & ed::Polinomio::operator+=(ed::Polinomio const &p){
	std::vector<Monomio>::iterator it;
	for (it = p.getMonomios().begin(); it != p.getMonomios().end(); it++){
		this->insertaMonomio(*it);
	}
	// Se devuelve el objeto actual
	return *this;
}

ed::Polinomio & ed::Polinomio::operator+=(ed::Monomio const &m){
	this->insertaMonomio(m);
	// Se devuelve el objeto actual
	return *this;
}

ed::Polinomio & ed::Polinomio::operator+=(double const &x){
	Monomio m(x,0);
	this->insertaMonomio(m);
	// Se devuelve el objeto actual
	return *this;
}

//Resta

ed::Polinomio & ed::Polinomio::operator-=(ed::Polinomio const &p){
	std::vector<Monomio>::iterator it;
	ed::Monomio m;
	for (it = p.getMonomios().begin(); it != p.getMonomios().end(); it++){
		m.setCoeficiente(- it->getCoeficiente());
		m.setGrado(it->getGrado());
		this->insertaMonomio(m);
	}
	return *this;
}

ed::Polinomio & ed::Polinomio::operator-=(ed::Monomio const &m){
	Monomio aux(-m.getCoeficiente(), m.getGrado());
	this->insertaMonomio(m);
	// Se devuelve el objeto actual
	return *this;
}

ed::Polinomio & ed::Polinomio::operator-=(double const &x){
	Monomio m(x,0);
	this->insertaMonomio(m);
	// Se devuelve el objeto actual
	return *this;
	return *this;
}

//Multiplicación

ed::Polinomio & ed::Polinomio::operator*=(ed::Polinomio const &p){
	std::vector<Monomio>::iterator it;
	for (it = p.getMonomios().begin(); it != p.getMonomios().end(); it++){
		*this *= *it;
	}

	return *this;
}

ed::Polinomio & ed::Polinomio::operator*=(ed::Monomio const &m){
	std::vector<Monomio> vector = this->getMonomios();

	std::vector<Monomio>::iterator it;
	for (it = vector.begin(); it != vector.end(); it++){
		*it *= m;
	}

	this->setMonomios(vector);
	return *this;
}

ed::Polinomio & ed::Polinomio::operator*=(double const &x){
	ed::Monomio m(x,0);
	std::vector<Monomio>::iterator it;
	for(it = this->getMonomios.begin(); it != this->getMonomios().end(); it++ ){
		*it *= m;
	}
	return *this;
}

//División

ed::Polinomio & ed::Polinomio::operator/=(ed::Polinomio const &p){
	
	return *this;
}

ed::Polinomio & ed::Polinomio::operator/=(ed::Monomio const &m){
	std::vector<Monomio>::iterator it;
	for(it = this->getMonomios.begin(); it != this->getMonomios().end(); it++ ){
		*it /= m;
	}
	return *this;
}

ed::Polinomio & ed::Polinomio::operator/=(double const &x){
	ed::Monomio m(x,0);
	std::vector<Monomio>::iterator it;
	for(it = this->getMonomios.begin(); it != this->getMonomios().end(); it++ ){
		*it /= m;
	}
	return *this;
}

///////////////////////////////////////////////////////////////////////

// Funciones lectura y escritura de la clase Polinomio

// COMPLETAR
void ed::Polinomio::leerPolinomio(){
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
	ed::Monomio m(coeficiente,grado);
	this->insertaMonomio(m);
	#ifndef NDEBUG
			assert (m.getGrado() >= 0);
	#endif
}

void ed::Polinomio::escribirPolinomio(){
	std::vector<ed::Monomio>::iterator it;

	for( it = this->getMonomios().begin(); it != this->getMonomios().end(); it++){
		it->escribirMonomio();
	}
}


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

void ed::Polinomio::insertaMonomio(ed::Monomio const &new_monomio){
	if (this->existeMonomio(new_monomio.getGrado)){
		std::vector<Monomio>::iterator it;
		for (it = monomios_.begin(); it != monomios_.end(); it++){
			if(it->getGrado() == new_monomio.getGrado()){
				*it += new_monomio;
			}
		}
	}
	else{
		monomios_.push_back(new_monomio);
		//this->ordenaPolinomio();
	}
}