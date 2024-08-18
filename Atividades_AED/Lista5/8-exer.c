#include <stdio.h>

int main(){
	
	int i, j;

    int tam;
    scanf("%d", &tam);
    
    int vet[tam];

	double multi = 1;
	
    for(i = 0; i < tam; i++){
        scanf("%d", &vet[i]); 
        multi *= vet[i]; 
    }

    int novoValor = 0;
    double testandoMulti;


    i = 1;
    while(1){
		testandoMulti = 1;
        for(j = 0; j < tam; j++){
            testandoMulti *= i;
        }
        if(testandoMulti > multi){
            novoValor = i;
            break;
        }
        i++;
    }

	
    for(i = 0; i < tam; i++){
        vet[i] = novoValor;
    }


    for(i = 0; i < tam; i++){
        printf("%d ", vet[i]);
    }
}