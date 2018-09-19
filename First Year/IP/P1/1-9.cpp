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
if ( (a>c && b>c) || (b<c && a<c) ){
			cout<<"c no esta entre a y b"<<endl;
		}
else{

			if (a<c && c<b){
						cout<<"c esta entre a y b"<<endl;
									}
			if (b<c && c<a){
						cout<<"c esta entre b y a"<<endl;
									}
		}


    system("pause");
}

