#ifndef JUGADOR_H
#define JUGADOR_H

#include <list>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include "persona.h"
using std::string;

class Apuesta {

    public:
      int tipo;
      string valor;
      int cantidad;
      friend std::ostream &operator<<(std::ostream &stream, const Apuesta &a);
      friend std::istream &operator>>(std::istream &stream, Apuesta &a);

};

class Jugador : public Persona{
    private:
      int dinero_;
      string codigo_;
      std::list<Apuesta> apuesta_;

    public:
      string getCodigo() const {return codigo_;}
      void setCodigo(const string codigo){codigo_ = codigo;}
      std::list<Apuesta> getApuestas() const {return apuesta_;}
      void setApuestas();
      int getDinero() const {return dinero_;}
      void setDinero(const int dinero){dinero_ = dinero;}
      Jugador(const string &dni, const string &codigo, const string &nombre = "",
      const string &apellidos = "", const int edad = 0, const string &direccion = "",
      const string &localidad = "", const string &provincia = "", const string &pais= ""); // Constructor
      Jugador(const Jugador &j);
      bool operator==(const Jugador &j){return (this->getDNI() == j.getDNI());}
};

#endif
