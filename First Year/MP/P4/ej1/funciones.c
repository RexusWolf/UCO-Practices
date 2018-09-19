#include "funciones.h"


void fx (float N){
  float fdx;
  float x=0;
  float e = 2.7182;
      for (x=0; x<N; x+=0.2){
        fdx = 3 * pow(e,x) - (2*x);
        printf("%f\n", fdx );
      }
}

void gx (float N){
  float gdx;
  float x=0;
  float e = 2.7182;
      for (x=0; x<N; x+=0.2){
        gdx = -x * sin(x) + 1.5;
        printf("%f\n", gdx );
      }
}

void zx (float N){
  float zdx;
  float x=0;
  float e = 2.7182;
      for (x=0; x<N; x+=0.2){
        zdx = pow(x,3) - (2*x) + 1;
        printf("%f\n", zdx );
        }
}
