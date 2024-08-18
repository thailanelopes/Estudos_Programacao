#include <stdio.h>

int main(){

    int n, vetor[8], i = 7, j = i;

    scanf("%d", &n);
    if((n < 0) || (n > 255)){
        printf("Numero invalido!");
    }
    else if(n >= 2){
        while(n / 2 > 0){
            vetor[i] = n % 2;
            n  /= 2;
            i--;
            j--;
        }

        for(i = 0 ; i < j; i++){
            vetor[i] = 0;
        }

        vetor[j] = 1;

        for(i = 0; i < 8; i++){
            printf("%d", vetor[i]);
        }
    }
    else if(n == 1){
        for(i = 0; i < j; i++){
            printf("%d", vetor[i] = 0);
        }
        printf("%d", vetor[i] = 1);
    }
    else{
        for(i = 0; i < 8; i++){
            printf("%d", vetor[i] = 0);
        }
    }
    return 0;
}
