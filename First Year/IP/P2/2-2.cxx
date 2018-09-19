#include <iostream>
#include <cmath>
using namespace std;

int main(){

int contador, serie, n;
cout<<"Introduzca un numero n perteneciente a la serie 1, 2, 3, ... n"<<endl;
cin>>n;
contador=n;
serie=0;
do{
serie=serie+contador;


contador=contador-1;
}while(contador!=0);

cout<<"El resultado de la serie es "<<serie<<endl;

cin.ignore();
cin.get();
}