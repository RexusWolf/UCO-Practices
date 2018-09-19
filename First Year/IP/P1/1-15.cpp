#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

int main(){
	int dia;
	
	cout<<"Escribe un numero correspondiente a un dia de la semana"<<endl;
	cin>>dia;

	switch(dia){

		case 1: cout<<"Es lunes."<<endl;
		break;
				
		case 2: cout<<"Es martes."<<endl;
		break;

		case 3: cout<<"Es miércoles."<<endl;
		break;

		case 4: cout<< "Es jueves."<<endl;
		break;

		case 5: cout<<"Es viernes."<<endl;
		break;

		case 6: cout<< "Es sábado."<<endl;
		break;

		case 7: cout<<"Es domingo."<<endl;
		break;

		default: cout<<"El numero no se corresponde con ningun dia de la semana"<<endl;;
		}+
    system("pause");
}

