#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

bool esprimo(int v){

int contador= 1;
int ndiv= 0;
bool r=true;

	for(contador=1;contador<=v;contador++){
			
			if (v%contador==0){
				ndiv++;
			}		
	}
		
	if(ndiv>2){
		r=false;
	}
return r;
}


int main(){
int n;

	cout<<"Introduce numero"<<endl;
	cin>>n;

	if (esprimo(n)==true ){
			cout<<"El numero es primo"<<endl;
						}
	else{
		cout<<"El numero no es primo"<<endl;
			}

    cin.ignore();
	cin.get();
}

