#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

int main(){

	int dinero, b500, b200, b100, b50, b20, b10, b5;

	cout<<"Introduzca una cantidad de dinero"<<endl;
	cin>>dinero;

	b500= dinero/500;
	dinero= dinero%500;

	b200= dinero/200;
	dinero=dinero%200;

	b100= dinero/100;
	dinero=dinero%100;

	b50= dinero/50;
	dinero=dinero%50;

	b20= dinero/20;
	dinero= dinero%20;

	b10 = dinero/10;
	dinero = dinero%10;
	
	cout<<"Resultan..."<<endl;
	cout<<b500<<" billetes de 500."<<endl;
	cout<<b200<<" billetes de 200."<<endl;
	cout<<b100<<" billetes de 100."<<endl;
	cout<<b50<<" billetes de 50."<<endl;
	cout<<b20<<" billetes de 20."<<endl;
	cout<<b10<<" billetes de 10."<<endl;
	cout<<dinero<<" euros "<<endl;

    system("pause");
}

