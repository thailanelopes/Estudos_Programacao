#include <stdio.h>
#include <math.h>

int main(){


    float  h, a, ab, v;

    scanf("%f %f", &h, &a);

    ab = (3*(a*a)*sqrt(3))/2;
    v = ((1.0/3.0) * ab * h);

    printf("O VOLUME DA PIRAMIDE E = %.2f METROS CUBICOS\n",v);

    return 0;
}
