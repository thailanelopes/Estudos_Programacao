#include <stdio.h>
#include <math.h>

int raizesEq2Grau(int a, int b, int c);

int main(){

    int x, y, z, retorno;

    scanf("%d %d %d", &x, &y, &z);

    retorno = raizesEq2Grau(x, y, z);

    if(retorno == 0){
        printf("RAIZES IMAGINARIAS\n");
    }
    else{
        float x1, x2, delta;

        delta = y*y-4*x*z;
        x1 = (-y + sqrt(delta))/(2.0*x);
        x2 = (-y - sqrt(delta))/(2.0*x);


        if(retorno == 1){
            printf("RAIZ UNICA\n");
            printf("X1 = %.2f\n", x1);
        }
        else if(retorno == 2){
            printf("RAIZES DISTINTAS\n");
            printf("X1 = %.2f\n", x1);
            printf("X2 = %.2f\n", x2);

        }
    }

    return 0;
}

int raizesEq2Grau(int a, int b, int c){
    int delta;

    delta = b*b-4*a*c;

    if(delta < 0){
        return 0;
    }
    else if(delta == 0){
        return 1;
    }
    else{
        return 2;
    }

}
