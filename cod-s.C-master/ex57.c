#include <stdio.h>

int main(){

    int n, k;
    scanf("%d %d", &n, &k);

    int alunos[n], i, cedo, pos;

    cedo = 0;
    for(i = 0; i < n; i++){
        scanf("%d", &alunos[i]);
        if(alunos[i] <= 0){
            cedo++;
        }
    }
    if(cedo < k){
        printf("SIM\n");
    }
    else{
        pos = 0;
        printf("NAO\n");
        for(i = n-1; i >= 0; i--){
            if(alunos[i] <= 0){
                printf("%d\n", i+1);
            }
        }
    }
    return 0;
}
