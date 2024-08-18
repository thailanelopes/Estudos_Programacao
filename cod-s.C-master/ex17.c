#include <stdio.h>

int main(){

    int n, i = 0;

    scanf("%d", &n);

    while(n > 0){
        i *= 10;
        i += (n % 10);
        n /= 10;
    }
    printf("%d\n", i);

    return 0;
}
