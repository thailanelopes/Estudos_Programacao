#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Caixa{
	char nome[20];
	struct Caixa *prox;
	struct Caixa *ant;
}Caixa;

typedef struct Lista{
	int tam;
	Caixa *inicio;
	Caixa *fim;
}Lista;

void criaLista(Lista *lista){
	lista->tam = 0;
	lista->inicio = NULL;
	lista->fim = NULL;
}

void adicionaLista(Lista *lista, char nome[]){

	Caixa* c = (Caixa*) malloc(sizeof(Caixa));
    strcpy(c->nome, nome);
    c->ant = NULL;
    c->prox = NULL;

    if(lista->inicio == NULL){
        lista->inicio = c;
        lista->fim = c;
    }else{
        lista->fim->prox = c;
        c->ant = lista->fim;
        lista->fim = c;
    }

    lista->tam++;
}

void mostraLista(Lista lista){
	
    if(lista.tam == 0){
        printf(" --- LISTA VAZIA ---");
        return;
    }

    Caixa* c = lista.inicio;

    while(c != NULL){
        printf("%s ", c->nome);
        c = c->prox;
    }
}

int procuraFim(Lista *lista, char n[]){

    if(lista->tam == 0){
        printf(" --- LISTA VAZIA ---");
        return 0;
    }

    Caixa* c = lista->fim;

	int i = 0; int cont = 0;
    while(c->ant != NULL && i < 2){
       
			if(strcmp(n, c->nome) == 0){
				cont++;
				
				if(c->ant == NULL){
					c = c->prox;
					c->ant = NULL;
					lista->inicio = c;
				} else if(c->prox == NULL){
					c->ant->prox=NULL;
					lista->fim = c;
				} else{
					c->prox->ant = c->ant;
					c->ant->prox = c->prox;
				}
				
			}
		c = c->ant;
        i++;
    }
    return cont;
}

int procuraInicio(Lista *lista, char n[]){

    if(lista->tam == 0){
        printf(" --- LISTA VAZIA --- ");
        return 0;
    }

    Caixa* c = lista->inicio;

	int i = 0; int cont = 0;
    while(c->prox != NULL && i < 2){
       
       		if(strcmp(n, c->nome) == 0){
				cont++;
				
				if(c->ant == NULL){
					c = c->prox;
					c->ant = NULL;
					lista->inicio = c;
				} else if(c->prox == NULL){
					c->ant->prox=NULL;
					lista->fim = c;
				} else{
					c->prox->ant = c->ant;
					c->ant->prox = c->prox;
				}
				
			}
		c = c->prox;
        i++;
	}
	return cont;
}
   
int main(){
	
	Lista lista;
	criaLista(&lista);
	
	char nome[20];
	
	while(1){
		scanf("%s", nome);
		
		if(strcmp(nome, "FIM") == 0){
			break;
		}
		
		adicionaLista(&lista, nome);
	}
		
	int i = 0;
	int cont = 0;
	
	while(i < lista.tam){
		
		char n[20], s[20];
		
		scanf("%s", n);
		scanf("%s", s);

		if(strcmp(s, "horario") == 0){
			cont = cont + procuraInicio(&lista, n);
		}else if (strcmp(s, "anti-horario") == 0){
			cont = cont + procuraFim(&lista, n);
		}
		i++;
	}
		
		printf("%d\n", cont);

return 0;
}