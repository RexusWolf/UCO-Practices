#include "ruleta.h"

Ruleta::Ruleta (Crupier &c) : crupier_ (c){
  bola_ = -1;
  banca_ = 1000000;

}

bool setBanca(const int banca){
  if(banca<0) return false;
  return true;
}

bool setBola(const int bola){
  if(bola<0 || bola>36) return false;
  return true;
}

bool addJugador(Jugador &j){

}

int deleteJugador(int j.dni){


}

int deleteJugador(Jugador &j){


}

void escribeJugadores(){


}

void leeJugadores(){


}

void giraRuleta(){


}

void getPremios(){


}
