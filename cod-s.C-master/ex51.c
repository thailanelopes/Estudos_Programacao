#include <stdio.h>

int main(){

    int n;
    scanf("%d", &n);

    int notas[n], i, maior = 0, qntd = 0, pos;

    for(i = 0; i < n; i++){
        scanf("%d", &notas[i]);
    }
    for(i = 0; i < n; i++){
        if(notas[n - 1] == notas[i]){
            qntd++;
        }
        if(notas[i] > maior){
            maior = notas[i];
            pos = i;
        }
    }

    printf("Nota %d, %d vezes\n", notas[n - 1], qntd);
    printf("Nota %d, indice %d\n", maior, pos);

    return 0;
}
