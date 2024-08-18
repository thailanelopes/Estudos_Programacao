#include <stdio.h>

int main(){

    int n;

    
    scanf("%d", &n);
   

    int vetor[n], i, max, min;

    for(i = 0; i < n; i++){
        scanf("%d", &vetor[i]);

        if(i == 0){
            max = vetor[i];
            min = vetor[i];
        }
        else{
            if(max < vetor[i]){
                max = vetor[i];
            }
            if(min > vetor[i]){
                min = vetor[i];
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
    for(i = n-1; i >= 0; i--){
        if(i > 0){
            printf("%d ", vetor[i]);
        }
        else{
            printf("%d\n", vetor[i]);
        }
    }
    printf("%d\n", max);
    printf("%d\n", min);
    return 0;
}
