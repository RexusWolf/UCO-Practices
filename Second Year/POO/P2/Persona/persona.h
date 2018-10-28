//persona.h
#ifndef PERSONA_H
#define PERSONA_H

#include <string>
using std::string

class Persona{
  private:
    string dni_;
    string name_;
    string surname_;
    int age_;
    string address_;
    string city_;
    string province_;
    string country_;

  public:
    string getDNI();
    void setDNI(string &cad);
    int getAge(){ return dni_;}
    bool setAge(int age);
    string getName(){ return name_;}
    void setName(string &cad);
    string getSurname(){ return surname_;}
    void setSurname(string &cad);
    string getCity(){ return city_;}
    void setCity(string &cad);
    string getProvince(){ return province_;}
    void setProvince(string &cad);
    string getCountry(){ return country_;}
    void setCountry(string &cad);
    string getAddress(){ return address_;}
    void setAddress(string &cad);
    string getApellidosyNombre(string &name, string &surname){return getApellidos() + ", " + getNombre();}
    bool mayor(int age);
    Persona(string &dni, string &name = "", string &surname = "", int age = 0,
            string &address = "", string &city = "", string &province = "",
            string &country = ""); // Constructor

};

#endif
