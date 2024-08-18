#include <stdio.h>

int main(){
    int matriz[6][6] =  {{0, 63, 210, 190, -1, 190},
                        {63, 0, 160, 150, 95, 10},
                        {210, 160, 0, 10, 1, 10},
                        {190, 150, 10, 0, 10, 20},
                        {10, 95, 7, 21, 0, 80},
                        {190, 2, -1, 41, 80, 0}};

    int n;
    scanf("%d", &n);

    int vetor[n], i, a, b, total = 0;

    for(i = 0; i < n; i++){
        scanf("%d", &vetor[i]);
    }
    for(i = 0; i < n-1; i++){
        a = vetor[i];
        b = vetor[i+1];

        if(matriz[a][b] == -1){
            total = -1;
            break;
        }
        else{
            total += matriz[a][b];
        }
    }

    if(total == -1){
        printf("rota invalida!\n");
    }
    else{
        printf("%d\n", total);
    }

    return 0;
}
