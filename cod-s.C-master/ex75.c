#include <stdio.h>

int somaDivisores(int num);

int main(){

    int x;

    scanf("%d", &x);

    somaDivisores(x);

    return 0;
}

int somaDivisores(int n){
    int soma, i;

    soma = 0;
    i = 1;
    while(i < n){
        if(i == 1){
            printf("%d = 1", n);
            soma += i;
        }
        else if(n % i == 0){
            printf(" + %d", i);
            soma += i;
        }
        i++;
    }
    printf(" = %d ", soma);
    if(soma == n){
        printf("(NUMERO PERFEITO)\n");
    }
    else{
        printf("(NUMERO NAO E PERFEITO)\n");
    }
}
