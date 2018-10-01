// dados_unittest.cc: Juan A. Romero
// A sample program demonstrating using Google C++ testing framework.
//


// This sample shows how to write a more complex unit test for a class
// that has multiple member functions.
//
// Usually, it's a good idea to have one test for each method in your
// class.  You don't have to do that exactly, but it helps to keep
// your tests organized.  You may also throw in additional tests as
// needed.

#include "dados.h"
#include "gtest/gtest.h"

// Tests the c'tor.
TEST(Dados, Constructor) {
  Dados d;

  EXPECT_EQ(1, d.getDado1());
  EXPECT_EQ(1, d.getDado2());
  EXPECT_EQ(2, d.getSuma());

}

// Tests operación lanzamiento
TEST(Dados, Lanzamiento) {
  Dados d;
  for (int i=0; i<100; i++){
  d.lanzamiento();
  EXPECT_GT(d.getDado1(), 0);
  EXPECT_LT(d.getDado1(), 7);
  EXPECT_GT(d.getDado2(), 0);
  EXPECT_LT(d.getDado2(), 7);
}

}

// Tests operación suma
TEST(Dados, Suma) {
  Dados d;

  EXPECT_EQ(d.getDado1()+d.getDado2(), d.getSuma());
}

// Tests modificadores
TEST(Dados, Modificadores) {
  Dados d;

  EXPECT_FALSE(d.setDado1(9));
  EXPECT_FALSE(d.setDado1(-9));
  EXPECT_FALSE(d.setDado2(9));
  EXPECT_FALSE(d.setDado2(-9));
  d.setDado1(3);
  EXPECT_EQ(3, d.getDado1());
  d.setDado2(2);
  EXPECT_EQ(2, d.getDado2());
  EXPECT_EQ(5, d.getSuma());
}

//Test diferencia
 TEST(Dados, Diferencia) {
   Dados d;

   d.setDado1(4);
   d.setDado2(1);
   EXPECT_EQ(3, d.getDiferencia());

 }

 TEST(Dados, Lanzamientos){
   Dados d;
   EXPECT_EQ(0, d.getLanzamientos1());
   EXPECT_EQ(0, d.getLanzamientos2());
   d.setDado1(3);
   d.setDado2(5);
   EXPECT_EQ(1, d.getLanzamientos1());
   EXPECT_EQ(1, d.getLanzamientos2());
   d.setDado2(5);
   EXPECT_EQ(1, d.getLanzamientos1());
   EXPECT_EQ(2, d.getLanzamientos2());
 }

 TEST(Dados, Media){
   Dados d;
   EXPECT_EQ(0, d.getMedia1());
   EXPECT_EQ(0, d.getMedia2());
   d.setDado1(2);
   d.setDado2(4);
   EXPECT_EQ(2, d.getMedia1());
   EXPECT_EQ(4, d.getMedia2());
   d.setDado1(1);
   d.setDado2(3);
   EXPECT_EQ(1.5, d.getMedia1());
   EXPECT_EQ(3.5, d.getMedia2());

 }

 TEST(Dados, Vector){
   Dados d;
   int vector1[5];
   int vector2[5];
   int v1[5] = {1,1,1,1,1};
   int v2[5] = {1,1,1,1,1};
   d.lanzamiento();
   v1[2] = d.getDado1();
   v2[2] = d.getDado2();
   d.lanzamiento();
   v1[1] = d.getDado1();
   v2[1] = d.getDado2();
   d.lanzamiento();
   v1[0] = d.getDado1();
   v2[0] = d.getDado2();
   d.getUltimos1(vector1);
   d.getUltimos2(vector2);
     for(int i = 0; i<5; i++){
     EXPECT_EQ(vector1[i], v1[i] );
     }
     for(int i = 0; i<5; i++){
     EXPECT_EQ(vector2[i], v2[i] );
     }
 }
