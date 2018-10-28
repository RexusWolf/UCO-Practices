#include <string>
#include <cstdlib>
#include "persona.h"
using std::string

Persona::Persona(int &age, string &dni, string &name,
                  string &surname, string &address,
                  string &city, string &province,
                  string &country){
  setAge(age);
  setDNI(dni);
  setName(name);
  setSurname(surname);
  setAddress(address);
  setCity(city);
  setProvince(province);
  setCountry(country);
}

bool Persona::setAge(int age) {
  if (age < 0 || age > 120) return false;
  else {
    age_ = age;
    return true;
  }
}

bool Persona::mayor(int age){
  if (age >= 18) return 1;
  return 0;
}
