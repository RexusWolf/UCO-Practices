#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

int main(){

int n, sum, contador, sumt, total;

cout<<"¿Cuantos numeros de la serie de Fibonacci quieres mostrar?"<<endl;
cin>>n;

contador=0;
sum=0;
sumt=1;
while (contador<n){

total=sum+sumt;	//El total será el número correspondiente en la serie de Fibonacci.
sum=sumt;		//Echa el valor de sumt (que se ha sumado a sum con anterioridad) a sum, que se sumará en la siguiente repetición del buble.
sumt=total;		//Iguala la suma anterior a sumt, que será lo que se sumará con sum en cada repetición de bucle.

cout<<sumt<<endl;
contador++;
}


    cin.ignore();
	cin.get();
}

