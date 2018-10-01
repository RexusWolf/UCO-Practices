// dados.h
// La clase dados representa el lanzamiento de 2 dados.
#ifndef DADOS_H
#define DADOS_H

class Dados{
  private:
        int d1_;
        int d2_;
        int l1_;
        int l2_;
        float m1_;
        float m2_;
        int vectordado1_[5];
        int vectordado2_[5];
  public:
        void lanzamiento();
        int getDado1();
        int getDado2();
        bool setDado1(int n1);
        bool setDado2(int n2);
        int getSuma();
        int getDiferencia();
        int getLanzamientos1();
        int getLanzamientos2();
        float getMedia1();
        float getMedia2();
        void getUltimos1(int vector[5]);
        void getUltimos2(int vector[5]);
        Dados(); //Constructor
};


#endif
