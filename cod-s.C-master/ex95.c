#include <stdio.h>

int main(){

    int n;
    double soma, i;

    scanf("%d", &n);

    if(n <= 1){
        printf("Numero invalido!\n");
    }
    else{
        soma = 0;
        i = 1.0;
        while(n--){
            soma += 1/i;
            i++;
        }
        printf("%.6lf\n", soma);
    }


    return 0;
}
