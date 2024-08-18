#pragma hdrstop
#pragma argsused
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

// Controlador de linha impressa com dados da pilha
int Lin;

// Definições da Pilha
typedef struct elemento* Pilha;

struct elemento{
    struct NO *dados;
    struct elemento *prox;
};

typedef struct elemento Elem;


// Definições da Árvore
typedef struct NO* ArvBin;

struct NO {
    int info;
    struct NO *esq;
    struct NO *dir;
};



Pilha* cria_Pilha();
void libera_Pilha(Pilha* pi);
//int consulta_topo_Pilha(Pilha* pi, struct NO **al);
int consulta_topo_Pilha(Pilha* pi, ArvBin *e);
//void libera_ArvBin(ArvBin *raiz);

//int insere_Pilha(Pilha* pi, struct aluno al);
//int insere_Pilha(Pilha* pi, struct NO **al);
//int insere_Pilha(Pilha* pi, ArvBin *e);
int insere_Pilha(Pilha* pi, struct NO *al);

//void libera_ArvBin(ArvBin *raiz);


int remove_Pilha(Pilha* pi);
int tamanho_Pilha(Pilha* pi);
int Pilha_vazia(Pilha* pi);
int Pilha_cheia(Pilha* pi);
void imprime_Pilha(Pilha* pi);
// Fim definições da Pilha

ArvBin* cria_ArvBin();
void libera_ArvBin(ArvBin *raiz);
int insere_ArvBin(ArvBin* raiz, int valor);
//
int insere_EmLargura(ArvBin *raiz, int valor);
//void desenheSubarvore(ArvBin *raiz, char separator[]);
//void desenheSubarvore(ArvBin *raiz, int espacos, char separator[]);
void desenheSubarvore(ArvBin *raizAbsoluta, ArvBin *raiz, int espacos, char separator[]);
void desenheArvore(ArvBin *raiz);
struct NO* searchFather (ArvBin *raiz, int el);

int remove_ArvBin(ArvBin *raiz, int valor);
int estaVazia_ArvBin(ArvBin *raiz);
int altura_ArvBin(ArvBin *raiz);
int totalNO_ArvBin(ArvBin *raiz);
int consulta_ArvBin(ArvBin *raiz, int valor, int *info);
int consulta_ArvBinRec(ArvBin *raiz, int valor, int *info);
void preOrdem_ArvBin(ArvBin *raiz);
void emOrdem_ArvBin(ArvBin *raiz);
void posOrdem_ArvBin(ArvBin *raiz);
void emOrdem_ArvBinNaoRec(ArvBin *raiz);
// 
int totalNO_ArvBin_Iter(ArvBin *raiz);
int altura_ArvBin_Iter(ArvBin *raiz);
// Fim Definições da Árvore

// IMPLEMENTAÇÕES REF. À ÁRVORE
ArvBin* cria_ArvBin(){
    ArvBin* raiz = (ArvBin*) malloc(sizeof(ArvBin));
    if(raiz != NULL)
        *raiz = NULL;
    return raiz;
}

void libera_NO(struct NO* no){
    if(no == NULL)
        return;
    libera_NO(no->esq);
    libera_NO(no->dir);
    free(no);
    no = NULL;
}

void libera_ArvBin(ArvBin* raiz){
    if(raiz == NULL)
        return;
    libera_NO(*raiz);//libera cada nó
    free(raiz);//libera a raiz
}


int insere_ArvBin(ArvBin* raiz, int valor){
    struct NO* novo;

    if(raiz == NULL)
        return 0;
    novo = (struct NO*) malloc(sizeof(struct NO));
    if(novo == NULL)
        return 0;
    novo->info = valor;
    novo->dir = NULL;
    novo->esq = NULL;

    if(*raiz == NULL)
        *raiz = novo;
    else{
        struct NO* atual = *raiz;
        struct NO* ant = NULL;
        while(atual != NULL){
            ant = atual;
            if(valor == atual->info){
                free(novo);
                return 0;//elemento já existe
            }

            if(valor > atual->info)
                atual = atual->dir;
            else
                atual = atual->esq;
        }
        if(valor > ant->info)
            ant->dir = novo;
        else
            ant->esq = novo;
    }
    return 1;
}



struct NO* remove_atual(struct NO* atual) {
    struct NO *no1, *no2;
    if(atual->esq == NULL){
        no2 = atual->dir;
        free(atual);
        return no2;
    }
    no1 = atual;
    no2 = atual->esq;
    while(no2->dir != NULL){
        no1 = no2;
        no2 = no2->dir;
    }
    // no2 é o nó anterior a r na ordem e-r-d
    // no1 é o pai de no2
    if(no1 != atual){
        no1->dir = no2->esq;
        no2->esq = atual->esq;
    }
    no2->dir = atual->dir;
    free(atual);
    return no2;
}


// http://www.ime.usp.br/~pf/algoritmos/aulas/binst.html
int remove_ArvBin(ArvBin *raiz, int valor){
    struct NO* ant = NULL;
    struct NO* atual = *raiz;

    if(raiz == NULL)
        return 0;
    while(atual != NULL){
        if(valor == atual->info){
            if(atual == *raiz)
                *raiz = remove_atual(atual);
            else{
                if(ant->dir == atual)
                    ant->dir = remove_atual(atual);
                else
                    ant->esq = remove_atual(atual);
            }
            return 1;
        }
        ant = atual;
        if(valor > atual->info)
            atual = atual->dir;
        else
            atual = atual->esq;
    }
    return 0;
}

int estaVazia_ArvBin(ArvBin *raiz){
    if(raiz == NULL)
        return 1;
    if(*raiz == NULL)
        return 1;
    return 0;
}

int totalNO_ArvBin(ArvBin *raiz){
    int alt_esq, alt_dir;

    if (raiz == NULL)
        return 0;
    if (*raiz == NULL)
        return 0;
    alt_esq = totalNO_ArvBin(&((*raiz)->esq));
    printf("alt_esq de %i: %i ", (*raiz)->info, alt_esq);

    alt_dir = totalNO_ArvBin(&((*raiz)->dir));
    printf("alt_dir de %i: %i ", (*raiz)->info, alt_esq);
    return(alt_esq + alt_dir + 1);
}


int altura_ArvBin(ArvBin *raiz){
  int alt_esq, alt_dir;
    if (raiz == NULL)
        return 0;
    if (*raiz == NULL)
        return 0;
        
    alt_esq = altura_ArvBin(&((*raiz)->esq));
    printf("alt_esq de %i: %i ", (*raiz)->info, alt_esq);

    alt_dir = altura_ArvBin(&((*raiz)->dir));
    printf("alt_dir de %i: %i ", (*raiz)->info, alt_dir);
    if (alt_esq > alt_dir)
        return (alt_esq + 1);
    else
        return(alt_dir + 1);
}


int consulta_ArvBin(ArvBin *raiz, int valor, int *info)
{
    struct NO* atual = *raiz;

    if(raiz == NULL)
        return 0;

    while(atual != NULL){
        if(valor == atual->info){
           *info = atual->info;
           return 1;
        }
        if(valor > atual->info)
            atual = atual->dir;
        else
            atual = atual->esq;
    }
    return 0;
}

// Corrigir erro decorrente de quando o valor não é encontrado
int consulta_ArvBinRec(ArvBin *raiz, int valor, int *info)
{
    struct NO* atual = *raiz;

    if(raiz == NULL)
       return 0;

    if(valor == atual->info)
       return 1;
    else if(valor < atual->info)
       consulta_ArvBinRec(&((*raiz)->esq), valor, info);
    else
       consulta_ArvBinRec(&((*raiz)->dir), valor, info);
}


void preOrdem_ArvBin(ArvBin *raiz){
    if(raiz == NULL)
        return;

    if(*raiz != NULL){
        printf("%d, ",(*raiz)->info);
        preOrdem_ArvBin(&((*raiz)->esq));
        preOrdem_ArvBin(&((*raiz)->dir));
    }

}

void emOrdem_ArvBin(ArvBin *raiz){
    if(raiz == NULL)
        return;

    if(*raiz != NULL){
        emOrdem_ArvBin(&((*raiz)->esq));
        printf("%d, ",(*raiz)->info);
        emOrdem_ArvBin(&((*raiz)->dir));
    }
}

void posOrdem_ArvBin(ArvBin *raiz){
    if(raiz == NULL)
        return;
    if(*raiz != NULL){
        posOrdem_ArvBin(&((*raiz)->esq));
        posOrdem_ArvBin(&((*raiz)->dir));
        printf("%d, ",(*raiz)->info);
    }
}

// Travessia em Ordem não recursiva
void emOrdem_ArvBinNaoRec(ArvBin* r)
{
  struct NO *x;
	Pilha *pi = cria_Pilha();
	insere_Pilha(pi, *r);

  printf("Nos  Pilha\n");

  while (1) {
    consulta_topo_Pilha(pi, &x);
		remove_Pilha(pi);

    if (x != NULL) {
      insere_Pilha(pi, x);
      insere_Pilha(pi, x->esq);
    }
    else {
      if (Pilha_vazia(pi))
        break;

      consulta_topo_Pilha(pi, &x);
      imprime_Pilha(pi);
      remove_Pilha(pi);
      printf ("%d ", x->info);
      Lin++; //@

      insere_Pilha(pi, x->dir);
    }
  }
  libera_Pilha(pi);
}


void desenheArvore(ArvBin *raiz)
{
     char separador[10];
     separador[0] = ' ';
     separador[1] = 192;
     separador[2] = 196;
     separador[3] = 196;
     separador[4] = '\0';

     strcpy(separador, " |__");

     if(raiz == NULL)
        return;
        
     if (*raiz == NULL) {
        printf("Árvore vazia!");
        return;
     }    	
     
     printf("Arvore Binaria:\n");
     printf("%i (R)\n", (*raiz)->info);
     //desenheSubarvore(&((*raiz)->esq), 0, separador);
     //desenheSubarvore(&((*raiz)->dir), 0, separador);
     desenheSubarvore(raiz, &((*raiz)->esq), 0, separador);
     desenheSubarvore(raiz, &((*raiz)->dir), 0, separador);

}



//void desenheSubarvore(AvlNode node, String separator[]) {
//void desenheSubarvore(ArvBin *raiz, int espacos, char separator[]) 
void desenheSubarvore(ArvBin *raizAbsoluta, ArvBin *raiz, int espacos, char separator[]) 
{
     int e;
     struct NO *noPai;

     if (*raiz != NULL) {
        for (e=1; e<=espacos; e++)
            printf(" ");

        noPai = searchFather(raizAbsoluta, (*raiz)->info);
        if (noPai->esq == *raiz)
        //if (noPai->esq == *raizAbsoluta)
           printf("%s%d (E)\n", separator, (*raiz)->info);
        else
           printf("%s%d (D)\n", separator, (*raiz)->info);
        //printf("%s%d\n", separator, (*raiz)->info);
        desenheSubarvore(raizAbsoluta, &((*raiz)->esq), espacos+4, separator);
        desenheSubarvore(raizAbsoluta, &((*raiz)->dir), espacos+4, separator);
     }
}


struct NO* searchFather(ArvBin *raiz, int el) 
{
      struct NO* p = *raiz;
		struct NO* prev = NULL; 

		while (p != NULL && p->info != el) {  // acha o nó p com a chave el
			prev = p;                           
			if (p->info < el)
               p = p->dir;
			else 
               p = p->esq;
		}
		if (p != NULL && p->info == el) {
           return prev;
        }
           
		return NULL;
}

// FIM IMPLEMENTAÇÕES REF. À ÁRVORE

// IMPLEMENTAÇÕES REF À PILHA
Pilha* cria_Pilha(){
    Pilha* pi = (Pilha*) malloc(sizeof(Pilha));
    if(pi != NULL)
        *pi = NULL;
    return pi;
}

void libera_Pilha(Pilha* pi){
    if(pi != NULL){
        Elem* no;
        while((*pi) != NULL){
            no = *pi;
            *pi = (*pi)->prox;
            free(no);
        }
        free(pi);
    }
}

//int consulta_topo_Pilha(Pilha* pi, struct aluno *al){
int consulta_topo_Pilha(Pilha* pi, struct NO** dado) 
{
	struct NO* atual;
	Elem* no = *pi;

    if(pi == NULL)
        return 0;
    if((*pi) == NULL)
        return 0;
        
    *dado = (*pi)->dados;
   	return 1;
}


int insere_Pilha(Pilha* pi, struct NO *al){
    Elem* no;

    if(pi == NULL)
        return 0;
    no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL)
        return 0;
    //no->dados = al;
    no->dados = al;
    no->prox = (*pi);
    *pi = no;
    return 1;
}

int remove_Pilha(Pilha* pi){
    Elem *no = *pi;
    if(pi == NULL)
        return 0;
    if((*pi) == NULL)
        return 0;

    *pi = no->prox;
    free(no);
    return 1;
}

int tamanho_Pilha(Pilha* pi)
{
    int cont;
    Elem* no = *pi;
    if(pi == NULL)
        return 0;

    cont = 0;
    while(no != NULL){
        cont++;
        no = no->prox;
    }
    return cont;
}

int Pilha_cheia(Pilha* pi){
    return 0;
}

int Pilha_vazia(Pilha* pi){
    if(pi == NULL)
        return 1;
    if(*pi == NULL)
        return 1;
    return 0;
}

/*
void imprime_Pilha(Pilha* pi){
    if(pi == NULL)
        return;
    Elem* no = *pi;
    while(no != NULL){
        printf("Matricula: %d\n",no->dados.matricula);
        printf("Nome: %s\n",no->dados.nome);
        printf("Notas: %f %f %f\n",no->dados.n1,
                                   no->dados.n2,
                                   no->dados.n3);
        printf("-------------------------------\n");
        no = no->prox;
    }
}
*/

void imprime_Pilha(Pilha* pi)
{
    Elem* no = *pi;

    if(pi == NULL)
      return;

    if (Lin == 0)
      printf("     ");
    else
      printf("   ");
    while(no != NULL){
      //gotoxy(5, Lin);
      printf("%d ", (*(no->dados)).info);
      Lin++;
      no = no->prox;
    }
    printf("\n\b");
}
// FIM IMPLEMENTAÇÕES REF. À PILHA

int main(int argc, char* argv[])
{
    ArvBin* raiz;
    int i, info;

    //int N, dados[] = {4, 2, 6, 1, 3, 5, 10, 8};
    int N, dados[] = {5, 3, 8, 1, 4, 6, 9, 0, 2, 7};

    N = sizeof(dados)/sizeof(dados[0]);

    raiz = cria_ArvBin();

    Lin = 0; //@
    for(i=0; i < N; i++)
        insere_ArvBin(raiz, dados[i]);
        //insere_EmLargura(raiz, dados[i]);

    desenheArvore(raiz);

    printf("\n\nPercurso em pre-ordem:\n");
    preOrdem_ArvBin(raiz);
    printf("\n\nPercurso em-ordem:\n");
    emOrdem_ArvBin(raiz);
    
    printf("\n\nPercurso em-ordem (nao recursivo):\n");
    emOrdem_ArvBinNaoRec(raiz);
    printf("\n\nPercurso pos-ordem:\n");
    posOrdem_ArvBin(raiz);
    printf("\n\n");

    //printf("\n\nTotal de nos da arvore (rec): %i\n", totalNO_ArvBin(raiz));
    //printf("\n\nTotal de nos da arvore (iter): %i\n\n", totalNO_ArvBin_Iter(raiz));    
    //printf("\nAltura da arvore (rec): %i\n", altura_ArvBin(raiz));
    //printf("\nAltura da arvore (iter): %i\n\n", altura_ArvBin_Iter(raiz));
    
      
    /*
    if(remove_ArvBin(raiz, 50)) {
        printf("\n\nremovido\n");
        preOrdem_ArvBin(raiz);
    }
    else
        printf("NAO removido\n");
    */

//    printf("altura: %d\n",altura_ArvBin(raiz));
//    printf("total NOs: %d\n",totalNO_ArvBin(raiz));
//
   if (consulta_ArvBin(raiz, 20, &info))
      printf("\nResultado da consulta: %i elemento encontrado na arvore!", info);
   /* 
   if (consulta_ArvBinRec(raiz, 500, &info))
      printf("\nResultado da consulta: %i elemento encontrado na arvore!", info);
   else
      printf("\nElemento pesquisado nao encontrado na arvore!");
   */

    libera_ArvBin(raiz);
    system("pause > nul");
    return 0;
}

