// juego.cc
// Programa que utiliza la clase Dados.

#include <iostream>
#include <cstdlib>
#include "dados.h"
using namespace std;

int main(){

  Dados d;
  int vector1[5] = {0,0,0,0,0};
  int vector2[5] = {0,0,0,0,0};
  // Realizamos primer lanzamiento para ambos dados.

  d.lanzamiento();

  cout<<"El dado 1 se ha lanzado "<<d.getLanzamientos1()<<" veces."<<endl;
  cout<<"El dado 2 se ha lanzado "<<d.getLanzamientos2()<<" veces."<<endl;
  cout<<"d1 = "<<d.getDado1()<<" "<<"d2 = "<<d.getDado2()<<" "<<endl;
  cout<<"La suma de los dos dados es "<<d.getSuma()<<endl;
  cout<<"La diferencia entre ambos es "<<d.getDiferencia()<<endl;
  cout<<"La media de valores del dado 1 es <<"<<d.getMedia1()<<endl;
  cout<<"La media de valores del dado 2 es <<"<<d.getMedia2()<<endl;
  cout<<endl;

  // Realizamos segundo lanzamiento para ambos dados.

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

  cout<<"El dado 1 se ha lanzado "<<d.getLanzamientos1()<<" veces."<<endl;
  cout<<"El dado 2 se ha lanzado "<<d.getLanzamientos2()<<" veces."<<endl;
  cout<<"La suma de los dos dados es "<<d.getSuma()<<endl;

  cout<<"La diferencia entre ambos es "<<d.getDiferencia()<<endl;

  cout<<"La media de valores del dado 1 es <<"<<d.getMedia1()<<endl;
  cout<<"La media de valores del dado 2 es <<"<<d.getMedia2()<<endl;
  cout<<endl;

  // Realizamos tercer lanzamiento, únicamente del dado 2.

  cout<<"Introduce un valor para el dado 2: ";
  cin>>n2;

  if(d.setDado2(n2)==true){
    cout<<"El valor del dado 2 es: "<<d.getDado2()<<" "<<endl;
  }
  else{
    cout<<"Este no es un valor entre 1 y 6."<<endl;
    exit(0);
  }

  cout<<"El dado 1 se ha lanzado "<<d.getLanzamientos1()<<" veces."<<endl;
  cout<<"El dado 2 se ha lanzado "<<d.getLanzamientos2()<<" veces."<<endl;
  cout<<"La suma de los dos dados es "<<d.getSuma()<<endl;

  cout<<"La diferencia entre ambos es "<<d.getDiferencia()<<endl;

  cout<<"La media de valores del dado 1 es <<"<<d.getMedia1()<<endl;
  cout<<"La media de valores del dado 2 es <<"<<d.getMedia2()<<endl;
  cout<<endl;
  d.getUltimos1(vector1);
  d.getUltimos2(vector2);
  for(int i=0;i<5;i++){
    cout<<"vector1["<<i<<"]= "<<vector1[i]<<endl;
  }
  cout<<endl;
  for(int i=0;i<5;i++){
    cout<<"vector2["<<i<<"]= "<<vector2[i]<<endl;
  }
}
