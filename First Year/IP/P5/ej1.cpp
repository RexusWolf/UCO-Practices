#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

void lee(float v[], int n){
	int m,i;
	for(i=0;i<n;i++){
		cout<<"Introduce un valor para el elemento numero "<<i<<"."<<endl;
			cin>>m;
		v[i]=m;
	}
}

void imprime(float v[], int n){
	cout<<"Los elementos del vector son: "<<endl;
	
	for(int i=0;i<n;i++) cout<<v[i]<<endl;
	
}

int main(){
	int n;
	cout<<"Introduce tamaño del vector"<<endl;
		cin>>n;
	float vector[n];

	lee(vector,n);
	imprime(vector,n);

   	cin.ignore();
	cin.get();
}

