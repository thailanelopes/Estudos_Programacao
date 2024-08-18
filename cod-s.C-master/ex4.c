#include <stdio.h>

int main(){

    int h, m, s, tot_s;

    scanf("%d %d %d", &h, &m, &s);

    tot_s = (h*3600) + (m * 60) + s;

    printf("O TEMPO EM SEGUNDOS E = %d\n", tot_s);

    return 0;
}
