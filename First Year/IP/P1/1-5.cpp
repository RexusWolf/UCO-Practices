#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

int main(){
	int num;
	cout<<"Escribe un numero ";
	cin>>num;
	
	if (num==0){
				cout<<"El número es cero.";
						}
	else{
			if (num<0){
				cout<<"Es menor que 0.";
							}
			if (num>0){
				cout<<"Es mayor que 0.";
							}
			}
 		
		cin.ignore();  
		cin.get();

}

