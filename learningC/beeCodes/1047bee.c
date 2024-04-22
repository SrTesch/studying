#include <stdio.h>
 
int main() {
 int hi, mi, hf, mf, m, h;
 scanf("%d %d %d %d", &hi, &mi, &hf, &mf);
 if(hi == hf){
    if (mi == mf){
        h = 24;
        m = 0;
    } else if (mi < mf){
        h = 0;
        m = mf - mi;
    } else if (mi > mf){
        h = 23;
        m = 60 + (mf - mi);
    }
}else if(hi < hf){
     if (mi == mf){
         h = hf - hi;
         m = 0;
     } else if (mi < mf){
         h = hf - hi;
         m = mf - mi;
     } else if (mi > mf){
         h = hf - hi; // h = 1;
         m = 60 + mf - mi; 
         h -= 1;
     }
}else if(hi > hf){ // hi = 10 hf = 5
     if (mi == mf){
         h = 24 - hi;
         h += hf;
         m = 0;
     } else if (mi < mf){
         h = 24 - hi;
         h += hf;
         m = mf - mi;
     } else if (mi > mf){
         h = 24 - hi;
         h += hf; 
         m =  60 + (mf - mi);
         h -= 1 ;
     }
 }
  printf("O JOGO DUROU %d HORA(S) E %d MINUTO(S)\n", h, m);
    return 0;
}
