#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <ctype.h>
using namespace std;
	
string concatena(string cad1, string cad2){


	string completo=cad1+cad2;
	return completo;
}

int main(){
	string cad1, cad2;
	cout<<"Introduce una cadena"<<endl;
	getline(cin,cad1);
	
	cout<<"Introduce una cadena"<<endl;
	getline(cin,cad2);
	
	
	cout<<concatena(cad1,cad2)<<endl;
	
 	cin.ignore();
	cin.get();
}
