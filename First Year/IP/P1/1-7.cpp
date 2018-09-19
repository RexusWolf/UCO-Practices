#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

int main(){

float nota, prac, parc, fin;

cout<<"Introduce nota de practica"<<endl;
cin>>prac;
cout<<"Introduce nota de parcial"<<endl;
cin>>parc;
cout<<"Introuce nota examen final"<<endl;
cin>>fin;

nota=prac*0.25+parc*0.25+fin*0.5;
cout<<"La nota es "<<nota<<".";


cin.ignore();
cin.get();


    system("pause");
}
