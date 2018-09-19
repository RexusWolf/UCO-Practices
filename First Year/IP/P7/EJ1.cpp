#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

  int espacios(string cad){

	int nveces=0;
	int n= cad.size();
		for(int i=0;i<n ; i++){
			if(cad[i]==32)
				nveces++;
		}
	return nveces;
}

int main(){
	string cad;
	cout<<"Introduce una cadena"<<endl;
	getline(cin,cad);
	int n= espacios(cad);
	cout<<"Tiene "<< n << " espacios."<<endl;
	
 	cin.ignore();
	cin.get();
}

