#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

int main(){

int n, sum, contador, sumt, total;

cout<<"�Cuantos numeros de la serie de Fibonacci quieres mostrar?"<<endl;
cin>>n;

contador=0;
sum=0;
sumt=1;
while (contador<n){

total=sum+sumt;	//El total ser� el n�mero correspondiente en la serie de Fibonacci.
sum=sumt;		//Echa el valor de sumt (que se ha sumado a sum con anterioridad) a sum, que se sumar� en la siguiente repetici�n del buble.
sumt=total;		//Iguala la suma anterior a sumt, que ser� lo que se sumar� con sum en cada repetici�n de bucle.

cout<<sumt<<endl;
contador++;
}


    cin.ignore();
	cin.get();
}

