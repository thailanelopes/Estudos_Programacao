#include <stdio.h>

int main(){

    int vetor[3], i, j, aux;
    for(i = 0; i < 3; i++){
        scanf("%d\n", &vetor[i]);
    }
    for(i = 0; i < 3; i++){
        for(j = i+1; j < 3; j++){
            if(vetor[i] > vetor[j]){
                aux = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = aux;
            }
        }
    }

    int a, b, c;
    char x, y, z;
    scanf("%c%c%c", &x, &y, &z);

    if(x == 'A'){
        a = vetor[0];
        if(y == 'B'){
            b = vetor[1];
            c = vetor[2];
        }
        else{
            b = vetor[2];
            c = vetor[1];
        }
    }
    else if(x == 'B'){
        a = vetor[1];
        if(y == 'A'){
            b = vetor[0];
            c = vetor[2];
        }
        else{
            b = vetor[2];
            c = vetor[0];
        }
    }
    else if(x == 'C'){
        a = vetor[2];
        if(y == 'A'){
            b = vetor[0];
            c = vetor[1];
        }
        else{
            b = vetor[1];
            c = vetor[0];
        }
    }

    printf("%d %d %d\n", a, b, c);

    return 0;
}
