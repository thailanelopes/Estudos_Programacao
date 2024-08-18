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
    // imprime a diagonal secundaria da matriz
    for(i = 0; i < n; i++){
        for(j = n; j >= 0; j--){
            if(i == (n-1-j) || j == (n-1-i)){
                printf("%d\n", m[i][j]);
                break;
            }
        }
    }
    return 0;
}

