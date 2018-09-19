#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

bool esprimo(int v){

int c= 1;
int ndiv= 0;
bool r=true;

	for(c=1;c<=v;c++){
			
			if (v%c==0){
				ndiv++;
			}		
	}
		
	if(ndiv>2){
		r=false;
	}

	return r;
}

void primos(int n){
int c=0, num=1;
	while(c<n){

		if (esprimo(num)){
				cout<<num<<endl;
				c++;
			}
		num++;
	}

}

int main(){
	int n;
		cout<<"Introduce un numero para ver los n primeros numeros primos: "<<endl;
		cin>>n;
		primos(n);
    cin.ignore();
	cin.get();
}
