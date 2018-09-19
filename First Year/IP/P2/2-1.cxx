#include <iostream>
#include <cmath>
using namespace std;

int main(){

int num, sumanum, contador, totalvalores;
float media;
cout<<"¿De cuantos valores quieres hacer la media?"<<endl;
cin>>contador;
cout<<"Introduce esos "<<contador<<" valores."<<endl;
totalvalores= contador;
sumanum=0;

do{

cin>>num;

sumanum=num+sumanum;
media=sumanum/totalvalores;
contador= contador-1;

}while(contador!=0);


cout<<"La media entre "<<totalvalores<<" números es "<<media<<endl;

int b;
cin>>b;
cin.ignore();
cin.get();

}