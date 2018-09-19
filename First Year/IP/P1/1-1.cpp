#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

int main(){

	float area,radio;
	cout<<"Introduzca el valor del radio"<<endl;
	cin>>radio;
	area= radio*radio*3.1415;
	cout<<"El área es "<<area<<endl;

   cin.ignore();
	cin.get();
}

