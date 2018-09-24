// dados.h
// La clase dados representa el lanzamiento de 2 dados.
#ifndef DADOS_H
#define DADOS_H

class Dados{
  private:
        int d1_;
        int d2_;
  public:
        void lanzamiento();
        int getDado1();
        int getDado2();
        bool setDado1(int n1);
        bool setDado2(int n2);
        int getSuma();
        int getDiferencia();
        Dados(); //Constructor
};


#endif
