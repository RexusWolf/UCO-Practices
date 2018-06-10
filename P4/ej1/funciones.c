#include "funciones.h"


void fx (float N){
  float fdx;
  float x=0;
  float e = 2.7182;

    while (x<N){
    fdx = 3 * pow(e,x) - (2*x);
    printf("%f\n", fdx );
    x+=0.2;
    }
}

void gx (float N){
  float gdx;
  float x=0;
  float e = 2.7182;
    while (x<N){
    gdx = -x * sin(x) + 1.5;
    printf("%f\n", gdx );
    x+=0.2;
    }
}

void zx (float N){
  float zdx;
  float x=0;
  float e = 2.7182;

    while (x<N){
    zdx = pow(x,3) - (2*x) + 1;
    printf("%f\n", zdx );
    x+=0.2;
    }
}
