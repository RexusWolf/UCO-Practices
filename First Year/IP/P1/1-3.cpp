#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cmath>

using namespace std;

int main(){

		float x;
		cout<<"Introduzca un numero: ";
		cin>>x;

		if (x>=0){
				cout<<"La ra�z del numero es "<<sqrt(x);
				}
		else{
		cout<<"No se pueden calcular ra�ces cuadradas de n�meros negativos.";
		}



    cin.ignore();
	cin.get();
}

