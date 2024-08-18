#include <stdio.h>

int main(){

    int n, aux, n_invertido = 0;

    scanf("%d", &n);

    if(n > 99999){
        printf("NUMERO INVALIDO\n");
    }
    else{
        aux = n;

        while(aux != 0){
            n_invertido = n_invertido * 10 + aux % 10;
            aux /= 10;
        }
        if(n_invertido == n){
            printf("PALINDROMO\n");
        }
        else{
            printf("NAO PALINDROMO\n");
        }
    }

    return 0;
}
