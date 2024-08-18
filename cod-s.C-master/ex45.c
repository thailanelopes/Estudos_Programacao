#include <stdio.h>

int main(){

    int n, i, maior, pos;

    do{
        scanf("%d", &n);

        if(n == 0){
            break;
        }

        int v[n];

        maior = 0;
        pos = 0;
        for(i = 0; i < n; i++){
            scanf("%d", &v[i]);
            if(v[i] > maior){
                maior = v[i];
                pos = i;
            }
        }

        printf("%d %d\n", pos, maior);


    }while(n != 0);

    return 0;
}
