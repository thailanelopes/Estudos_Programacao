#include <stdio.h>

int main(){

    int n;
    do{
        scanf("%d", &n);
    }while((n < 1) || (n > 1000));

    int i, v[n], k, elementos = 0;

    for(i = 0; i < n; i++){
        scanf("%d", &v[i]);
    }

    scanf("%d", &k);

    for(i = 0; i < n; i++){
        if(v[i] >= k){
            elementos += 1;
        }
    }

    printf("%d\n", elementos);


    return 0;
}
