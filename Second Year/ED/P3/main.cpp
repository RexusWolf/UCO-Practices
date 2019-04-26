#include <iostream>
#include <cstdlib>
#include <unistd.h>

#include "arbolbinarioordenadoenlazado.hpp"
#include "operadornodo.hpp"
#include "persona.hpp"
#include "generarpersona.hpp"

#include "macros.hpp"

using namespace ed;
using namespace std;

int main()
{
  system("clear");
  srand(time(0));
  ArbolBinarioOrdenadoEnlazado<Persona> a;
  EscribirNodo<Persona> op;
  int i, n, option;

  cout << BIBLUE << "Bienvenido al test de la Práctica 3 de ED";
  cout << RESET <<'\n';
  cout<<"Introduce numero de personas a insertar:\n"<< RESET;
  cin>>n;
  for(i = 0; i < n; i++){
    a.insertar(generarDatosPersonales());
  }
  cout << GREEN << "Personas insertadas. Iniciando programa...\n";
  sleep(2);
  system("clear");

  while(option != 0){
    system("clear");
    cout<< BIGREEN <<"Elige una opcion:\n"<< RESET;
    cout<<"1. Insertar más personas en el árbol.\n";
    cout<<"2. Comprobar existencia de una persona en el árbol.\n";
    cout<<"3. Mostrar todos los elementos del árbol.\n";
    cout<<"4. Borrar una persona.\n";
    cout<<"5. Borrar el árbol completo.\n";
    cout << "0. Salir\n" << RESET;

    cin>>option;
    switch(option){

      // INSERCIÓN DE PERSONAS EN EL ÁRBOL
      case 1:{
        system("clear");
        cout<< IBLUE <<"Introduce un numero de personas a insertar:"<< RESET;
        cin>>n;
        for(i = 0; i < n; i++){
          a.insertar(generarDatosPersonales());
        }
        cout << GREEN <<"Personas insertadas satisfactoriamente\n";
        cout << GREEN << "Espere...\n";
        sleep(2);
      }break;

      // BÚSQUEDA DE PERSONA EN EL ÁRBOL
      case 2:{
        system("clear");
        if(! a.estaVacio()){
          Persona persona;
          int pdni;
          cout<< BIPURPLE <<"Introduce el dni de la persona que buscas:\n";
          cin>>pdni;
          persona.dni(pdni);
          if(a.buscar(persona))
            cout<< ICYAN << a.actual() << "\n" << RESET;
          else
            cout<< IRED <<"Persona no encontrada\n" << RESET;
        }
        else{
          cout << RED << "ERROR! Árbol vacío\n" << RESET;
        }
        cout << WHITE << "\nPulse [ENTER] para continuar\n";
        cin.ignore();
        cin.get();
        system("clear");
      }break;

      // MOSTRADO DE ÁRBOL
      case 3:{
        system("clear");
        if(a.estaVacio()){
          cout<< BIRED <<"ERROR!! El árbol está vacío\n"<< RESET;
          cout<< GREEN << "Espere...\n";
          sleep(2);
          break;
        }
        else{
          int orden;
          cout<< BIGREEN <<"Elige el orden a mostrar:\n" << RESET;
          cout<< YELLOW <<"1. PreOrden\n";
          cout<< BLUE <<"2. InOrden\n";
          cout<< CYAN <<"3. PostOrden\n";
          cin>>orden;
          switch(orden){
            case 1:
              system("clear");
              cout << GREEN << "RESULTADO DE LA BÚSQUEDA:\n";
              cout << YELLOW << "\n";
              a.recorridoPreOrden(op);
              break;

            case 2:
              system("clear");
              cout << GREEN << "RESULTADO DE LA BÚSQUEDA:\n";
              cout << BLUE << "\n";
              a.recorridoInOrden(op);
              break;

            case 3:
              system("clear");
              cout << GREEN << "RESULTADO DE LA BÚSQUEDA:\n";
              cout << CYAN << "\n";
              a.recorridoPostOrden(op);
              break;
            
            default:
              cout<<"Opción errónea.\n";
              cout<< GREEN << "Espere...\n";
              sleep(1);
              break;
          }
        }
        cout << WHITE << "\nPulse [ENTER] para continuar\n";
        cin.ignore();
        cin.get();
        system("clear");
      }break;

      // BORRADO DE UNA PERSONA EN EL ÁRBOL
      case 4:{
        system("clear");
        if(! a.estaVacio()){
          Persona persona;
          cout<<"Introduce los datos de la persona\n"<< RESET;
          cin>>persona;
          if(a.buscar(persona)){
            if(a.borrar()){
            cout<< GREEN <<"Borrado satisfactoriamente.\n";
            }
            else{
              cout<< RED << "ERROR AL BORRAR!\n";
              cout << RESET;
            }
          }
          else{
            cout<< RED <<"ERROR! Persona no encontrada\n" << RESET;
          }
        }
        else{
          cout<< RED <<"ERROR! Persona no encontrada\n" << RESET;
        }
        cout<< GREEN << "Espere...\n";
        sleep(2);
      }break;

      // BORRADO DEL ÁRBOL
      case 5:{
        system("clear");
        if(!a.estaVacio()){
          a.borrarArbol();
          cout << GREEN << "Borrado satisfactorio\n";
        }
        else{ cout << RED << "ERROR. Árbol vacío\n" << RESET;}
        cout<< GREEN << "Espere...\n";
        sleep(2);
      }break;

      case 0:{
        cout << BICYAN << "Saliendo...\n" << RESET;
        sleep(1);
      }break;

      default:{
        cout<< RED <<"Opción incorrecta.\n" << RESET;
        cout<< GREEN << "Reiniciando...\n";
        sleep(1);
        break;
      }

      if (option != 0){
      cout << "Pulse [ENTER] para continuar\n";
      cin.ignore();
      cin.get();
      system("clear");
      }
    }
  }
}
