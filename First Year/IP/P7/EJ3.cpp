#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <ctype.h>
using namespace std;

  void convierte_a_mayuscula(string& cad){

	int n= cad.size();
		for(int i=0;i<n; i++){
			if( (cad[i]>96) && (cad[i]<122) )
			cad[i]=toupper(cad[i]);
		}
}

int main(){
	string cad;
	cout<<"Introduce una cadena"<<endl;
	getline(cin,cad);
	convierte_a_mayuscula(cad);
	cout<<cad<<endl;
	
 	cin.ignore();
	cin.get();
}
