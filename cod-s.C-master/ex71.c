#include <stdio.h>

int pessoaSorteada(int pessoas){

    int vetor[pessoas], i, x;

    for(i = 0; i < pessoas; i++){
        scanf("%d", &vetor[i]);
    }
    for(i = 0; i < pessoas; i++){
        if(vetor[i] == i+1){
            x = vetor[i];
            break;
        }
    }

    return x;
}

int main(){

    int n, teste = 1;
    int pessoaSorteada();

    while(1){
        scanf("%d", &n);
        if(n == 0){
            break;
        }
        printf("Teste %d\n%d\n\n", teste, pessoaSorteada(n));
        teste++;
    }

    return 0;
}
