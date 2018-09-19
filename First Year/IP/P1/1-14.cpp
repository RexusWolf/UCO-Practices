#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

int main(){

		int a, b, c;

		cout<<"Introduce dos números"<<endl;

		cin>>a;
		cin>>b;
		c=0;
		if (a>b){
			c=a;
			a=b;
			b=c;
			}
		
		cout<<"a es igual a "<< a <<" y b es igual a "<<b<<endl;
    system("pause");
}

