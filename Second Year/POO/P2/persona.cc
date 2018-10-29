
#include "persona.h"

Persona::Persona(const string &dni, const string &nombre, const string &apellidos, const int edad,
        const string &direccion, const string &localidad, const string &provincia,
        const string &pais){
  setEdad(edad);
  setDNI(dni);
  setNombre(nombre);
  setApellidos(apellidos);
  setDireccion(direccion);
  setLocalidad(localidad);
  setProvincia(provincia);
  setPais(pais);
}

bool Persona::setEdad(const int edad) {
  if (edad < 0 || edad > 120) return false;
  else {
    edad_ = edad;
    return true;
  }
}

bool Persona::mayor() const{
  if (getEdad() >= 18) return 1;
  return 0;
}
