// dados.cc
// Cuerpo de los métodos de la clase Dados

#include <cstdlib>
#include <ctime>
#include "dados.h"

  Dados::Dados(){
      srand(time(NULL));
      d1_ = 1;
      d2_ = 1;
  }

  void Dados::lanzamiento(){
    d1_ = (rand()%6)+1;
    d2_ = (rand()%6)+1;
  }

  int Dados::getDado1(){
    return d1_;
  }

  int Dados::getDado2(){
    return d2_;
  }

  bool Dados::setDado1(int n1){
      if(1<=n1 && n1<=6){
        d1_ = n1;
        return true;
      }
    return false;
  }

  bool Dados::setDado2(int n2){
      if(1<=n2 && n2<=6){
        d2_ = n2;
        return true;
      }
    return false;
  }

  int Dados::getSuma(){
    int suma;
    suma = (d1_ + d2_);
    return suma;
  }
