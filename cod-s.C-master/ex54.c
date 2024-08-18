#include <stdio.h>

int main(){

    int n;
    scanf("%d", &n);

    int vetor[n], i, j, elementos, numMaiorFreq, freq;

    for(i = 0; i < n; i++){
        scanf("%d", &vetor[i]);
    }

    elementos = 0;
    freq = 0;
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            if(vetor[i] == vetor[j]){
                elementos++;
                if(i == 0){
                    freq = elementos;
                    numMaiorFreq = vetor[i];
                }
                if(freq < elementos){
                    freq = elementos;
                    numMaiorFreq = vetor[i];
                }
                else if(freq == elementos && numMaiorFreq > vetor[i]){
                    numMaiorFreq = vetor[i];
                }
            }
        }
        elementos = 0;
    }

    printf("%d\n", numMaiorFreq);
    printf("%d\n", freq);



    return 0;
}
