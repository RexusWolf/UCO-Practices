#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

int main(){

		float angulo,rad;

		cout<<"Introduce un angulo en grados y se devolvera el valor en radianes"<<endl;
		cin>>angulo;
		rad= (angulo*3.1415)/180;
		cout<<"Su valor en radianes es "<<rad<<endl;

		cin.ignore();
		cin.get();
}

