#include <stdio.h>

int main(){

    int i, r, n, an, soma;
    scanf("%d %d %d", &i, &r, &n);

    an = i + (n-1) * r;
    soma = (n*(i + an))/2;

    printf("%d\n", soma);

    return 0;
}
