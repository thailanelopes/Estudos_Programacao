#include <stdio.h>

int main(){

    int n;
    do{
        scanf("%d", &n);
    }while(n <= 1 || n > 1000);

    int matriz[n][n], i, j, aux, aux1;

    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            scanf("%d", &matriz[i][j]);
        }
    }

    for(j = n-1; j >= 0; j--){
        for(i = n-1; i >= 0; i--){
            for(aux1 = i-1; aux1 >= 0; aux1--){
                if(matriz[i][j] < matriz[aux1][j]){
                    aux = matriz[i][j];
                    matriz[i][j] = matriz[aux1][j];
                    matriz[aux1][j] = aux;
                }
            }
        }
    }

    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            if(j < n-1){
                printf("%d ", matriz[i][j]);
            }
            else{
                printf("%d", matriz[i][j]);
            }
        }
        printf("\n");
    }

    return 0;
}
