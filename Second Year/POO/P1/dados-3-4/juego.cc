// juego.cc
// Programa que utiliza la clase Dados.

#include <iostream>
#include <cstdlib>
#include "dados.h"
using namespace std;

int main(){

  Dados d;
  d.lanzamiento();
  cout<<"d1 = "<<d.getDado1()<<" "<<"d2 = "<<d.getDado2()<<" "<<endl;
  cout<<"La suma de los dos dados es "<<d.getSuma()<<endl;
  cout<<"La diferencia entre ambos es "<<d.getDiferencia()<<endl;

  int n1, n2;
  cout<<"Introduce un valor para el dado 1: ";
  cin>>n1;

  if(d.setDado1(n1)==true){
    cout<<"El valor del dado 1 es: "<<d.getDado1()<<" "<<endl;
  }
  else{
    cout<<"Este no es un valor entre 1 y 6."<<endl;
    exit(0);
  }
  
  cout<<"Introduce un valor para el dado 2: ";
  cin>>n2;


  if(d.setDado2(n2)==true){
    cout<<"El valor del dado 2 es: "<<d.getDado2()<<" "<<endl;
  }
  else{
    cout<<"Este no es un valor entre 1 y 6."<<endl;
    exit(0);
  }

  cout<<"La suma de los dos dados es "<<d.getSuma()<<endl;

  cout<<"La diferencia entre ambos es "<<d.getDiferencia()<<endl;
}
