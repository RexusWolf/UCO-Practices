#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

int main(){

		int dia;
		cout<<"Introduce un numero correspondiente a un dia de la semana ";
		cin>>dia;

		if ((dia<1) || (dia>7)){
				cout<<"El número no se corresponde con un dia de la semana.";
				}
		else{

						if (dia<6){
								cout<<"Es laboral.";
								}
						else{
								cout<<"Es festivo";
								}
					}
    
	cin.ignore();
	cin.get();
}

