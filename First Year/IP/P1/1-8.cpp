#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cmath>

using namespace std;

int main(){

int x0, y0, x1, y1;
int puntox, puntoy;
int sumapuntos;
float distancia;

cout<<"Introduce punto x0"<<endl;
cin>>x0;
cout<<"Introduce punto y0"<<endl;
cin>>y0;
cout<<"Introduce punto x1"<<endl;
cin>>x1;
cout<<"Introduce punto y1"<<endl;
cin>>y1;

puntox= x1-x0;
puntoy= y1-y0;

sumapuntos= pow(puntox,2)+pow(puntoy,2);
distancia= sqrt(sumapuntos);

cout<<"La distancia es "<<distancia<<".";


cin.ignore();
cin.get();


    system("pause");
}