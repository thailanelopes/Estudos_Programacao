#include <stdio.h>

int main(){

    int n;
    // lê tamanho da matriz quadrada
    scanf("%d", &n);
    int m[n][n], i, j;
    // lê elementos da matriz
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            scanf("%d", &m[i][j]);
        }
    }
    // imprime a diagonal da matriz
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            if(i == j){
                printf("%d\n", m[i][j]);
                break;
            }
        }
    }
    return 0;
}
