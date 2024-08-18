#include <stdio.h>

int main(){

    int n1, n2, n3, numero;
    scanf("%d %d %d", &n1, &n2, &n3);

    if((n1 > 9) || (n2 > 9 ) || (n3 > 9)){
        printf("DIGITO INVALIDO\n");
    }
    else if((n1 == 0)&& (n2 == 0)){
        printf("%d, %d\n", n3, n3*n3);
    }
    else if(n1 == 0){
        numero = (n2 * 10) + n3;
        printf("%d, %d\n", numero, numero * numero);
    }
    else{
        numero = numero = (n1 * 100) + (n2 * 10) + n3;
        printf("%d, %d\n", numero, numero * numero);
    }

    return 0;
}
