#include <stdio.h>

void converteEmNotasMoedas(int valor);

int main(){

    int v;

    scanf("%d", &v);
    converteEmNotasMoedas(v);

    return 0;
}

void converteEmNotasMoedas(int valor){
    int n100, n50 , n10, n1;

    n100 = valor / 100;
    n50 = (valor % 100) / 50;
    n10 = (valor % 50) / 10;
    n1 = (valor % 10) / 1;

    printf("NOTAS DE 100 = %d\n", n100);
    printf("NOTAS DE 50 = %d\n", n50);
    printf("NOTAS DE 10 = %d\n", n10);
    printf("MOEDAS DE 1 = %d\n", n1);
}
