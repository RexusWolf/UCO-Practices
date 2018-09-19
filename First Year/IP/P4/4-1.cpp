#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

bool espar(int v){

bool res;
res=false;
	if (v%2==0){
		res=true;
	}

return res;

}

int main(){

int n;
	cout<<"Introduzca un numero para saber si es par"<<endl;
	cin>>n;
	
	if (espar(n)==true){
			cout<<"Es par"<<endl;
	}

	else{
			cout<<"No es par"<<endl;
	}

    cin.ignore();
	cin.get();
}

