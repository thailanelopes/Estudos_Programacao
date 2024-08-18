#include <stdio.h>

int main(){

    int a, b, ano = 0;

    scanf("%d %d", &a, &b);


    while(a < b){
        a *= 1.03;
        b *= 1.015;
        ano++;
    }

    printf("ANOS = %d\n", ano);

    return 0;
}

