#include <stdio.h>

int main() {

    int c;
    scanf("%d", &c);

    int i, elementos, vetor[c], comprimento;

    for(i = 0; i < c; i++){
        scanf("%d", &vetor[c]);
    }
    elementos = 0;
    comprimento = 1;
    for(i = 0; i < c-1; i++){
        if(vetor[i] == vetor[i+1]){
            elementos++;
        }
        else{
            elementos = 0;
        }
        if(elementos > comprimento){
            comprimento = elementos;
        }
    }
    printf("O comprimento do segmento de numeros iguais e: %d\n", comprimento);

    return 0;
}
