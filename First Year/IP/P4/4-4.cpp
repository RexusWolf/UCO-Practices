#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

int factorial(int v){
int fact=1,c;

	for(c=v; c>=1;c=c-1){
		
			fact=fact*c;
	}
		
	
return fact;
}


int main(){
int n;
int f;

	cout<<"¿De que numero quieres calcular el factorial?"<<endl;
	cin>>n;
	f= factorial(n);
	cout<<"El factorial es "<<f<<endl;

    cin.ignore();
	cin.get();
}
