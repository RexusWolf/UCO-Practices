// dados.cc
// Cuerpo de los métodos de la clase Dados

#include <cstdlib>
#include <ctime>
#include "dados.h"

  Dados::Dados(){
      srand(time(NULL));
      d1_ = 1;
      d2_ = 1;
      l1_ = 0; // lanzamientos d1
      l2_ = 0; // lanzamientos d2
      m1_ = 0;
      m2_ = 0;
      }

  void Dados::lanzamiento(){
    d1_ = (rand()%6)+1;
    d2_ = (rand()%6)+1;
    l1_++;
    l2_++;
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
        l1_++;
        return true;
      }
    return false;
  }

  bool Dados::setDado2(int n2){
      if(1<=n2 && n2<=6){
        d2_ = n2;
        l2_++;
        return true;
      }
    return false;
  }

  int Dados::getSuma(){
    int suma;
    suma = (d1_ + d2_);
    return suma;
  }

  int Dados::getDiferencia(){
    int dif;
    dif = (d1_ - d2_);
    return dif;
  }

  int Dados::getLanzamientos1(){
    return l1_;
  }

  int Dados::getLanzamientos2(){
    return l2_;
  }

  float Dados::getMedia1(){
    if(Dados::getLanzamientos1()==0 || Dados::getLanzamientos2()==0) return 0;
    else{
      m1_ = (m1_*(Dados::getLanzamientos1()-1)+d1_)/Dados::getLanzamientos1();
    }
    return m1_;
  }

  float Dados::getMedia2(){
    if(Dados::getLanzamientos1()==0 || Dados::getLanzamientos2()==0) return 0;
    else{
      m2_ = (m2_*(Dados::getLanzamientos1()-1)+d2_)/Dados::getLanzamientos1();
    }
    return m2_;
  }
