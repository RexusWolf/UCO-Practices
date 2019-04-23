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
  int i, n, option;


  cout<<"Introduce numero de personas a insertar:"<<endl;
  cin>>n;
  for(i = 0; i < n; i++){
    a.insertar(generarDatosPersonales());
  }

  cout<<"Elige una opcion: "<<endl;
  cout<<"1. Insertar más personas en el árbol."<<endl;
  cout<<"2. Comprobar existencia de una persona en el árbol."<<endl;
  cout<<"3. Mostrar todos los elementos del árbol."<<endl;
  cout<<"4. Borrar una persona."<<endl;
  cout<<"5. Borrar el árbol completo."<<endl;

  cin>>option;
  switch(option){

    // INSERCIÓN DE PERSONAS EN EL ÁRBOL
    case 1:{
      cout<<"Introduce numero de personas:"<<endl;
      cin>>n;
      for(i = 0; i < n; i++){
        a.insertar(generarDatosPersonales());
      }
    }break;

    // BÚSQUEDA DE PERSONA EN EL ÁRBOL
    case 2:{
      Persona persona;
      cout<<"Introduce el dni, apellido y nombre"<<endl;
      cin>>persona;
      if(a.buscar(persona)) cout<< a.actual() <<endl;
      else cout<<"Persona no encontrada"<<endl;
    }break;

    // MOSTRADO DE ÁRBOL
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
        }break;

        case 2: {
          a.recorridoInOrden(op);
        }break;

        case 3: {
          a.recorridoPostOrden(op);
        }break;
        
        default:
          cout<<"Opción errónea."<<endl;
          break;
      }
    }break;

    // BORRADO DE UNA PERSONA EN EL ÁRBOL
    case 4:{
      Persona persona;
      cout<<"Introduce el dni, apellido y nombre"<<endl;
      cin>>persona;
      if(a.buscar(persona)){
        if(a.borrar()){
        cout<<"Borrado satisfactoriamente."<<endl;
        }
      }
      else cout<<"Fallo al borrar!"<<endl;
    }break;

    // BORRADO DEL ÁRBOL
    case 5:{
     a.borrarArbol();
    }break;
    default:{
      cout<<"Opción incorrecta."<<endl;
      break;
    }
  }
}
