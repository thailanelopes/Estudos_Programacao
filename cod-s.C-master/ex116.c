#include <stdio.h>

int main(){

    int n, i, ordenado;

    while(1){
        scanf("%d", &n);
        float vetor[n];

        if(n == 0){
            break;
        }
        for(i = 0; i < n; i++){
            scanf("%f", &vetor[i]);
        }

        ordenado = 1;
        for(i = 0; i < n-1; i++){
            if(vetor[i] > vetor[i+1]){
                ordenado = 0;
                break;
            }
        }
        if(ordenado == 0){
            printf("DESORDENADA\n");
        }
        else{
           printf("ORDENADA\n");
        }
    }

    return 0;
}
