#include <stdio.h>

int main(){

    int n;
    scanf("%d", &n);

    int vetor[n], i, j, k;

    for(i = 0; i < n; i++){
        scanf("%d", &vetor[i]);
    }

    for(i = 0; i < n; i++){
        for(j = i+1; j < n; ){
            if(vetor[j] == vetor[i]){
                for(k = j; k < n; k++){
                    vetor[k] = vetor[k + 1];
                }
                n--;
            }
            else{
                j++;
            }
        }
    }

    for(i = 0; i < n; i++){
        printf("%d\n", vetor[i]);
    }

    return 0;
}
