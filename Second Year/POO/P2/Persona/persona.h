//persona.h
#ifndef PERSONA_H
#define PERSONA_H

#include <string>
#include <cstdlib>
using std::string;

class Persona{
  private:
    string dni_;
    string nombre_;
    string apellidos_;
    int edad_;
    string direccion_;
    string localidad_;
    string provincia_;
    string pais_;

  public:
    string getDNI() const {return dni_;}
    void setDNI(const string &cad){ dni_ = cad;}
    int getEdad() const { return edad_;}
    bool setEdad(const int edad);
    string getNombre() const { return nombre_;}
    void setNombre(const string &cad){ nombre_ = cad; }
    string getApellidos() const { return apellidos_;}
    void setApellidos(const string &cad){ apellidos_ = cad;}
    string getLocalidad() const { return localidad_;}
    void setLocalidad(const string &cad){ localidad_ = cad;}
    string getProvincia() const { return provincia_;}
    void setProvincia(const string &cad){ provincia_ = cad;}
    string getPais() const { return pais_;}
    void setPais(const string &cad){ pais_ = cad;}
    string getDireccion() const { return direccion_;}
    void setDireccion(const string &cad){ direccion_ = cad;}
    string getApellidosyNombre() const {return getApellidos() + ", " + getNombre();}
    bool mayor() const;
    Persona(const string &dni, const string &nombre = "", const string &apellidos = "", const int Edad = 0,
            const string &direccion = "", const string &localidad = "", const string &provincia = "",
            const string &pais = ""); // Constructor

};

#endif
