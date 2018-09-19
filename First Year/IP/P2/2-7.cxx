#include <iostream>
#include <cmath>
using namespace std;

int main(){

int num, div, contador;
cout<<"Introduce un numero para hallar si es primo."<<endl;
cin>>num;
contador=num-1;

		do{
				if (num%contador==0)
				{
				cout<<"El número no es primo. ";
				contador=0;
				}
				

				contador=contador-1;

				if (contador==1){
				cout<<"El número es primo.";
				contador=0;
				}

		}while(contador>0);

		
		

cin.ignore();
cin.get();
}