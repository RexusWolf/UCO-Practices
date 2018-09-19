#include <iostream>
#include <cmath>
using namespace std;

int main(){

int num, div, contador;
cout<<"Introduce un numero para hallar sus divisores"<<endl;
cin>>num;
contador=1;

cout<<"Sus divisores son:"<<endl;
		do{
				if (num%contador==0){
				cout<<contador<<" ";

				}


				contador=contador+1;

		}while(contador!=num);




cin.ignore();
cin.get();
}