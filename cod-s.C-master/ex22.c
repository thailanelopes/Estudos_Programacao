#include <stdio.h>

int main(){

    int h;
    float total;

    scanf("%d", &h);

    total = (h / 3 * 10) + (h % 3 * 5);

    printf("O VALOR A PAGAR E = %.2f\n", total);

    return 0;
}
