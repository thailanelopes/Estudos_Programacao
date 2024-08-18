#include <stdio.h>

int main(){

    int i, j, matriz[6][6], soma, max = 0;
    // inserindo elementos na matriz
    for(i = 0; i < 6; i++){
        for (j = 0; j < 6; j++){
            scanf("%d", &matriz[i][j]);
        }
    }
    // soma no padrão ampulheta
    soma = 0;
    for(i = 0; i < 4; i++){
        for(j = 0; j < 4; j++){
            soma = matriz[i][j] + matriz[i][j+1] + matriz[i][j+2] + matriz[i+1][j+1] + matriz[i+2][j] + matriz[i+2][j+1] + matriz[i+2][j+2];

            if(i == 0 && j == 0){
                max = soma;
            }
            else if(max < soma){
                max = soma;
            }
        }
    }

    // o máximo da soma
    printf("%d\n", max);

    return 0;
}
