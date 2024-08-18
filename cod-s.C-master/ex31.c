#include <stdio.h>

int main(){

    int n, ano, mes, dia;

    scanf("%d", &n);

    ano = n % 10000;
    mes = (n  % 1000000) / 10000;
    dia = n / 1000000;

    if((ano % 4 == 0 && (ano % 400 == 0 || ano % 100 != 0)) || n <= 9999999 || n > 99999999 || (mes > 12 || mes < 1 || dia > 31 || dia < 1)){
        printf("Data invalida!\n");
    }
    else if(mes == 2 && dia > 28){
        printf("Data invalida!\n");
    }
    else{
        if(mes == 1){
            printf("%d de janeiro de %d\n", dia, ano);
        }
        else if(mes == 2){
            printf("%d de fevereiro de %d\n", dia, ano);
        }
        else if(mes == 3){
            printf("%d de marco de %d\n", dia, ano);
        }
        else if(mes == 4){
            printf("%d de abril de %d\n", dia, ano);
        }
        else if(mes == 5){
            printf("%d de maio de %d\n", dia, ano);
        }
        else if(mes == 6){
            printf("%d de junho de %d\n", dia, ano);
        }
        else if(mes == 7){
            printf("%d de julho de %d\n", dia, ano);
        }
        else if(mes == 8){
            printf("%d de agosto de %d\n", dia, ano);
        }
        else if(mes == 9){
            printf("%d de setembro de %d\n", dia, ano);
        }
        else if(mes == 10){
            printf("%d de outubro de %d\n", dia, ano);
        }
        else if(mes == 11){
            printf("%d de novembro de %d\n", dia, ano);
        }
        else if(mes == 12){
            printf("%d de dezembro de %d\n", dia, ano);
        }
    }

    return 0;
}
