#include <stdio.h>

int main(){

    int n;
    int fator;
    int mult;
    int i;

    while(1){
        scanf("%d", &n);
        if(n > 1){
            break;
        }
        printf("Fatoracao nao e possivel para o numero %d!\n", n);
    }


    fator = 2;
    printf("%d = ", n);
    while(n > 1){
        mult = 0;
        while (n % fator == 0){
            mult ++;
            n = n / fator;
        }
        if(mult != 0){
            for(i = 0; i < mult; i++){
                if(n > 1){
                    printf("%d x ", fator);
                }
                else{
                    printf("%d\n", fator);
                }
            }
        }
        fator++;
    }
    return 0;
}
