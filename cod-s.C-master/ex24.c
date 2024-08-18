#include <stdio.h>

int main(){

    float sal;

    scanf("%f", &sal);

    if(sal <= 300){
        sal *= 1.5;
    }
    else{
        sal *= 1.3;
    }

    printf("SALARIO COM REAJUSTE = %.2f\n", sal);
    return 0;
}
