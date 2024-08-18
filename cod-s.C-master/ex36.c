#include <stdio.h>

int main(){

    int i, j;
    float aux, vetor[4];

    for(i = 0; i < 4; i++){
        scanf("%f", &vetor[i]);
    }

    for(i = 0; i < 4; i++){
        for(j = i+1; j < 4; j++){
            if(vetor[i] > vetor[j]){
                aux = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = aux;
            }
        }
    }

    for(i = 0; i < 4; i++){
        if(i < 3){
            printf("%.2f, ", vetor[i]);
        }
        else{
            printf("%.2f\n", vetor[i]);
        }
    }

    return 0;
}
