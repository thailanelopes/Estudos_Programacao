#include <stdio.h>

int main(){

    int n;
    scanf("%d", &n);

    int v[n], i;

    for(i = 0; i < n; i++){
        scanf("%d", &v[i]);
    }
    for(i = 0; i < n; i++){
        printf("%d ", v[i]);
    }

    return 0;
}
