#include <stdio.h>
#include <string.h>

int main(){
    int N;
    scanf("%d\n", &N);

    int i, x, y, r;
    char nome[N][32];
    char aux[32];

    for(i = 0; i < N; i++){
        scanf("%s", nome[i]);
    }
    for(x = 0; x < N; x++){
        for(y = x+1; y < N; y++){
            r = strcmp(nome[x], nome[y]);
            if(r > 0){
                strcpy(aux, nome[x]);
                strcpy(nome[x], nome[y]);
                strcpy(nome[y], aux);
            }
        }
    }
    for(i = 0; i < N; i++){
        puts(nome[i]);
    }


    return 0;
}
