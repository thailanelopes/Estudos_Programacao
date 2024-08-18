#include <stdio.h>

double compute_pi(int n);

int main(){

    int valor;
    scanf("%d", &valor);

    double pi;

    pi = compute_pi(valor);

    printf("%.12lf\n", pi);

    return 0;
}

double compute_pi(int n){
    double pi, denominador, numerador;
    int i;

    pi = 1.0;
    numerador = 2.0;
    denominador = 1.0;

    for(i = 1; i <= n; i++){
        pi *= (numerador / denominador);
        if(i % 2 == 1){
            denominador += 2.0;
        }
        else{
            numerador += 2.0;
        }
    }

    pi *= 2.0;

    return pi;
}
