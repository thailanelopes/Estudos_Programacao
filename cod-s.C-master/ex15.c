#include <stdio.h>

int main(){

    int valor, n100, n50 , n10, n1;

    scanf("%d", &valor);

    n100 = valor / 100;
    n50 = (valor % 100) / 50;
    n10 = (valor % 50) / 10;
    n1 = (valor % 10) / 1;

    printf("NOTAS DE 100 = %d\n", n100);
    printf("NOTAS DE 50 = %d\n", n50);
    printf("NOTAS DE 10 = %d\n", n10);
    printf("MOEDAS DE 1 = %d\n", n1);

    return 0;
}
