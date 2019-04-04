/*!
   \file Polinomio.hpp
   \brief Definición de la clase Polinomio
*/

#ifndef _POLINOMIO_HPP_
#define _POLINOMIO_HPP_

// Control de asertos
#include <cassert>

// Vector de STL
#include <vector>
#include <list>

// Para usar la función abs
#include <cmath>

#include "PolinomioInterfaz.hpp"
#include "Monomio.hpp"
#include "operadoresExternosMonomios.hpp"


// Se incluye la clase Polinomio dentro del espacio de nombre de la asigantura: ed
namespace ed {

//!  Definición de la clase Polinomio que hereda de PolinomioInterfaz
class Polinomio: public ed::PolinomioInterfaz
{

  //! \name Atributos privados de la clase Polinomio

   private:
     std::vector<Monomio> monomios_;

   //! \name Funciones o métodos públicos de la clase Polinomio
   public:

	//! \name Constructores de la clase Polinomio

  inline Polinomio(){
    double coeficiente = 0.0;
    int grado = 0;
    Monomio m(coeficiente, grado);
    getMonomios().push_back(m);

    #ifndef NDEBUG
      assert(std::abs(m.getCoeficiente()-coeficiente) < COTA_ERROR);
      assert(m.getGrado() == 0);
    #endif
  }

  ed::Monomio inline Polimonio(const Polinomio &p){
    this->setMonomios(p.getMonomios());
    #ifndef NDEBUG
      assert(this->getMonomios() == p.getMonomios());
    #endif
  }

  //! \name Observadores: funciones de consulta de la clase Polinomio


  inline std::vector<Monomio> getMonomios() const {return monomios_;};

  inline void setMonomios(std::vector<Monomio> const &vectormonomios){this->monomios_ = vectormonomios;};

  inline bool esNulo(){
    Monomio primero = this->getMonomios()[0];
    if((this->getNumeroMonomios() == 1) && (std::abs(primero.getCoeficiente() < COTA_ERROR)) && (primero.getGrado() == 0))
      return true;
    else return false;
  }

  inline int getGrado(){return this->getMonomios().begin()->getGrado();}

  inline int getNumeroMonomios(){
    return getMonomios().size();
  }

  bool existeMonomio(int ngrado){
    std::vector<Monomio>::iterator begin;
    std::vector<Monomio>::iterator end;

    if(getMonomios().empty()) return false;

    for(begin = getMonomios().begin(); begin != end; begin++){
      if(begin->getGrado() == ngrado) return true;
    }

    return false;
  }


  Monomio getMonomio(int ngrado){
    std::vector<Monomio>::iterator begin;
    std::vector<Monomio>::iterator end;

    #ifndef NDEBUG
      assert(getMonomios().empty() == false );
    #endif

    for(begin = getMonomios().begin(); begin != end; begin++){
      if(begin->getGrado() == ngrado) return *begin;
    }

  }

	//! \name Funciones de modificación de la clase Polinomio

	// Función de ordenación de polinomio
  void ordenaPolinomio();
  void insertaMonomio(Monomio const &new_monomio);

 	////////////////////////////////////////////////////////////////

   //! \name Operadores de la clase Polinomio

	// COMPLETAR LOS COMENTARIOS DE DOXYGEN
	Polinomio & operator=(Polinomio const &p);

	// COMPLETAR LOS COMENTARIOS DE DOXYGEN
	Polinomio & operator=(Monomio const &m);

	// COMPLETAR LOS COMENTARIOS DE DOXYGEN
	Polinomio & operator=(double const &x);

  // Operadores aritméticos y asignación

	//Suma
	Polinomio & operator+=(Polinomio const &p);

  Polinomio & operator+=(ed::Monomio const &m);

  Polinomio & operator+=(double const &x);

  //Resta
  Polinomio & operator-=(ed::Polinomio const &p);

  Polinomio & operator-=(ed::Monomio const &m);
  
  Polinomio & operator-=(double const &x);

   //Multiplicación
  Polinomio & operator*=(ed::Polinomio const &p);

  Polinomio & operator*=(ed::Monomio const &m);
  
  Polinomio & operator*=(double const &x);

   //División
  Polinomio & operator/=(ed::Polinomio const &p);

  Polinomio & operator/=(ed::Monomio const &m);
  
  Polinomio & operator/=(double const &x);
	// COMPLETAR EL RESTO DE OPERADORES


  /////////////////////////////////////////////////////////////////////////////////////

	//! \name Funciones lectura y escritura de la clase Polinomio

	void escribirPolinomio();
  void leerPolinomio();

	///////////////////////////////////////////////////////////////////////

	//! \name Funciones auxiliares de la clase Polinomio

	// COMPLETAR


}; // Fin de la definición de la clase Polinomio




} // \brief Fin de namespace ed.

//  _getMonomios()HPP_
#endif
