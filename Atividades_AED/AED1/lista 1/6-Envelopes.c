#include<stdio.h>

main(){

int i, j;

// k = numero de tipos de bala que SBC produz
// n = quantidade de rótulos de balas que Kurt possui
int n, k;

scanf("%d %d", &n, &k);

int v[n];
for(i = 0; i < n; i++){
    scanf("%d", &v[i]);
}

int quantidadetipos[k];

for(i = 0; i < k; i++){
    quantidadetipos[i] = 0;
}

for(i = 0; i < n; i++){
    for(j = 0; j < k; j++){
        if(v[i] == j+1){
            quantidadetipos[j] ++;
        }
    }
}
int menor = quantidadetipos[0];
for(i = 1; i < k; i++){
   if(quantidadetipos[i] < menor){
    menor = quantidadetipos[i];
   }
}

printf("%d", menor);

}