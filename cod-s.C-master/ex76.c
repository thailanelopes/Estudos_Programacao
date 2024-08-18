#include <stdio.h>

void interceptoEmX(float a, float b);
void interceptoEmY(float a, float b);

int main(){

    int casos;
    float a, b;

    scanf("%d", &casos);

    while(casos--){
        scanf("%f %f", &a, &b);

        interceptoEmX(a, b);
        interceptoEmY(a, b);
    }

    return 0;
}

void interceptoEmX(float a, float b){

    float x;

    x = -b/a;

    printf("Intercepto em x: (%.2f, 0.00)\n", x);
}

void interceptoEmY(float a, float b){

    float y;

    y = b;

    printf("Intercepto em y: (0.00, %.2f)\n", y);
}
