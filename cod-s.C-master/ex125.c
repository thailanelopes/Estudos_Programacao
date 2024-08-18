#include <stdio.h>

int main(){

    float m[2][2], d;
    int j, i;

    for(i = 0; i < 2; i++){
        for(j = 0; j < 2; j++){
            scanf("%f", &m[i][j]);
        }
    }

    d = (m[0][0]*m[1][1]) - (m[0][1]*m[1][0]);

    printf("%.2f\n", d);

    return 0;
}
