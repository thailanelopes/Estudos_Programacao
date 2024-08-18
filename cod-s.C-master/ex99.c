#include <stdio.h>

int main(){

    int k;
    float n, i, s, inicio, teste;

    scanf("%f %f %d %f", &n, &i, &k, &s);

    printf("Tabuada de soma:\n");
    inicio = i;
    teste = k;
    while(teste--){
        printf("%.2f + %.2f = %.2f\n", n, inicio, n+inicio);
        inicio += s;
    }
    printf("Tabuada de subtracao:\n");
    inicio = i;
    teste = k;
    while(teste--){
        printf("%.2f - %.2f = %.2f\n", n, inicio, n-inicio);
        inicio += s;
    }
    printf("Tabuada de multiplicacao:\n");
    inicio = i;
    teste = k;
    while(teste--){
        printf("%.2f x %.2f = %.2f\n", n, inicio, n*inicio);
        inicio += s;
    }
    printf("Tabuada de divisao:\n");
    inicio = i;
    teste = k;
    while(teste--){
        printf("%.2f / %.2f = %.2f\n", n, inicio, n/inicio);
        inicio += s;
    }

    return 0;
}
