#include <stdio.h>
#include <math.h>

int main(){

    int teste;
    scanf("%d", &teste);

    int i, k, j;
    float d, vetor[3], aux[3], maior[3];

    for(i = 0; i < 3; i++){
        scanf("%f", &vetor[i]);
    }

    teste -= 1;
    while(teste--){
        for(i = 0; i < 3; i++){
            scanf("%f", &aux[i]);
        }

        for(i = 0; i < 3; i++){
            if(aux[i]-vetor[i] < 0){
                maior[i] = (aux[i]-vetor[i])*-1;
            }
            else{
                maior[i] = (aux[i]-vetor[i]);
            }
        }

        for(i = 0; i < 3; i++){
            for(j = i + 1; j < 3; j++){
                if(maior[i] < maior[j]){
                    k = maior[i];
                    maior[i] = maior[j];
                    maior[j] = k;
                }
            }
        }
        d = maior[0];

        printf("%.2f\n", d);

        for(i = 0; i < 3; i++){
            vetor[i] = aux[i];
        }
    }

    return 0;
}
