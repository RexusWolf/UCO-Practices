#include "crupier.h"

Crupier::Crupier(const string &dni, const string &codigo,  const string &nombre, const string &apellidos, const int edad,
        const string &direccion, const string &localidad, const string &provincia,
        const string &pais):Persona(dni,nombre,apellidos, edad,
        direccion, localidad, provincia,
        pais){
          setCodigo(codigo);
        }