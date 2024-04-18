#include <stdio.h>

int main(){
    for(int i = 0; i < 3; i++){
        if(i >= 0 && i <= 200){
            for(int j = 0; j < 3; j++){
                if(j >= 0 && j  <=200){
                    puts("Alteração na matriz");
                }
            }
        }
    }
    return 0;
}