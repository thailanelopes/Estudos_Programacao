#include <stdio.h>

int main(){

    float valorIngresso, valorInicial, valorFinal;
    scanf("%f %f %f", &valorIngresso, &valorInicial, &valorFinal);

    int numIngressos, numIngressosMelhor, i = 0;
    float lucro, melhorValor, lucroMelhor;

    if(valorInicial >= valorFinal){
        printf("INTERVALO INVALIDO.\n");
    }
    else{
        for(valorInicial; valorInicial <= valorFinal; valorInicial++){

            if(valorInicial < valorIngresso){
                numIngressos = (valorIngresso - valorInicial)/0.5 * 25 + 120;
            }
            else if(valorInicial == valorIngresso){
                numIngressos = 120;
            }
            else{
                numIngressos = (valorIngresso - valorInicial)/0.5 * 30 + 120;
            }
            lucro = (numIngressos * valorInicial) - (200 + (0.05 * numIngressos));

            if(i == 0){
                melhorValor = valorInicial;
                lucroMelhor = lucro;
                numIngressosMelhor = numIngressos;
            }
            else{
                if(lucroMelhor < lucro){
                    melhorValor = valorInicial;
                    lucroMelhor = lucro;
                    numIngressosMelhor = numIngressos;
                }
            }
            i++;

            printf("V: %.2f, N: %d, L: %.2f\n", valorInicial, numIngressos, lucro);
        }

        if(lucroMelhor <= 0){
            melhorValor = 0.0;
            lucroMelhor = 0.0;
            numIngressosMelhor = 0;

            printf("Melhor valor final: %.2f\n", melhorValor);
            printf("Lucro: %.2f\n", lucroMelhor);
            printf("Numero de ingressos: %d\n", numIngressosMelhor);
        }
        else{
            printf("Melhor valor final: %.2f\n", melhorValor);
            printf("Lucro: %.2f\n", lucroMelhor);
            printf("Numero de ingressos: %d\n", numIngressosMelhor);
        }
    }

    return 0;
}
