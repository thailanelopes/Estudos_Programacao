
#include <stdio.h>

int main(){

    int t, n, i, j, dist, d;

    scanf("%d", &t);

    while(t--){

        scanf("%d", &n);

        int vetor[n];

        for(i = 0; i < n; i++){
            scanf("%d", &vetor[i]);
        }

        for(i = 0; i < n; i++){
            for(j = i+1; j < n; j++){
                d = vetor[i] - vetor[j];
                if(d < 0){
                    d = d * -1;
                }
                if(i == 0){
                    dist = d;
                }
                else if(dist > d){
                    dist = d;
                }
            }
        }

        printf("%d %d\n", dist, n*n);
    }

    return 0;
}
