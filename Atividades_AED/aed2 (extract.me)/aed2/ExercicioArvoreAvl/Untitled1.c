#include<stdio.h>
#include<stdlib.h>


typedef struct Arvore{
    int alt;
    int valor;
    struct Arvore *esq;
    struct Arvore *dir;
}Arvore;

typedef struct Arvore* AVL;

int inserindoValores(AVL* raiz,int valor){
    int resposta;
    if((*raiz)==NULL){

        Arvore *novo=(Arvore*)malloc(sizeof(Arvore));
        novo->alt=0;
        novo->valor=valor;
        novo->esq=NULL;
        novo->dir=NULL;
        (*raiz)=novo;
        return 1;
    Arvore* atual= (*raiz);
    }
    if(valor<atual->valor){
        if(resposta=inserindoValores(&(atual->esq),valor)==1){
            if()
        }
    }
    else
        if(valor>atual->valor){
            if(resposta=inserindoValores(&(atual->dir),valor)==1){
                if()
            }
    }
}





int main(){
        AVL *raiz;


        int quantidade;
        printf("DIGITE A QUANTIDADE DE VALORES PARA INSERIR : ");
        scanf("%d",&quantidade);
        int i=0;

        for(i=0;i<quantidade;i++){
            inserindoValores(&(raiz),valor);
        }

}
