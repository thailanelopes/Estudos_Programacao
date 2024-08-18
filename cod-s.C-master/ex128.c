#include <stdio.h>

int main(){

    int m, n;
    // lê o tamanho da linha da matriz
    do{
        scanf("%d", &m);
    }while(m < 1 || m > 10);
    // lê o tamanho da coluna da matriz
    do{
        scanf("%d", &n);
    }while(n < 1 || n > 10);

    int matriz[m][n], i, j;
    // lê os elementos da matriz
    for(i = 0; i < m; i++){
        for(j = 0; j < n; j++){
            scanf("%d", &matriz[i][j]);
        }
    }
    // imprime a matriz linha a linha
    for(i = 0; i < m; i++){
        printf("linha %d: ", i+1);
        for(j = 0; j < n; j++){
            if(j == n-1){
                printf("%d", matriz[i][j]);
            }
            else{
                printf("%d,", matriz[i][j]);
            }
        }
        printf("\n");
    }
    return 0;
}

