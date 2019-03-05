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

// Para usar la función abs
#include <cmath>

#include "PolinomioInterfaz.hpp"
#include "Monomio.hpp"
#include <list>


// Se incluye la clase Polinomio dentro del espacio de nombre de la asigantura: ed
namespace ed {

//!  Definición de la clase Polinomio que hereda de PolinomioInterfaz
class Polinomio: public ed::PolinomioInterfaz
{

  //! \name Atributos privados de la clase Polinomio

   private:
     std::list<Monomio> polinomio_;

   //! \name Funciones o métodos públicos de la clase Polinomio
   public:

	//! \name Constructores de la clase Polinomio

  inline Polinomio(){
    double coeficiente = 0.0;
    int grado = 0;
    Monomio(coeficiente, grado);

    #ifndef NDEBUG
      assert(std::abs(this->getCoeficiente()-coeficiente) < COTA_ERROR);
      assert(if(this->getGrado() == 0));
    #endif
  }

  inline Polimonio(const Polinomio &p){
    double coeficiente = p.getCoeficiente();
    int grado = p.getGrado();
    Monomio(coeficiente, grado);

    #ifndef NDEBUG
      assert(std::abs(this->getCoeficiente()-coeficiente) < COTA_ERROR);
      assert(if(this->getGrado() == 0));
    #endif
  }

  //! \name Observadores: funciones de consulta de la clase Polinomio

	inline bool esNulo(){
    if(this->getGrado() == 0 && this->getCoeficiente() < COTA_ERROR)
    return true;
    else return false;
  }

  inline int getGrado(){return grado_;}

  inline int getNumeroMonomios(){
    return polinomio_.size();
  }

  bool existeMonomio(int ngrado){
    std::list<Monomio>::iterator begin;
    std::list<Monomio>::iterator end;

    if(polinomio_.empty()) return false;

    for(begin = polinomio_.begin(); begin != end; begin++){
      if(begin.getGrado() == ngrado) return true;
    }

    return false;
  }


	//! \name Funciones de modificación de la clase Polinomio

	// COMPLETAR


 	////////////////////////////////////////////////////////////////

   //! \name Operadores de la clase Polinomio

	// COMPLETAR LOS COMENTARIOS DE DOXYGEN
	Polinomio & operator=(Polinomio const &p);

	// COMPLETAR LOS COMENTARIOS DE DOXYGEN
	Polinomio & operator=(Monomio const &m);

	// COMPLETAR LOS COMENTARIOS DE DOXYGEN
	Polinomio & operator=(double const &x);

  // Operadores aritméticos y asignación

		// COMPLETAR LOS COMENTARIOS DE DOXYGEN
	Polinomio & operator+=(Polinomio const &p);


	// COMPLETAR EL RESTO DE OPERADORES


  /////////////////////////////////////////////////////////////////////////////////////

	//! \name Funciones lectura y escritura de la clase Polinomio

	// COMPLETAR


	///////////////////////////////////////////////////////////////////////

	//! \name Funciones auxiliares de la clase Polinomio

	// COMPLETAR


}; // Fin de la definición de la clase Polinomio




} // \brief Fin de namespace ed.

//  _POLINOMIO_HPP_
#endif
