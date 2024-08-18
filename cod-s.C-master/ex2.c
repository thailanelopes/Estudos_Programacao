#include <stdio.h>

int main(){

    float sal_min, qntd_kw, valor_kw, valor_cons, valor_desc;

    scanf("%f %f", &sal_min, &qntd_kw);

    valor_kw = (0.007 * sal_min);
    valor_cons = valor_kw * qntd_kw;
    valor_desc = valor_cons * 0.90;

    printf("Custo por kW: R$ %.2f\n", valor_kw);
    printf("Custo do consumo: R$ %.2f\n", valor_cons);
    printf("Custo com desconto: R$ %.2f\n", valor_desc);

    return 0;
}
