#include "jugador.h"

void Jugador::setApuestas(){

  string namefile = getDNI() + ".txt"; // Obtenemos el nombre del fichero de texto.
  Apuesta aux;
  std::ifstream file(namefile); /* No es necesario realizar la función open, se abre
                           directamente en modo lectura si definimos el fichero
                           con ifstream. */

  apuesta_.clear(); // Borramos las apuestas existentes en la lista.

  file >> aux; // Añade la primera apuesta a la lista.
    while (!file.eof()){
      apuesta_.push_back(aux); // Añade una nueva apuesta a la lista apuesta_
      file >> aux; // Lee una apuesta.
    }
  file.close();
}

// Función para escribir apuestas en el fichero con el formato específico.
std::ostream &operator<<(std::ostream &stream, const Apuesta &a){
  stream << a.tipo<<","<<a.valor<<","<<a.cantidad<<'\n';
}

// Función para obtener datos de una apuesta del fichero.
std::istream &operator>>(std::istream &stream, Apuesta &a){
  string aux; // Creamos un string aux que nos servirá como un buffer.
  getline(stream, aux, ',');
  a.tipo = atoi(aux.c_str()); // Transformamos la string en int, quitando el /0.
  getline(stream, aux, ',');
  a.valor = aux;
  getline(stream, aux, ',');
  a.cantidad = atoi(aux.c_str());
}

Jugador::Jugador (const string &dni, const string &codigo, const string &nombre,
const string &apellidos, const int edad, const string &direccion,
const string &localidad, const string &provincia, const string &pais) :
Persona( dni, nombre, apellidos, edad, direccion, localidad, provincia, pais){
  codigo_ = codigo;
  dinero_ = 1000; // El dinero inicial será 1000.
}
