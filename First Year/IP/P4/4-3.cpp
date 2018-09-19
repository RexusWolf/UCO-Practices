#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

float media(int n){
float m=0;
int v, c=0, suma=0;

	cout<<"Introduce los "<<n<<" valores"<<endl;
	for(c=0; c<n;c++){
		
			cin>>v;
			suma=suma+v;
			m=suma/n;
	}
		
	
return m;
}


int main(){
int n;
float med;

	cout<<"¿Entre cuantos numeros haras la media?"<<endl;
	cin>>n;
	med= media(n);
	cout<<"La media es "<<med<<endl;

    cin.ignore();
	cin.get();
}

