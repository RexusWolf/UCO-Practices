#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <limits>
using namespace std;

int main(){

	int n, contador, mayor, menor, aux;
	
	
	mayor= std::numeric_limits<int>::min();
	menor=  std::numeric_limits<int>::max();
	
		
			for(contador=0;contador<5;contador++){
			
				cout<<"Introduce un número"<<endl;
					cin>>aux;
				if (aux>0){

						if(aux>mayor){
								mayor = aux;
									}

						if(aux < menor){
								menor = aux;
									}

								}	
				
				}

		cout<<"El menor es "<<menor<<endl;
		cout<<"El mayor es "<<mayor<<endl;
		cout<<"La suma es "<<mayor+menor<<endl;



	cin.ignore();
	cin.get();
}