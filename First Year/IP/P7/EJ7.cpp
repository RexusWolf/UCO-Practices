#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <ctype.h>
using namespace std;

bool palindromo(string cad){
	int n=cad.size();
	for(int i=0;i<n/2;i++){
		if(cad[i]!=cad[n-1-i]) return false;
	}
return true;

}

int main(){

	string cad;
	cout<<"Introduce cadena"<<endl;
	getline(cin,cad);
	
	if(palindromo(cad)){
		cout<<"Es un palindromo"<<endl;
	}
	else cout<<"No es un palindromo"<<endl;


 	cin.ignore();
	cin.get();
}