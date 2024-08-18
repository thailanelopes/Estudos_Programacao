#include <stdio.h>

int main(){

    int m, n;

    scanf("%d %d", &m, &n);

    int matriz[m][n], i, j;
    int maior, menor, posl_maior, posc_maior, posl_menor, posc_menor, aux;

    for(i = 0; i < m; i++){
        for(j = 0; j < n; j++){
            scanf("%d", &matriz[i][j]);
            if(i == 0 && j == 0){
                maior = matriz[i][j];
                menor = matriz[i][j];
                posl_maior = i;
                posc_maior = j;
                posl_menor = i;
                posc_menor = j;
            }
            else{
                if(maior < matriz[i][j]){
                    maior = matriz[i][j];
                    posl_maior = i;
                    posc_maior = j;
                }
                if(menor > matriz[i][j]){
                    menor = matriz[i][j];
                    posl_menor = i;
                    posc_menor = j;
                }
            }
        }
    }
    matriz[posl_maior][posc_maior] = menor;
    matriz[posl_menor][posc_menor] = maior;

    for(i = 0; i < m; i++){
        for(j = 0; j < n; j++){
            if(j < n-1){
                printf("%d ", matriz[i][j]);
            }
            else{
                printf("%d\n", matriz[i][j]);
            }
        }
    }
    return 0;
}
