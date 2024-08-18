
#include <stdio.h>

int main(){

    int n;

    do{
        scanf("%d", &n);
    }while(n >= 5000);

    int vetor[n], copia[n], i, j, x = 0, elementos = 0;

    for(i = 0; i < n; i++){
        scanf("%d", &vetor[i]);
        copia[i] = vetor[i];
    }

    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            if(copia[j] == vetor[i]){
                x++;
            }
        }
        if(x == 1){
            elementos++;
        }
        x = 0;
    }
    printf("%d\n", elementos);

    return 0;
}

