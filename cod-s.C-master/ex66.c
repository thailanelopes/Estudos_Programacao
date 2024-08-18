#include <stdio.h>

int main(){

    int sorteadas[6], i, j;
    for(i = 0; i < 6; i++){
        scanf("%d", &sorteadas[i]);
    }

    int N;
    scanf("%d", &N);

    int dezenas[6], sena, quina, quadra, acertadas;

    acertadas = 0;
    sena = 0;
    quadra = 0;
    quina = 0;
    while(N--){
        for(i = 0; i < 6; i++){
            scanf("%d", &dezenas[i]);
            for(j = 0; j < 6; j++){
                if(dezenas[i] == sorteadas[j]){
                    acertadas++;
                }
            }
        }

        if(acertadas == 4){
            quadra++;
        }
        else if(acertadas == 5){
            quina++;
        }
        else if(acertadas == 6){
            sena++;
        }

        acertadas = 0;

    }

    if(sena > 0){
        printf("Houve %d acertador(es) da sena\n", sena);
    }
    else{
        printf("Nao houve acertador para sena\n");
    }

    if(quina > 0){
        printf("Houve %d acertador(es) da quina\n", quina);
    }
    else{
        printf("Nao houve acertador para quina\n");
    }

    if(quadra > 0){
        printf("Houve %d acertador(es) da quadra\n", quadra);
    }
    else{
        printf("Nao houve acertador para quadra\n");
    }

    return 0;
}
