#include <iostream>
#include <cmath>
using namespace std;

int main(){

int num, div, contador;
cout<<"Introduce un numero natural para hallar si es primo. (El 1 no puede ser introducido)"<<endl;
cin>>num;

	if (num>0){
		if (num==2){ cout<<"El numero es primo"<<endl;}
	else{
	for (contador=num-1; contador>0; ){		

					if (num%contador==0)
					{
					cout<<"El numero no es primo. ";
					contador=0;
					}
				

					contador=contador-1;

					if (contador==1){
					cout<<"El numero es primo.";
					contador=0;
					}

					}

			} //Llave del "else"
		}
	else{
	cout<<"El numero no es natural"<<endl;
			}
		

cin.ignore();
cin.get();
}