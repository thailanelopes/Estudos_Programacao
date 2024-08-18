#include <stdio.h>

int main(){
    // Definindo tamanho da linha e coluna da matriz respectivamente, sendo 1 < n, m <= 1000
    int m, n;
    // m
    do{
        scanf("%d", &m);
    }while(m < 1 || m > 1000);
    // n
    do{
        scanf("%d", &n);
    }while(n < 2 || n > 1000);

    int matriz[m][n], i, j, max, min;
    float freq_max = 0, freq_min = 0;
    // Inserindo elementos na matriz, e pegando minímo e maior valor
    for(i = 0; i < m; i++){
        for(j = 0; j < n; j++){
            scanf("%d", &matriz[i][j]);
            if(i == 0 && j == 0){
                max = matriz[i][j];
                min = matriz[i][j];
            }
            else{
                if(matriz[i][j] > max){
                    max = matriz[i][j];
                }
                if(matriz[i][j] < min){
                    min = matriz[i][j];
                }
            }
        }
    }
    // Pegando ferquencia do maior e menor valor da matriz
    for(i = 0; i < m; i++){
        for(j = 0; j < n; j++){
            // frequência maior
            if(max == matriz[i][j]){
                freq_max++;
            }
            // frequência menor
            if(min == matriz[i][j]){
                freq_min++;
            }
        }
    }
    // Calculando frequência do maior e menor valor respectivamente
    freq_max = (freq_max*100) / (m*n);
    freq_min = (freq_min*100) / (m*n);
    // Imprimindo frequêcia do menor e maior valor respectivamente
    printf("%d %.2f%%\n", min, freq_min);
    printf("%d %.2f%%\n", max, freq_max);

    return 0;
}
