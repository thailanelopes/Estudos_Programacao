#include <stdio.h>

int main(){

    int n;
    scanf("%d", &n);

    int vetor[n], i, j, aux, elementosPares, elementosImpares;

    elementosPares = 0;
    elementosImpares = 0;
    for(i = 0; i < n; i++){
        scanf("%d", &vetor[i]);
        if(vetor[i] % 2 == 0){
            elementosPares++;
        }
        else{
            elementosImpares++;
        }
    }

    int pares[elementosPares], x, impares[elementosImpares], y;
    x = 0;
    y = 0;
    for(i = 0; i < n; i++){
        if(vetor[i] % 2 == 0){
            pares[x] = vetor[i];
            x++;
        }
        else{
            impares[y] = vetor[i];
            y++;
        }
    }

    for(i = 0; i < elementosPares; i++){
        for(j = i+1; j < elementosPares; j++){
            if(pares[i] > pares[j]){
                aux = pares[i];
                pares[i] = pares[j];
                pares[j] = aux;
            }
        }
    }
    for(i = 0; i < elementosImpares; i++){
        for(j = i+1; j < elementosImpares; j++){
            if(impares[i] < impares[j]){
                aux = impares[i];
                impares[i] = impares[j];
                impares[j] = aux;
            }
        }
    }

    for(i = 0; i < elementosPares; i++){
        printf("%d\n", pares[i]);
    }
    for(i = 0; i < elementosImpares; i++){
        printf("%d\n", impares[i]);
    }


    return 0;
}
