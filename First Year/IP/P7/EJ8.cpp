#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <ctype.h>
using namespace std;

int stoi(const string &cad){
	int v;
	sscanf(cad.c_str(), "%i", &v);
	return v;
}

int main(){

	string cad;
	cout<<"Introduce un dni"<<endl;
	getline(cin,cad);
	
	int tam=cad.size();
	
	if(tam==9){
		cout<<"El número de caracteres del DNI es correcto"<<endl;
			int n=std::stoi(cad);	
			char vectorletras[]="TRWAGMYFPDXBNJZSQVHLCKE";
			char letra=vectorletras[n%23];
			if(cad[8]==letra) cout<<"Es correcto."<<endl;
			else{
				cout<<"La letra "<<cad[8]<<" no es correcta"<<endl;
				cad[8]= letra;
			}
			cout<<"El dni corregido seria "<<cad<<"."<<endl;
	}
	else cout<<"El numero de caracteres del DNI no es correcto."<<endl;
	
 	cin.ignore();
	cin.get();
}