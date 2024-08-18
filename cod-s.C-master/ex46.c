#include <stdio.h>

int main(){

    int n, i, soma = 0;
    scanf("%d", &n);

    int v[n];

    for(i = 0; i < n; i++){
        scanf("%d", &v[i]);
        soma += v[i];
    }

    printf("%d\n", soma);

    return 0;
}
