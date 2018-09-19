#include <iostream>
#include <cmath>
using namespace std;

int main(){

int num, contador, suma;
cin>>num;

suma=0;
do{

			if (num%2!=0){
						suma=suma+num;
						
			
		}
			num=num-1;
	

}while(num!=0);

cout<<"La suma es "<<suma<<endl;



cin.ignore();
cin.get();
}