#include<stdio.h>
#include<stdlib.h>

typedef struct no* PONT;

typedef struct no{
    int valor;
    PONT esq;
    PONT dir;
}no;

PONT cria(int valor){
    PONT p=(PONT)malloc(sizeof(no));
    if(p!= NULL){
        p->valor=valor;
        p->esq=NULL;
        p->dir=NULL;
        return p;
    }
    return 0;
}
 PONT insereElemento(PONT raiz,PONT no ){
    if(raiz==NULL){
        return no;
    }
    else{
        if(raiz->valor > no->valor){
            raiz->esq= insereElemento(raiz->esq, no);
        }
        else{
            raiz->dir= insereElemento(raiz->dir, no);
        }
        return raiz;
    }

 }
void printa_arvore(PONT r){
    if(r!= NULL){

        printa_arvore(r->esq);
        printf("%d ",r->valor);
        printa_arvore(r->dir);
    }


}

int somarFolhas(PONT raiz){
    if(raiz==NULL)
        return 0;
    if(!raiz->esq && !raiz->dir)
        return 1;
    return somarFolhas(raiz->esq)+somarFolhas(raiz->dir);


}





int main (){
    PONT raiz;
    raiz=NULL;
    PONT no;

    int saida=0;
    int valor;
    while(saida<3){
        printf("digite um valor para inserir: ");
        scanf("%d",&valor);
        no=cria(valor);
       // printf("deu certo");
        raiz=insereElemento(raiz,no);

        saida++;


    }
    printa_arvore(raiz);
    printf("%d",somarFolhas(raiz));
}
