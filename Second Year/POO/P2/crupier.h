//crupier.h

#ifndef CRUPIER_H
#define CRUPIER_H

#include <string>
#include "persona.h"
using std::string;



class Crupier : public Persona{
  private:
    string codigo_;
  public:
    Crupier(const string &dni, const string &codigo, const string &nombre = "",
    const string &apellidos = "", const int edad = 0, const string &direccion = "",
const string &localidad = "", const string &provincia = "", const string &pais= "");
    string getCodigo() const { return codigo_;}
    void setCodigo(const string codigo){ codigo_ = codigo;}
};


#endif