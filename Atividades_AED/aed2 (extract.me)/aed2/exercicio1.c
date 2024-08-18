#include<stdio.h>
#include<stdlib.h>



typedef struct no* ArvoreBin ;

typedef struct no{
    int valor ;
    struct   no* esq;
    struct no* dir;
}no;

typedef struct ArvoreBin* raiz;

void inserir(ArvoreBin *raiz, int numero){
    if((*raiz) == NULL){
        (*raiz) = (ArvoreBin) malloc(sizeof( no));
        ((*raiz))->esq = NULL;
        ((*raiz))->dir = NULL;
        ((*raiz))->valor = numero;
    }else{
        if(numero < ((*raiz))->valor)
            inserir(&((*raiz))->esq, numero);
        if(numero > ((*raiz))->valor)
            inserir(&((*raiz))->dir, numero);
    }
}
void printa(no* raiz){
    if(raiz != NULL){
        //printf("lha so %d",raiz->valor);
        printa(raiz->esq);
        printf("%d",raiz->valor);
        printa(raiz->dir);

    }


}

no *MaiorDireita(no **no)
{
    if((*no)->dir != NULL)
    {
       return MaiorDireita(&(*no)->dir);
    }
    else
    {
     struct  no *aux = *no;

       if((*no)->esq != NULL)
        {
          *no = (*no)->esq;
        }
        else
        {
            *no = NULL;
            return aux;
        }
    }

}




void remover(no **raiz, int numero){
    if(((*raiz)->valor%2)==0){
        numero=(((*raiz)->valor)/2);
    }
    if((*raiz) == NULL){
       printf("Numero nao existe na arvore!");
       getch();
       return;
    }
    if(numero < (*raiz)->valor)
       remover(&(*raiz)->esq, numero);
    else
       if(numero > (*raiz)->valor)
          remover(&(*raiz)->dir, numero);
       else{
          no *pAux = (*raiz);
          if (((*raiz))->esq == NULL && ((*raiz))->dir == NULL){
                free(pAux);
                (*raiz) = NULL;
               }
          else{
             if ((*raiz)->esq == NULL){
                (*raiz) = (*raiz)->dir;
                pAux->dir = NULL;
                free(pAux); pAux = NULL;
                }
             else{
                if ((*raiz)->dir == NULL){
                    (*raiz) = (*raiz)->esq;
                    pAux->esq = NULL;
                    free(pAux); pAux = NULL;
                    }
                else{
                   pAux = MaiorDireita(&(*raiz)->esq);
                   pAux->esq= (*raiz)->esq;
                   pAux->dir = (*raiz)->dir;
                   (*raiz)->esq = (*raiz)->dir = NULL;
                   free((*raiz));  (*raiz) = pAux;  pAux = NULL;
                   }
                }
             }
          }
}







int main (){
    ArvoreBin* raiz=NULL;

    int saida=0;
    int valor;
    while(saida<5){
        printf("digite um valor para inserir: ");
        scanf("%d",&valor);
        inserir(&raiz,valor);
        printf("passou");
        saida++;
    }
    printa(raiz);
    remover(&raiz,0);
    printf("\n");
     printa(raiz);

}
