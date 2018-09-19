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
				cout<<"La raíz del numero es "<<sqrt(x);
				}
		else{
		cout<<"No se pueden calcular raíces cuadradas de números negativos.";
		}



    cin.ignore();
	cin.get();
}

