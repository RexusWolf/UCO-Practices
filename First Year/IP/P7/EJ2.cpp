#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

  int digitos(string cad){

	int ndigitos=0;
	int n= cad.size();
		for(int i=0;i<n; i++){
			if((cad[i]>47) && (cad[i]<58))
				ndigitos++;
		}
	return ndigitos;
}

int main(){
	string cad;
	cout<<"Introduce una cadena"<<endl;
	getline(cin,cad);
	int n= digitos(cad);
	cout<<"Tiene "<< n << " digitos."<<endl;
	
 	cin.ignore();
	cin.get();
}
