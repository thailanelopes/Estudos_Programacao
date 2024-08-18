#include <stdio.h>
#include <math.h>

int fibonacci( int t1, int t2, int n);


int main(){

    int x, y, z;
    scanf("%d %d %d", &x, &y, &z);

    printf("%d\n", fibonacci(x, y, z));

    return 0;
}

int fibonacci(int t1, int t2, int n){
    int termo , i;

    for(i = 0; i < n-2; i++){
        termo = t1+t2;
        t1 = t2;
        t2 = termo;
    }

    return termo;
}
