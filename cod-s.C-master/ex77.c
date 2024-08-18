#include <stdio.h>

int separaDigitos(int n);

int main(){

    int num, num_invertido;
    scanf("%d", &num);

    num_invertido = separaDigitos(num);

    printf("%d\n", num_invertido);

    return 0;
}

int separaDigitos(int n){

    int ret=0;
    int i=1;

    while(i<=n){
       ret*=10;
       ret+=(n%(i*10)-n%i)/i;
       i*=10;
    }
    return ret;
}
