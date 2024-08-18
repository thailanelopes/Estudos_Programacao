#include <stdio.h>
#include <math.h>

int main(){

    int teste;
    scanf("%d", &teste);

    int i;
    float d, vetor[3], aux[3];

    for(i = 0; i < 3; i++){
        scanf("%f", &vetor[i]);
    }

    teste -= 1;
    while(teste--){
        for(i = 0; i < 3; i++){
            scanf("%f", &aux[i]);
        }

        d = sqrt(pow(vetor[0]-aux[0], 2) + pow(vetor[1]-aux[1], 2) + pow(vetor[2] - aux[2], 2));

        printf("%.2f\n", d);

        for(i = 0; i < 3; i++){
            vetor[i] = aux[i];
        }
    }

    return 0;
}
