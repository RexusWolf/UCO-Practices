#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <ctype.h>
using namespace std;

int find(string cad, string cad2){
int n=cad.size();
int n2=cad2.size();
int cont=0;
for(int i=0; i<n;i++){
		if(cad[i]==cad2[cont]){
			cont++;
			if(cont==n2){return i-cont;}
		}
		else{cont=0;}
	}

return 0;


}

int main(){

	string cad;
	cout<<"Introduce una cadena"<<endl;
	getline(cin,cad);
	
	string cad2;
	cout<<"Introduce otra cadena"<<endl;
	getline(cin,cad2);
	
	int num=find(cad,cad2);

	if(num==0) cout<<"No se encuentra la cadena b en a"<<endl;
	else cout<<"Si se encuentra la cadena b en a, en la posicion "<<num+1<<"."<<endl;
 	cin.ignore();
	cin.get();
}