#include <stdio.h>

int main(){

    int n, a1, a2, a3, a4, r;

    scanf("%d", &n);

    r = n;

    a3 = n % 10;
    n /= 10;

    a2 = n % 10;
    n /= 10;

    a1 = n;

    a4 = (a1 + a2 * 3 + a3 * 5) % 7;

    r = r * 10 + a4;

    printf("O NOVO NUMERO E = %d\n", r);


    return 0;
}
