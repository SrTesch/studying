#include <stdio.h>

int main(){
    int x = 10, y = 20;

    int a = 10, b = 5;

    if(x == y){
        if(a > b){
            puts("a é maior que b e x = y");
        }else if (a < b){
            puts("a é menor que b e x = y");
        }else{
            puts("a = b e x = y");
        }
    }else if(x < y){
        if(a > b){
            puts("a é maior do que b e x < y");
        } else if(a < b){
            puts("a é menor do que b e x < y");
        }else if(a == b){
            puts("a = b e x < y");
        }
    }else if(x > y){
        if(a > b){
            puts("a é maior do que b e x < y");
        }else if(a < b){
            puts("a é menor do que b e x < y");
        }else if(a == b){
            puts("a = b e x < y");
        }
    }

    return 0;
}