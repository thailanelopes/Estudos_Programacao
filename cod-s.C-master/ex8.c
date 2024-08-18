#include <stdio.h>

int main(){

    float r, h, area, valor;

    scanf("%f %f", &r, &h);

    area = 2*(3.14159*r*r) + (2*3.14159*r*h);
    valor = area * 100;

    printf("O VALOR DO CUSTO E = %.2f\n", valor);

    return 0;
}
