#include <iostream>
#include <cmath>
#include <string>
using namespace std;


struct Alumno{

	string dni;
	int edad;
	float nota;

}alumnos[10];

void inicio(){

	for(int i=0;i<10;i++){
		alumnos[i].dni='0';
		alumnos[i].edad=0;
		alumnos[i].nota=0;
		}

}

bool ninguno(){

	for(int i=0;i<10;i++){
		if(alumnos[i].edad!=0) return false;
	} 
return true;
}

void eliminando(int& i, int& nmatriculados){
	int j=i-1;	
		if( (j==nmatriculados) 	||	(j==0)){
				alumnos[j].dni='0';
				alumnos[j].edad=0;
				alumnos[j].nota=0;
			}
					
			else{
					while(j<nmatriculados){
							alumnos[j-1].dni=alumnos[j].dni;
							alumnos[j-1].edad=alumnos[j].edad;
							alumnos[j-1].nota=alumnos[j].nota;
							i++;					
					}
				alumnos[9].dni='0';
				alumnos[9].edad=0;
				alumnos[9].nota=0;
			}
					
	nmatriculados=nmatriculados-1;

}

bool vacio(int& i){
	if(alumnos[i-1].edad!=0) return false;
		
	return true;	


}
int main(){
	
	int nmatriculados=0;
	int i=0;
	for(i=0;i<10;i++){
		alumnos[i].dni='0';
		alumnos[i].edad=0;
		alumnos[i].nota=0;
		}
	int opcion_menu=0;

			do{
			system("CLS");
			cout<<" "<<endl;
			cout<<"Seleccione una opcion..."<<endl;
			cout<<" "<<endl;
			cout<<"1.Anadir alumno."<<endl;
			cout<<"2.Imprimir datos alumno."<<endl;
			cout<<"3.Imprimir datos todos los alumnos."<<endl;
			cout<<"4.Modificar alumno."<<endl;
			cout<<"5.Eliminar alumno."<<endl;
			cout<<"6.Salir."<<endl;
			cout<<" ";
			cout<<"Opcion: ";
			cin>>opcion_menu;	
			if((opcion_menu<1)	||		(opcion_menu>6)){ cout<<"Introduce una opcion valida."<<endl;
			system("pause"); return 0;}
					switch(opcion_menu){
					case 1:{
					if(nmatriculados<10){
							for(i=nmatriculados;i<nmatriculados+1;i++){
						
								cout<<"Introduzca DNI del alumno: ";
								cin>>alumnos[i].dni;
								cout<<"Introduzca edad del alumno: ";
								cin>>alumnos[i].edad;
										if((alumnos[i].edad>70) || (alumnos[i].edad<1)){ cout<<"Introduce una edad valida."<<endl;
										system("pause"); return 0;	}
								cout<<"Introduzca nota del alumno: ";
								cin>>alumnos[i].nota;
										if((alumnos[i].nota>10) || (alumnos[i].nota<0)){ cout<<"Introduce una edad valida."<<endl;
										system("pause"); return 0;	}
						}
						nmatriculados++;
						}
						else cout<<"Ha alcanzado el maximo de alumnos."<<endl;
					}break;
	
				case 2:{
						
						cout<<"Introduzca numero de alumno: ";
						cin>>i;
						if( (i>0) & (i<11) ){
	
								cout<<"DNI del alumno: "<<alumnos[i-1].dni<<endl;
					
								cout<<"Edad del alumno: "<<alumnos[i-1].edad<<endl;
							
								cout<<"Nota del alumno: "<<alumnos[i-1].nota<<endl;
						}
						else{cout<<"ERROR. Introduce un numero valido de alumno."<<endl;
						system("pause"); return 0;}
						
					}break;
				case 3:{
					if(ninguno()==true) cout<<"No hay alumnos registrados."<<endl;
					else{
							for(i=0;i<nmatriculados;i++){
								cout<<" "<<endl;
								cout<<"DNI del alumno "<<i+1<<":"<<alumnos[i].dni<<endl;
					
								cout<<"Edad del alumno "<<i+1<<":"<<alumnos[i].edad<<endl;
							
								cout<<"Nota del alumno "<<i+1<<":"<<alumnos[i].nota<<endl;
							}
						}

						}break;
				case 4:{
					int contador=0;
					char j='N';
					do{
								system("CLS");
							
									cout<<"Introduzca alumno a modificar: ";
									cin>>i;
								
								if( (i>0) & (i<11)){
	
										cout<<"Introduzca DNI del alumno: ";
										cin>>alumnos[i-1].dni;
										cout<<"Introduzca edad del alumno: ";
										cin>>alumnos[i-1].edad;
												if((alumnos[i].edad>70) || (alumnos[i].edad<1)){ cout<<"Introduce una edad valida."<<endl;
												system("pause"); return 0;	}
										cout<<"Introduzca nota del alumno: ";
										cin>>alumnos[i-1].nota;
												if((alumnos[i].nota>10) || (alumnos[i].nota<0)){ cout<<"Introduce una edad valida."<<endl;
												system("pause"); return 0;	}
								}
								else{ cout<<"ERROR. Introduce un numero valido de alumno"<<endl;
								system("pause"); return 0;	}
						
							if(contador==0){
									cout<<"Desea modificar otro alumno? Y/N: "; 
									cin>>j;
							}
							
					}while((j=='Y')||(j=='y'));
					}break;
				case 5:{
					
					int contador=0;
					char j='N';
					do{
					if(ninguno()==true){ cout<<"No hay alumnos registrados."<<endl;
					system("pause"); return 0;}
					else{
								system("CLS");
							
									cout<<"Introduzca alumno a eliminar: ";
									cin>>i;
									
											if( (i>0) & (i<11)){
												if(vacio(i)==true){cout<<"No existe alumno."<<endl;
												system("pause"); break;}
												eliminando(i, nmatriculados);
											}
																
											else{ cout<<"ERROR. Introduce un numero valido de alumno"<<endl;
											system("pause"); return 0;	}
							
											if(contador==0){
												cout<<"Desea eliminar otro alumno? Y/N: "; 
												cin>>j;
											}	
								} //Del else
						}while((j=='Y')||(j=='y'));
							
						}break;
				case 6:{
					cout<<"Goodbye... =)"<<endl;;	
					system("pause"); return 0;
					
					}break;
				}
	cout<<" "<<endl;
	cout<<"Pulse una tecla para continuar...";
	cin.ignore();
	cin.get();
}while(opcion_menu!=-1);

}