#include <stdio.h>

int main(){

    int A;
    float B, C, sal;

    while(1){
        scanf("%d %f %f", &A, &B, &C);
        getchar();

        if(A == 0 && B == 0 && C == 0){
            break;
        }

        sal = B*C;

        printf("%d %.2f\n", A, sal);
    }



    return 0;
}
