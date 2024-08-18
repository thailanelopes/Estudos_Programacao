#include <stdio.h>
#include <math.h>

int main(){

    float n;
    scanf("%f", &n);

    printf("%.6f\n", round(n * 10)/10.0);
    printf("%.6f\n", round(n * 100)/100.0);
    printf("%.6f\n", round(n * 1000)/1000.0);

    //Se for uma casa decimal divide e multiplica por 10, duas casas (100), se for três (1000) , etc

    return 0;
}
