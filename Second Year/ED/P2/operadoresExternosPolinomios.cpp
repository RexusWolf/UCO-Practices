/*!
   \file operadoresExternosPolinomios.cpp
   \brief Fichero que contiene el código de las funciones de la clase Polinomio
*/


// Ficheros de cabecera
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
#include <cstdio>

#include "operadoresExternosPolinomios.hpp"

#include "operadoresExternosMonomios.hpp"

// Se incluyen los operadores sobrecargados dentro del espacio de nombres de ed

namespace ed
{

bool operator==(ed::Polinomio const & p1, ed::Polinomio const & p2)
{
	vector <Monomio>::const_iterator m1 = p1.getMonomios().begin();
	vector <Monomio>::const_iterator m2 = p2.getMonomios().begin();
	if(p1.getNumeroMonomios() != p2.getNumeroMonomios()) return false;
	else {
		while((m1 != p1.getMonomios().end()) && m2 != p2.getMonomios().end()) {
			if(m1 != m2) return false;
		}
	}
	return true;
}

// COMPLETAR LOS OTROS OPERADORES DE IGUALDAD
bool operator==(Polinomio const &p, Monomio const & m) {
	if(p.getNumeroMonomios() != 1) return false;
	else if(p.getMonomios().front() != m) return false;
	else return true;
}

bool operator==(Monomio const & monomio, Polinomio const &polinomio) {
	return polinomio == monomio;
}

bool operator==(Polinomio const &p, double x) {
	vector <Monomio>::const_iterator monomio;
	if(p.getNumeroMonomios() != 1) return false;
	else if(p.getMonomios().front() != x) return false;
	else return true;
}

bool operator==(double x, Polinomio const &polinomio) {
	return polinomio == x;
}


////////////////////////////////////////////////////////////////////////////////////
// Operadores de desigualdad
bool operator!=(Polinomio const & p1, Polinomio const & p2) {
	return !(p1 == p2);
}

bool operator!=(Polinomio const & polinomio, Monomio const & monomio) {
	return !(polinomio == monomio);
}

bool operator!=(Monomio const & monomio, Polinomio const & polinomio) {
	return !(polinomio == monomio);
}

bool operator!=(Polinomio const & polinomio, double x) {
	return !(polinomio == x);
}

bool operator!=(double x, Polinomio const & polinomio) {
	return !(polinomio == x);
}


//////////////////////////////////////////////////////////////////////////////////////

// Operadores unarios

// COMPLETAR
Polinomio & operator+(Polinomio const & polinomio) {
	Polinomio *return_polinomio = new Polinomio(polinomio);
	return *return_polinomio;
}

// COMPLETAR EL OTRO OPERADOR UNARIO PREFIJO: resta ¡
Polinomio & operator-(Polinomio const & p) {
	Polinomio *return_polinomio = new Polinomio(p);
	for(int i = 0; i < p.getNumeroMonomios(); i++) {
		return_polinomio->getMonomios()[i] = -p.getMonomios()[i];
	}
	return_polinomio->escribirPolinomio();
	return *return_polinomio;
}





//////////////////////////////////////////////////////////////////////////////////////

//OPERADORES BINARIOS

//Operador suma

Polinomio & operator+(Polinomio const &p1,  Polinomio const &p2) {
	//Creo el nuevo objeto
	Polinomio *new_polinomio = new Polinomio;
	//Creo el nuevo vector con los mismos monomios que el polinomio 1
	vector <Monomio> new_vector = p1.getMonomios();
	for(int i = 0; i < p2.getNumeroMonomios(); i++) {
		//Si existe un monomio en el polinomio 1 con el mismo grado que el monomio de esta itearaciñon del polinomio 2
		if(p1.existeMonomio(p2.getMonomios()[i].getGrado())) {
			//Recorre el polinomio 1 buscando ese monomio, y se suma al del polinomio 2
			for(int j = 0; j < p1.getNumeroMonomios(); j++) {
				if(p1.getMonomios()[j].getGrado() == p2.getMonomios()[i].getGrado()) {
					new_vector[j] = p1.getMonomios()[j] + p2.getMonomios()[i];
				}
			}
		}
		//Si no existe un monomio en el polinomio 1 con ese grado, el monomio del polinomio 2 de esta iteración se añade al nuevo polinomio
		else new_vector.push_back(p2.getMonomios()[i]);
	}
	new_polinomio->setMonomios(new_vector);
	new_polinomio->escribirPolinomio();
	return *new_polinomio;
}

Polinomio & operator+(Polinomio const &p, Monomio const & m) {
	Polinomio *return_polinomio = new Polinomio;
	vector <Monomio> new_vector = p.getMonomios();
	bool sumado = false;
	for(int index = 0; index < p.getNumeroMonomios(); index++) {
		if(p.getMonomios()[index].getGrado() == m.getGrado()) {
			new_vector[index] = p.getMonomios()[index] + m;
			sumado = true;
		}
	}
	if(sumado == false) new_vector.push_back(m);
	return_polinomio->setMonomios(new_vector);
	return *return_polinomio;
}

Polinomio & operator+(Monomio const & m, Polinomio const &p) {
	Polinomio *return_polinomio = new Polinomio(p + m);
	return *return_polinomio;
}

Polinomio & operator+(Polinomio const &p, double x) {
	Monomio monomio_aux(0, x);
	Polinomio *return_polinomio = new Polinomio(p + monomio_aux);
	return *return_polinomio;
}

Polinomio & operator+(double x, Polinomio const &p) {
	Monomio monomio_aux(0, x);
	Polinomio *return_polinomio = new Polinomio(p + monomio_aux);
	return *return_polinomio;
}

//Operador resta

Polinomio & operator-(Polinomio const &p1,  Polinomio const &p2) {
	Polinomio *return_polinomio = new Polinomio(p1 + (-p2));
	return *return_polinomio;
}

Polinomio & operator-(Polinomio const &p, Monomio const & m) {
	Polinomio *return_polinomio = new Polinomio(p + (-m));
	return *return_polinomio;
}

Polinomio & operator-(Monomio const & m, Polinomio const &p) {
	Polinomio *return_polinomio = new Polinomio(p - m);
	return *return_polinomio;
}

Polinomio & operator-(Polinomio const &p, double x) {
	Monomio monomio_aux(0, x);
	Polinomio *return_polinomio = new Polinomio(p - monomio_aux);
	return *return_polinomio;
}

Polinomio & operator-(double x, Polinomio const &p) {
	Monomio monomio_aux(0, x);
	Polinomio *return_polinomio = new Polinomio(p - monomio_aux);
	return *return_polinomio;
}

//Operador multiplicación

Polinomio & operator*(Polinomio const &p1,  Polinomio const &p2) {
	Polinomio new_polinomio;
	vector <Monomio>::const_iterator m1;
	for(m1 = p1.getMonomios().begin(); m1 != p1.getMonomios().end(); m1++) {
		new_polinomio = p2 * (*m1);
	}
	Polinomio *return_polinomio = new Polinomio(new_polinomio);
	return *return_polinomio;
}

Polinomio & operator*(Polinomio const &polinomio, Monomio const & m) {
	vector <Monomio> new_vector = polinomio.getMonomios();
	int index = 0;
	vector <Monomio>::const_iterator monomio_it;
	for(monomio_it = polinomio.getMonomios().begin(); monomio_it != polinomio.getMonomios().end(); monomio_it++) {
		new_vector.assign(index, *monomio_it * m);
		index++;
	}
	Polinomio new_polinomio;
	new_polinomio.getMonomios()setMonomios(new_vector);
	Polinomio *return_polinomio = new Polinomio(new_polinomio);
	return *return_polinomio;
}

Polinomio & operator*(Monomio const &m, Polinomio const &p) {
	Polinomio *return_polinomio = new Polinomio(p * m);
	return *return_polinomio;
}

Polinomio & operator*(Polinomio const &p, double x) {
	Monomio monomio_aux(0, x);
	Polinomio *return_polinomio = new Polinomio(p * monomio_aux);
	return *return_polinomio;
}

Polinomio & operator*(double x, Polinomio const &p) {
	Monomio monomio_aux(0, x);
	Polinomio *return_polinomio = new Polinomio(p * monomio_aux);
	return *return_polinomio;
}

//Operador división

Polinomio & operator/(Polinomio const &p1,  Polinomio const &p2) {
	Polinomio *return_polinomio = new Polinomio();
	return *return_polinomio;
}

Polinomio & operator/(Polinomio const &p, Monomio const &m) {
	Polinomio *return_polinomio = new Polinomio();
	return *return_polinomio;
}

Polinomio & operator/(Monomio const & m, Polinomio const &p) {
	Polinomio *return_polinomio = new Polinomio();
	return *return_polinomio;
}

Polinomio & operator/(Polinomio const &p, double x) {
	Polinomio *return_polinomio = new Polinomio();
	return *return_polinomio;
}

Polinomio & operator/(double x, Polinomio const &p) {
	Polinomio *return_polinomio = new Polinomio();
	return *return_polinomio;
}

//////////////////////////////////////////////////////////////////////////////////////

//Operadores de flujo

ostream &operator<<(ostream &stream, Polinomio const &p) {
	vector <Monomio>::const_iterator monomio;
	for(monomio = p.getMonomios().begin(); monomio != p.getMonomios().end(); monomio++) {
		stream << *monomio << " ";
	}
	return stream;
}

istream &operator>>(istream &stream, Polinomio &p) {
	std::string cadena_auxiliar;
	Monomio aux_monomio;
	while(getline(stream, cadena_auxiliar)) {
		stream >> aux_monomio;
		p.getMonomios().push_back(aux_monomio);
	}
	return stream;
}


} // Fin del espacio de nombres ed
