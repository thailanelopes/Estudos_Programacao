
#include <stdio.h>

int main(){

    int n;

    do{
        scanf("%d", &n);
    }while(n <= 1 || n > 1000000);

    int vetor[n], i, j, aux;
    float mediana;

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
    if(n % 2 == 0){
        mediana = (vetor[n/2-1] + vetor[n/2])/2.0;
    }
    else{
        mediana = vetor[n/2];
    }

    printf("%.2f\n", mediana);

    return 0;
}
