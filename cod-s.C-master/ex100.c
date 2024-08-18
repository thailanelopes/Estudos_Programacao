#include <stdio.h>

int main(){

    int n, np = 0, ni = 0;
    float mp = 0, mi = 0;

    while(1){
        scanf("%d", &n);

        if(n == 0){
            break;
        }
        if(n % 2 == 0){
            mp += n;
            np++;
        }
        else{
            mi += n;
            ni++;
        }
    }

    printf("MEDIA PAR = %.6f\n", mp/np);
    printf("MEDIA IMPAR = %.6f\n", mi/ni);

    return 0;
}
