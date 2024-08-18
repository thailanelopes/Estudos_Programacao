#include <stdio.h>

int main(){

    float sal_min, limite_isencao_ir, p1, p2;

    scanf("%f %f %f %f", &sal_min, &limite_isencao_ir, &p1, &p2);

    int matricula, num_p1, num_p2;
    float sal_bruto, sal_liquido, sal_total, comissao;
    while(1){
        scanf("%d %d %d", &matricula, &num_p1, &num_p2);

        if(matricula == 0 && num_p1 == 0 && num_p2 == 0){
            break;
        }

        comissao = 0;
        if(num_p1 < 10){
            comissao += (num_p1 * p1) * 0.13;
        }
        else{
            comissao += (num_p1 * p1) * 0.14;
        }

        if(num_p2 < 20){
            comissao += (num_p2 * p2) * 0.12;
        }
        else{
            comissao += (num_p2 * p2) * 0.13;
        }

        sal_bruto = comissao + sal_min;
        sal_total = sal_bruto * 0.92;

        if(sal_total > limite_isencao_ir){
            sal_liquido = (sal_total - limite_isencao_ir) * 0.85 + limite_isencao_ir;
        }
        else{
            sal_liquido = sal_total;
        }
            printf("MATRICULA = %d, SALARIO BRUTO = %.2f, SALARIO LIQUIDO = %.2f\n", matricula, sal_bruto, sal_liquido);
    }


    return 0;
}
