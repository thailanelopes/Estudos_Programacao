#include <stdio.h>

int main(){

    int matricula, n_dp;
    float sal_min, sal_func, taxa, imposto_bruto, imposto_liquido, resultado;

    scanf("%d %f %d %f %f", &matricula, &sal_min, &n_dp, &sal_func, &taxa);

    if((sal_min * 12) < sal_func){
        imposto_bruto = sal_func * 0.2;
    }
    else if((sal_min * 5) < sal_func){
        imposto_bruto = sal_func * 0.08;
    }
    else{
        imposto_bruto = 0;
    }

    imposto_liquido = imposto_bruto - 300 * n_dp;
    resultado = imposto_liquido - (sal_func * taxa/100);

    printf("MATRICULA = %d\n", matricula);
    printf("IMPOSTO BRUTO = %.2f\n", imposto_bruto);
    printf("IMPOSTO LIQUIDO = %.2f\n", imposto_liquido);
    printf("RESULTADO = %.2f\n", resultado);

    if(resultado < 0){
        printf("IMPOSTO A RECEBER\n");
    }
    else if(resultado > 0){
        printf("IMPOSTO A PAGAR\n");
    }
    else{
        printf("IMPOSTO QUITADO\n");
    }

    return 0;
}
