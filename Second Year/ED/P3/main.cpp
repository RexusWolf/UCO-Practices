#include <iostream>
#include <cstdlib> //para usar srand()

#include "arbolbinarioordenadoenlazado.hpp"
#include "operadornodo.hpp"
#include "persona.hpp"
#include "generarpersona.hpp"

using namespace ed;
using namespace std;

int main()
{
  srand(time(0));
  ArbolBinarioOrdenadoEnlazado<Persona> a;
  EscribirNodo<Persona> op;
  int option;
  cout<<"Elige una opcion:"<<endl;
  cin>>option;

  cout<<"1. Insertar un número de personas en el árbol."<<endl;
  cout<<"2. Comprobar existencia de una persona en el árbol."<<endl;
  cout<<"3. Mostrar todos los elementos del árbol."<<endl;
  cout<<"4. Borrar una persona."<<endl;
  cout<<"5. Borrar el árbol completo."<<endl;

  switch(option){
    case 1:{
      int n;
      cout<<"Introduce numero de personas:"<<endl;
      cin>>n;
      while(n>0){
        Persona p = generarDatosPersonales();
        a.insertar(p);
        n--;
      }
      break;
    }
    case 2:{
      Persona persona;
      cout<<"Introduce el dni, apellido y nombre"<<endl;
      cin>>persona;
      if(a.buscar(persona)) cout<<"Encontrado."<<endl;
      else cout<<"No encontrado"<<endl;
      break;
    } 
    case 3:{
      int orden;
      cout<<"Elige el orden a mostrar:"<<endl;
      cout<<"1. PreOrden"<<endl;
      cout<<"2. InOrden"<<endl;
      cout<<"3. PostOrden"<<endl;
      cin>>orden;
      switch(orden){
        case 1: {
          a.recorridoPreOrden(op);
          break;
        }
        case 2: {
          a.recorridoInOrden(op);
          break; 
        }
        case 3: {
          a.recorridoPostOrden(op);
          break;
        }
        default:
          cout<<"Opción errónea."<<endl;
          break;
      }
      break;
    }
    case 4:{
      Persona persona;
      cout<<"Introduce el dni, apellido y nombre"<<endl;
      cin>>persona;
      if(a.buscar(persona)){
        a.borrar();
        cout<<"Encontrado y borrado."<<endl;
      }
      else cout<<"No encontrado"<<endl;
      break;
    }
    case 5:{
     a.borrarArbol();
      break;
    }
    default:{
      cout<<"Opción incorrecta."<<endl;
      break;
    }
  }
}
