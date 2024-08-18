#include <stdio.h>

int main(){

    // Definindo tamanho da matriz
    int n;
    do{
        scanf("%d", &n);
    }while(n <= 1 || n > 1000);

    int A[n][n], AT[n][n], tr = 0, i, j, resultado;

    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            // matriz A
            scanf("%d", &A[i][j]);
            // matriz transposta de A
            AT[j][i] = A[i][j];
        }
    }
    // soma dos elementos da diagonal principal da matriz A
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            if(i == j){
                tr += A[i][j];
                break;
            }
        }
    }
    // imprimindo resultado
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            resultado = tr * A[i][j] + AT[i][j];
            if(j < n-1){
                printf("%d ", resultado);
            }
            else{
                printf("%d", resultado);
            }
        }
        printf("\n");
    }

    return 0;
}
