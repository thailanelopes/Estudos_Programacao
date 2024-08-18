#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct crianca{
    char nome[30];
    int valor;
    struct crianca *ant,*prox;
}crianca;

typedef struct descritor{
    crianca *inicio, *fim;
    int tamanhoLista;
}descritor;

descritor *lista;

void inicia();
void exclui(int n);
void insere();
void horario(int n);
void anti(int n);
void exibe();

void inicia(){
    lista = (descritor*) malloc(sizeof(descritor));
    lista->fim = NULL;
    lista->inicio = NULL;
    lista->tamanhoLista = 0;
}

void insere(){
    crianca *aux;
    aux = (crianca*) malloc(sizeof(crianca));

    scanf( "%s", aux->nome);
    scanf("%d", &aux->valor);

    if(lista->inicio == NULL){
        aux->prox = aux;
        aux->ant = aux;
        lista->inicio = aux;
        lista->fim = aux;
        lista->tamanhoLista++;
    }
    else {
        aux->prox = lista->inicio;
        lista->inicio = aux;
        aux->ant = lista->fim;
        (aux->prox)->ant = aux;
        (lista->fim)->prox = aux;
        lista->tamanhoLista++;
    }
}

void exclui(int n){
    crianca *aux;
    aux = lista->inicio;

    while(aux->valor != n){
        aux = aux->prox;
    }

    if(aux==lista->inicio){
        lista->inicio = aux->prox;
        (lista->inicio)->ant = lista->fim;
        (aux->prox)->ant = lista->inicio;
        lista->tamanhoLista--;
        free(aux);
    }
    else if(aux==lista->fim){

        lista->fim = aux->ant;
        (aux->ant)->prox = lista->inicio;
        lista->tamanhoLista--;
        free(aux);
    }
    else {
        (aux->ant)->prox = aux->prox;
        (aux->prox)->ant = aux->ant;
        lista->tamanhoLista--;
        free(aux);
    }
}

void horario(int n){

    if(lista->tamanhoLista == 1){
        return;
    }

    int i = 1, valorExcluir;
    crianca *aux;
    aux = (lista->fim)->prox;

    while(i<=n){
        aux = aux->prox;
        i++;
    }

    valorExcluir = aux->valor;
    exclui(aux->valor);

    if(valorExcluir%2 == 0){
        horario(valorExcluir);
    }
    else {
        anti(valorExcluir);
    }
}

void anti(int n){

    if(lista->tamanhoLista == 1){
        return;
    }

    int i = 1, valorExcluir;
    crianca *aux;
    aux = (lista->inicio)->ant;

    while(i<=n){
        aux = aux->ant;
        i++;
    }

    valorExcluir = aux->valor;
    exclui(aux->valor);

    if(valorExcluir%2 == 0){
        horario(valorExcluir);
    }
    else {
        anti(valorExcluir);
    }
}

void exibe(){
    crianca *aux;
    aux = lista->fim;
    int i=1;

    while(i<=lista->tamanhoLista){
        printf("%s , %d\n", aux->nome,aux->valor);
        aux = aux->ant;
        i++;
    }
}

int main(){

    inicia();

    int testes, i=0;

    scanf("%d", &testes);

    while(i<testes){
        insere();
        i++;
    }

    if((lista->inicio)->valor %2 == 0){
        horario((lista->inicio)->valor);
    }
    else {
        anti((lista->inicio)->valor);
    }

    printf("Vencedor(a) : ");
    printf("%s\n", (lista->inicio)->nome);

    return 0;
}