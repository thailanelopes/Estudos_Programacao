#include <stdio.h>

int main(){

    int n, x, i;
    scanf("%d", &n);

    if(n < 0){
        printf("Numero invalido!\n");
    }
    else{
        x = 0;
        for(i = 1; i <= n; i++){
            if(n % i == 0){
                x++;
            }
        }
        if(x == 2){
            printf("PRIMO\n");
        }
        else{
            printf("NAO PRIMO\n");
        }
    }

    return 0;
}
