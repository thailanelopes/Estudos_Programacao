#include <stdio.h>

int main(){

    int n, m, c, d, u;
    scanf("%d", &n);

    if(n < 1 && n > 9999){
        printf("Numero invalido!\n");
    }
    else{
        u = n % 10;
        d = (n / 10) % 10;
        c = (n / 100) % 10;
        m = (n / 1000) % 10;

        if(n > 999){
            printf("(quarta ordem) %d = %d unidade de milhar + %d centenas + %d dezenas + %d unidades = %d + %d + %d + %d\n", n, m, c, d, u, m * 1000, c * 100, d * 10, u);
        }
        else if(n <= 999 && n > 99){
            if(d != 0){
                printf("(terceira ordem) %d = %d centenas + %d dezenas + %d unidades = %d + %d + %d\n", n, c, d, u, c * 100, d * 10, u);
            }
            else{
                printf("(terceira ordem) %d = %d centenas + %d unidades = %d + %d\n", n, c, u, c * 100, u);
            }
        }
        else{
            printf("(segunda ordem) %d = %d dezena + %d unidade\n", n, d, u);
        }
    }
    return 0;
}
