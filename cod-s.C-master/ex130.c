#include <stdio.h>

int main(){

    int k, j, i;;
    float matriz1[2][2], matriz2[2][2], soma;
    //inserindo elementos na matriz1 e matriz2
    for(i = 0; i < 2; i++){
        for (j = 0; j < 2; j++){
            scanf("%f", &matriz1[i][j]);
            matriz2[i][j] = matriz1[i][j];
        }
    }
    //multiplicando a matriz
    soma = 0;
    for(i = 0; i < 2; i++){
        for(j = 0; j < 2; j++){
            for(k = 0; k < 2; k++){
                soma = soma + matriz1[i][k]*matriz2[k][j];
            }
            if(j == 0){
                printf("%.3f ",soma);
            }
            else{
                printf("%.3f", soma);
            }
            soma = 0;
        }
        printf("\n");
    }

    return 0;
}
