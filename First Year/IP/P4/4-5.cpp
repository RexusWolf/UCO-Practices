#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

void divisores(int v){
int c;
	for (c=1; c<=v; c++){
			if (v%c==0){
				cout<<c<<endl;
			}
	}

}


int main(){
	int n;
		cout<<"Introduce un numero para calcular sus divisores: "<<endl;
		cin>>n;
		divisores(n);
    cin.ignore();
	cin.get();
}

