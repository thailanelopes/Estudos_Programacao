#include <stdio.h>

int main(void){

    int n, f1, f2;
    scanf("%d %d %d", &n, &f1, &f2);

    int i, fib1 = f1, fib2 = f2, soma, x = 2;
    int sequencia[n], fibonacci[n], nao;

    for(i = 0; i < n; i++){
        scanf("%d", &sequencia[i]);
    }
    fibonacci[0] = f1;
    fibonacci[1] = f2;

    for (i = 3; i <= n; i = i + 1){
        soma = fib1 + fib2;
        fib1 = fib2;
        fib2 = soma;
        fibonacci[x] = fib2;
        x++;
    }

    nao = 0;
    for(i = 0; i < n; i++){
        if(sequencia[i] == fibonacci[i]){
            printf("OK\n");
            continue;
        }
        nao = 1;
        break;
    }

    if(nao == 1){
        printf("Nao e Fibonacci\n");
    }
    else{
        printf("A serie informada e de Fibonacci\n");
    }

    return 0;
}

