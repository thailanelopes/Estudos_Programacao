#include <stdio.h>

int main(){

    int q1, q2, i, tam, j, aux;
    scanf("%d %d", &q1, &q2);

    tam = q1 + q2;

    int v1[q1], v2[q2], v3[tam];

    for(i = 0; i < q1; i++){
        while(1){
            scanf("%d", &v1[i]);
            if(i == 0){
                aux = v1[i];
                break;
            }
            else if(aux > v1[i]){
            }
            else{
                aux = v1[i];
                break;
            }
        }
    }
    for(i = 0; i < q2; i++){
        while(1){
            scanf("%d", &v2[i]);
            if(i == 0){
                aux = v2[i];
                break;
            }
            else if(aux > v2[i]){
            }
            else{
                aux = v2[i];
                break;
            }
        }
    }
    j = 0;
    for(i = 0; i < q1; i++){
        v3[i] = v1[i];
    }
    for(i = q1; i < tam; i++){
        v3[i] = v2[j];
        j++;
    }

    aux = 0;
    for(i = 0; i < tam; i++){
        for(j = i+1; j < tam; j++){
            if(v3[i] > v3[j]){
                aux = v3[j];
                v3[j] = v3[i];
                v3[i] = aux;
            }
        }
    }

    for(i = 0; i < tam; i++){
        printf("%d\n", v3[i]);
    }

    return 0;
}
