#include <stdio.h>

int main(){

    float n;
    scanf("%f", &n);

    if((n >= 9) && (n <= 10)){
        printf("NOTA = %.1f CONCEITO = A\n", n);
    }
    else if((n >= 7.5) && (n < 9)){
        printf("NOTA = %.1f CONCEITO = B\n", n);
    }
    else if((n >= 6) && (n < 7.5)){
        printf("NOTA = %.1f CONCEITO = C\n", n);
    }
    else{
        printf("NOTA = %.1f CONCEITO = D\n", n);
    }

    return 0;
}
