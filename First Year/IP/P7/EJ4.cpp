#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <ctype.h>
using namespace std;

 int vocales(string& cad){
	int nveces=0;
	int n= cad.size();

		for(int i=0;i<n; i++){
			if( (cad[i]>96) && (cad[i]<122) )
			cad[i]=toupper(cad[i]);
		}

		for(int i=0;i<n; i++){
			if( (cad[i]=='A') || (cad[i]=='E') || (cad[i]=='I') || (cad[i]=='O') || (cad[i]=='U') ) 
			 nveces++;
		}
	return nveces;
}

int main(){
	string cad;
	cout<<"Introduce una cadena"<<endl;
	getline(cin,cad);
	int n=vocales(cad);
	cout<<"Tiene "<<n<< " vocales. "<<endl;
	
 	cin.ignore();
	cin.get();
}
