#include <stdio.h>

int main(){

    int n;
    scanf("%d", &n);

    int v[n], i, qntd = 0;

    for(i = 0; i < n; i++ ){
        scanf("%d", &v[i]);
    }
    for(i = 0; i < n; i++ ){
        if(v[i] % 2 == 0){
            printf("%d ", v[i]);
            qntd++;
        }
    }
    printf("%d\n", qntd);

    return 0;
}
