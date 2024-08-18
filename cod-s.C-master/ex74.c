#include <stdio.h>

int digit_count(long int n);

int main(){

    long int x;
    scanf("%li", &x);

    printf("Numero de digitos: %d\n", digit_count(x));

    return 0;
}

int digit_count(long int n){

    int quantidade = 0;

    while(n != 0){
        n = n / 10;
        quantidade++;
    }

    return quantidade;
}
