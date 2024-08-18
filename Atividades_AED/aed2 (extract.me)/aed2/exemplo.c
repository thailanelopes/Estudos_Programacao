
#include<stdio.h>
#include<stdlib.h>




struct No{
    int numero;
    struct No *esquerda;
    struct No *direita;
};
typedef struct No No;



void inserir(No **pRaiz, int numero){
    if(*pRaiz == NULL){
        *pRaiz = (No *) malloc(sizeof(No));
        (*pRaiz)->esquerda = NULL;
        (*pRaiz)->direita = NULL;
        (*pRaiz)->numero = numero;
    }else{
        if(numero < (*pRaiz)->numero)
            inserir(&(*pRaiz)->esquerda, numero);
        if(numero > (*pRaiz)->numero)
            inserir(&(*pRaiz)->direita, numero);
    }
}







int main (){
   struct    NO** raiz=NULL;

    int saida=0;
    int valor;
    while(saida<5){
        printf("digite um valor para inserir: ");
        scanf("%d",&valor);
        inserir(&raiz,valor);
        printf("passou");
        saida++;
    }

}



