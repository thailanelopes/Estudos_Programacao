#include <stdio.h>

int main(){

    // Definindo largura, altura, espessura da borda e valor da borda da matriz respectivamente
    int m, n, b, v;
    scanf("%d %d %d %d", &m, &n, &b, &v);

    int i, j;

    printf("P2\n");
    printf("%d %d\n", m, n);
    printf("255\n");
    // desenhando matriz
    for (i = 0; i < m; i++){
        for(j = 0; j < n; j++){
            if(i < b || i >= m - b){
                printf("%d ", v);
            }
            else {
                if(j < b || j >= n - b){
                    printf("%d ", v);
                }
                else{
                    printf("0 ");
                }
            }
        }
        printf("\n");
    }

    return 0;
}
