#include <stdio.h>

int main(){

    float p_carro, perc_d, perc_i, custo_cons;

    scanf("%f %f %f", &p_carro, &perc_d, &perc_i);

    custo_cons = p_carro + (p_carro * perc_d/100) + (p_carro * perc_i/100);

    printf("O VALOR DO CARRO E = %.2f\n", custo_cons);

    return 0;
}
