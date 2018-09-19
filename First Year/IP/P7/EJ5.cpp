#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <ctype.h>
using namespace std;
	
void replace(string &cad, char a, char b){

	int n= cad.size();

		for(int i=0;i<n; i++){
			if(cad[i]==a) cad[i]=b;
		}
	
}

int main(){
	string cad;
	char a,b;
	cout<<"Introduce una cadena"<<endl;
	getline(cin,cad);
	cout<<"Que valor quieres reemplazar?"<<endl;
	cin>>a;
	b = toupper(a);
	replace(cad,a, b);
	cout<<cad<<endl;
	
 	cin.ignore();
	cin.get();
}
