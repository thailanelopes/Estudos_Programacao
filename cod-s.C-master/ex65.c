#include <stdio.h>

int main(){

    int n, aux, i, j;

    while(1){
        scanf("%d", &n);
        if(n == 0){
            break;
        }

        int vetor[n];

        for(i = 0; i < n; i++){
            scanf("%d", &vetor[i]);
        }
        for(i = 0; i < n; i++){
            for(j = i+1; j < n; j++){
                if(vetor[i] > vetor[j]){
                    aux = vetor[i];
                    vetor[i] = vetor[j];
                    vetor[j] = aux;
                }
            }
        }
        for(i = 0; i < n; i++){
            if(i < n-1){
                printf("%d ", vetor[i]);
            }
            else{
                printf("%d\n", vetor[i]);
            }
        }
    }

    return 0;
}
