#include <stdio.h>
#include <math.h>

int main(){

    int T;
    scanf("%d", &T);

    int A, B, invertidoA, invertidoB, maior, i;

    while(T--){
        scanf("%d %d", &A, &B);

        invertidoA = 0;
        for(i = 2; i >= 0; i--){
            invertidoA += (A % 10) * (pow(10, i));
            A /= 10;
        }
        invertidoB = 0;
        for(i = 2; i >= 0; i--){
            invertidoB += (B % 10) * (pow(10, i));
            B /= 10;
        }

        if(invertidoA > invertidoB){
            maior = invertidoA;
        }
        else{
            maior = invertidoB;
        }
        printf("%d\n", maior);
    }
    return 0;
}
