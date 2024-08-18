#include <stdio.h>

int main(){

    int n;
    scanf("%d", &n);

    int v[n], i, j, m, num, achou = 0;

    for(i = 0; i < n; i++){
        scanf("%d", &v[i]);
    }

    scanf("%d", &m);

    for(i = 0; i < m; i++){
        scanf("%d", &num);
        for(j = 0; j < n; j++){
            if(num == v[j]){
                achou = 1;
                break;
            }
        }
        if(achou == 1){
            printf("ACHEI\n");
        }
        else{
            printf("NAO ACHEI\n");
        }
        achou = 0;
    }


    return 0;
}
