#include <stdio.h>

int main(){

    int n, quadrado, i;

    scanf("%d", &n);

    for(i = 2; i <= n; i += 2){
        quadrado = i * i;
        printf("%d^2 = %d\n", i, quadrado);
    }


    return 0;
}

