#include <stdio.h>

int main(){
    int fat, n, i;
    scanf("%d", &n);

    i = n;
    for(fat = 1; n > 1; n = n - 1){
        fat = fat * n;
    }

    printf("%d! = %d\n", i, fat);

    return 0;
}
