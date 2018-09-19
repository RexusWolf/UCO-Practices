#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <limits>
using namespace std;

int main(){

	int  suma, aux, contador;
	contador=0;
	suma= 0;
	do{
		cout<<"Introduce un número"<<endl;
			cin>>aux;
		if (aux>0){

				suma= suma+aux;
				contador++;
					
						}	
	}while (aux>0);

	
		cout<<"La suma es "<<suma<<endl;
		cout<<"La media es "<<suma/contador<<endl;


	cin.ignore();
	cin.get();
}