#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

int main(){
int n, contador;

cout<<"Introduce un numero para saber sus divisores entre 2 o 3"<<endl;
cin>>n;
cout<<"Los divisores son..."<<endl;

contador=1;
while (contador<=n){
		
		if ((contador%2==0) || (contador%3==0) ){
					cout<<contador<<endl;
			}
	
		contador++;
}

	cin.ignore();
	cin.get();
}

