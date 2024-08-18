#include <stdio.h>

int main(){

    int m, n;
    // lê as linhas e colunas respectivamente
    scanf("%d %d", &m, &n);

    int matriz[m][n], i, j, k = 1;

    // constrói a matriz no padrão xadrez, sendo 1(branco) e 0(preto)
    for(i = 0; i < m; i++){
        for(j = 0; j < n; j++){
            if(i % 2 == 0){
                if(j % 2 == 0){
                    matriz[i][j] = 0;
                }
                else{
                    matriz[i][j] = k;
                    k++;
                }
            }
            else{
                if(j % 2 == 0){
                    matriz[i][j] = k;
                    k++;
                }
                else{
                    matriz[i][j] = 0;
                }
            }
        }
    }
    // imprime a matriz
    for(i = 0; i < m; i++){
        for(j = 0; j < n; j++){
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }


    return 0;
}

