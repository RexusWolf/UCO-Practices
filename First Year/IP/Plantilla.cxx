#include <iostream>
#include <cmath>
#using namespace std;

int main(){

int num, sumanum, contador, media;
cout<<"Introduce tantos números como quieras (Para dejar de calcular la media introduce 0)."<<endl;

sumanum=0;
contador=0;
do{

cin>>num;
sumanum=num+sumanum;
contador= contador+1;
media=sumanum/contador;

cout<<"La media entre "<<contador<<" números es "<<media<<endl;
}while(n!=0)




cin.ignore();
cin.get();
}