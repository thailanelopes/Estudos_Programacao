#include <stdio.h>

struct structsapos {
    int posicaoinicial;
    int distanciapulo;
};

main(){

int p, s, i;
int conta;

scanf("%d %d", &p, &s);

struct structsapos sapos[s];
for(i=0; i<s; i++){
    scanf("%d", &sapos[i].posicaoinicial);
    scanf("%d", &sapos[i].distanciapulo);
}


int pedras[p];
for(i=0; i<p; i++){
    pedras[i] = 0;
}

for(i=0; i<s; i++){

    conta = 0;
    while(sapos[i].posicaoinicial - conta > 0){
        int j = sapos[i].posicaoinicial - conta ;
        pedras[j -1] = 1;
        conta = conta + sapos[i].distanciapulo;
    }

    conta = 0;
    while(sapos[i].posicaoinicial + conta <= p){
        int j = sapos[i].posicaoinicial + conta ;
        pedras[j -1] = 1;
        conta = conta + sapos[i].distanciapulo;
    }
}

for(i=0; i<p; i++){
    printf("%d\n", pedras[i]);
}
}