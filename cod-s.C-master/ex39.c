#include <stdio.h>
#include <stdlib.h>

int main(){
    float vet[4], aux;
    int i, j, opc;

    scanf("%d", &opc);

    for(i = 0; i < 3; i++){
        scanf("%f", &vet[i]);
    }

    for(i = 0; i < 3; i++){
        for( j=i+1; j<3; j++ ){
            if( vet[i] > vet[j] ){
                aux = vet[i];
                vet[i] = vet[j];
                vet[j] = aux;
            }
        }
    }
    if(opc == 1){
        for (i = 0; i < 3; i++){
            if(i < 3-1){
                printf("%.2f ", vet[i]);
            }
            else{
                printf("%.2f\n", vet[i]);
            }
        }
    }
    else if(opc == 2){
        for (i = 2; i >= 0; i--){
            if(i > 0){
                printf("%.2f ", vet[i]);
            }
            else{
                printf("%.2f\n", vet[i]);
            }
        }

    }
    else{
        printf("%.2f %.2f %.2f\n", vet[1], vet[2], vet[0]);
    }

}

