#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <limits>
using namespace std;

int main(){

	int  suma, aux, contador;
	contador=0;
	suma= 0;

	for(aux=0;aux>-1;contador++){

		cout<<"Introduce un número"<<endl;
			cin>>aux;
		if (aux>0){

				suma= suma+aux;
			
					
						}	
	}

	
		cout<<"La suma es "<<suma<<endl;
		cout<<"La media es "<<suma/contador<<endl;


	cin.ignore();
	cin.get();
}