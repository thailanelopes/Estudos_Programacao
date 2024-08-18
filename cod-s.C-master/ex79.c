#include <stdio.h>

int main(){

    double n, e;
    scanf("%lf %lf", &n, &e);

    int i;
    double b, a, err;

    a = 1;
    b = n/1;

    do{
        a = (a+b)/2;
        b = n/a;
        err = n-(a*a);

        if(err < 0){
            err *= -1;
        }

        printf("r: %.9lf, err: %.9lf\n", a, err);

    }while(err > e);

    return 0;
}
