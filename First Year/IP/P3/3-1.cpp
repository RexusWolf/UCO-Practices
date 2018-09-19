#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <limits>
using namespace std;

int main(){

	int n, menor, contador;
	menor=std::numeric_limits<int>::max();
	contador=0;
	while (contador<5){
	cout<<"Introduce un numero"<<endl;
	cin>>n;
					if(n<menor){
					
						menor=n;
					}
	contador++;
	}
	
	cout<<"El menor de los 5 es "<<menor<<endl;




	cin.ignore();
	cin.get();
}

