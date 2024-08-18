#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){

    char numero[31];
    int cont, i, j;

    scanf("%s", numero);
    setbuf(stdin, NULL);

    cont = 0;
    for(i = 0; i < 30; i++){
        if(numero[i] == '.'){
            for(j = i+1; numero[j] != '\0'; j++){
                cont++;
            }
            break;
        }
    }

    int denominador, numerador;
    float num;

    num = atof(numero);
    denominador = pow(10, cont);
    numerador = num*denominador;

    for(i = 2; i < numerador && i < denominador; i++){
        if(numerador % i == 0 && denominador % i == 0){
            numerador = numerador/i;
            denominador = denominador/i;
        }
    }

    printf("%d/%d\n", numerador, denominador);

    return 0;
}
