#include <stdio.h>

int main(){

    int n;
    scanf("%d", &n);
    if(n < 2){
        printf("Campeonato invalido!\n");
    }
    else{
        int i, j, k = 1;
        for(i = 1; i < n; i++){
            for(j = i+1; j <= n && j != i; j++){
                printf("Final %d: Time%d X Time%d\n", k, i, j);
                k++;
            }
        }
    }
    return 0;
}
