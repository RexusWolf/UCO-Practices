#include "ruleta.h"

Ruleta::Ruleta (Crupier &c) : crupier_ (c){
  bola_ = -1;
  banca_ = 1000000;

}

bool Ruleta::setBanca(const int banca){
  if(banca<0) return false;
  banca_ = banca;
  return true;
}

bool Ruleta::setBola(const int bola){
  if(bola<0 || bola>36) return false;
  bola_ = bola;
  return true;
}

bool addJugador(const Jugador &j){
  if(find(jugadores_.begin(), jugadores_.end(), j) != jugadores.end()){
    return false;
  }
  else{
    jugadores_.push_back(j); // Añadiremos el jugador al final de la lista.
    std::ifstream f;
    f.open(j.getDNI()+"txt", std::ios::app); // Creamos el fichero del jugador
    f.close();                              // si no existe.
    return true;
  }

}

int Ruleta::deleteJugador(const string dni){
  list<Jugador>::iterador itpos;
  list<Jugador>::iterador ptr;
  bool exists = false;

  if(jugadores_.empty()){
    return -1; // Lista vacía.
  }
  for (itpos = jugadores_.begin(); itpos = jugadores_.end(); ++it){
    if(itpos->getDNI() == dni){ // Obtendremos el DNI de cada jugador en la lista.
      exists = true;
      ptr = itpos;
    }
  }
  if(exists){
    jugadores_.erase(); // Jugador encontrado y borrado de la lista.
    return 1;
  }
  else{
    return -2; // Jugador no encontrado.
  }

}

int Ruleta::deleteJugador(const Jugador& j){
  list<Jugador>::iterator itpos; // Creamos un iterador que nos indicará la posición
                                // del elemento que borraremos en caso de existir.
  if(jugadores_.empty()){
    return -1; // La lista está vacía.
  }
  else if( (itpost = find(jugadores_.begin(),jugadores_.end(), j)) == jugadores_.end()  ){
    return -2; // El jugador no existe, ya que el iterador es igual al final de la lista.
  }
  else{
    jugadores_.erase(itpost); // Borraremos el elemento en la posición del iterador.
    return 1;
  }

}

void Ruleta::escribeJugadores(){
  std::ofstream f;
  f.open("jugadores.txt", std:ios::out); // Abrimos el fichero en modo escritura.
  list<Jugador>::iterator itpos;
  for(itpos = jugadores_.begin(); itpos != jugadores_.end(); ++it){
    f << (*itpos) << '\n' // Escribe en el fichero todo el elemento al que apunta it.
  }
  f.close();

}

void Ruleta::leeJugadores(){
  std::ifstream f("jugadores.txt"); // Abrimos fichero en modo lectura.
  Jugador jaux("","");  // Creamos un objeto auxiliar.
  list<Jugador> aux;   // Creamos una lista Jugador auxiliar.
  f >> aux;           // Comenzamos el bucle que recorre el fichero e irá
  while(!f.eof()){   // escribiendo los jugadores en la lista, elemento a elem.
    aux.push_back(jaux);
    f >> aux;
  }
  f.close();
  jugadores_ = aux;   // Igualamos la lista auxiliar creada a la de la clase.
}

void giraRuleta(){


}

void getPremios(){


}
