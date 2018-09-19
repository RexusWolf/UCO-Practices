#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <limits>
using namespace std;

int main(){

	int  mayor, aux;
	
	
	mayor= std::numeric_limits<int>::min();
	for(aux=0;aux>-1; ){
	
		cout<<"Introduce un número"<<endl;
			cin>>aux;
		if (aux>=0){

				if(aux>mayor){
						mayor = aux;
							}


						}	
	}

		cout<<"El mayor es "<<mayor<<endl;



	cin.ignore();
	cin.get();
}