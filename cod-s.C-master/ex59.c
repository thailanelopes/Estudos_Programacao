#include <stdio.h>

int main(){

    int teste;
    scanf("%d", &teste);

    int cpf[11], b1, b2, divisivel, i, j, x;

    while(teste--){
        divisivel = 0;
        x = 9;
        b1 = 0;
        b2 = 0;
        for(i = 1; i <= 11; i++){
            scanf("%d", &cpf[i]);
            if(i < 10){
                b1 += cpf[i] * i;
                b2 += cpf[i] * x;
                x--;
            }
            divisivel += cpf[i];
        }

        if(b1 % 11 == 10){
            b1 = 0;
        }
        else{
            b1 = b1 % 11;
        }

        if(b2 % 11 == 10){
            b2 = 0;
        }
        else{
            b2 = b2 % 11;
        }

        if(divisivel % 11 == 0 && b1 == cpf[10] && b2 == cpf[11]){
            printf("CPF valido\n");
        }
        else{
            printf("CPF invalido\n");
        }

    }

    return 0;
}
