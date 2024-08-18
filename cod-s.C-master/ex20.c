#include <stdio.h>

int main(){

    int conta;
    float consumo, valor;
    char tipo;

    scanf("%d %f %c", &conta, &consumo, &tipo);

    printf("CONTA = %d\n", conta);

    if(tipo == 'R'){
        valor = 5 + (0.05 * consumo);
        printf("VALOR DA CONTA = %.2f\n", valor);
    }
    else if(tipo == 'C'){
        if(consumo > 80){
            valor = 500 + (consumo - 80) * 0.25;
        }
        else{
            valor = 500;
        }
        printf("VALOR DA CONTA = %.2f\n", valor);
    }
    else{
        if(consumo > 100){
            valor = 800 + (consumo - 100) * 0.04;
        }
        else{
            valor = 800;
        }
        printf("VALOR DA CONTA = %.2f\n", valor);
    }

    return 0;
}
