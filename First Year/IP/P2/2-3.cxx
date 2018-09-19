#include <iostream>

using namespace std;

int main(){

int fact, n;
cout<<"Introduzca un numero para calcular su factorial"<<endl;
cin>>n;
fact=1;
while(n>=1){

	fact=fact*n;
	n=n-1;


}

cout<<"El factorial es "<<fact<<endl;

cin.ignore();
cin.get();
}