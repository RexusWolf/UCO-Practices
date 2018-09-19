#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

int main(){

	int mes;
	
	cout<<"Escribe un numero correspondiente a un mes"<<endl;
	cin>>mes;

	switch(mes){

		case 1: cout<<"El mes tiene 31 días"<<endl;
		break;
				
		case 2: cout<<"El mes tiene 28 días"<<endl;
		break;

		case 3: cout<<"El mes tiene 31 días"<<endl;
		break;

		case 4: cout<< "El mes tiene 30 días"<<endl;
		break;

		case 5: cout<<"El mes tiene 31 días"<<endl;
		break;

		case 6: cout<< "El mes tiene 30 días"<<endl;
		break;

		case 7: cout<<"El mes tiene 31 días"<<endl;
		break;

		case 8: cout<<"El mes tiene 31 días"<<endl;
		break;

		case 9: cout<< "El mes tiene 30 días"<<endl;
		break;

		case 10: cout<<"El mes tiene 31 días"<<endl;
		break;

		case 11: cout<< "El mes tiene 30 días"<<endl;
		break;

		case 12: cout<<"El mes tiene 31 días"<<endl;
		break;

		default: cout<<"El número no corresponde con un mes"<<endl;
		}

		cin.ignore();
		cin.get();
    system("pause");
}

