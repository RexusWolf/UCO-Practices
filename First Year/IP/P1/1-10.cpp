#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

int main(){

float a,b,c;
cout<<"Introduce valores de a,b y c en ese orden"<<endl;
cin>>a;
cin>>b;
cin>>c;
if ( a<c && c>b ){
			cout<<"El mayor es "<<c<<endl;
		}
else{

			if (a<c && c<b){
						cout<<"El mayor es "<<b<<endl;
									}
			if (b<c && c<a){
						cout<<"El mayor es "<<a<<endl;
									}
		}

cin.ignore();
cin.get();

    system("pause");
}