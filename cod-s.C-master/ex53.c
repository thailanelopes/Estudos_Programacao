#include <stdio.h>

int main(){

    int n;
    scanf("%d", &n);

    int vet[n], i, j, aux = 0;

    for(i = 0; i < n; i++){
        scanf("%d", &vet[i]);
    }

    for (i = 0; i < n; i++){
        for (j = 0; j < n; j++){
            if (vet[i] < vet[j]){
                aux = vet[i];
                vet[i] = vet[j];
                vet[j] = aux;
            }
        }
    }
    for(i = 0; i < n; i++){
        printf("%d\n", vet[i]);
    }


    return 0;
}
