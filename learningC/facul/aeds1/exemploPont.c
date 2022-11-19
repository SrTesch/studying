#include <stdio.h>

int main(){
    int a[4];
    for(int i = 0; i < 4; i++){
        printf("%p\n", &a[i]);
    }
    return 0;
}