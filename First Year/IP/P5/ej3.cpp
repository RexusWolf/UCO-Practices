#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

void fijavaloraleatorio(float v[], int n, int& max){

	srand(time(0));
	for(int i=0;i<n;i++){
		int m=rand()%max;
		v[i]=m;
	}
}

void imprime(float v[], int n){
	cout<<"Los elementos del vector son: "<<endl;
	
	for(int i=0;i<n;i++) cout<<v[i]<<endl;
	
}

int main(){
	int n, max;
	cout<<"Introduce tamaño del vector"<<endl;
		cin>>n;
	float vector[n];

	cout<<"Introduce valor maximo de rango para elementos aleatorios"<<endl;
	cin>>max;
	
		fijavaloraleatorio(vector,n,max);
		imprime(vector,n);
   	
cin.ignore();
	cin.get();
}
