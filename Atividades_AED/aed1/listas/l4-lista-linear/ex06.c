#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SUCESSO 1
#define FALHA -1
#define TAM 1000

typedef struct Dados dado;

struct Dados{
	char expressao[TAM];
	dado *proximo;
	dado *ant;
};

typedef struct Descricao Descritor;

struct Descricao{
	unsigned int tam;
	dado *inicio;
	dado *fim;
};

typedef struct Comparacao Comp;

struct Comparacao{
	unsigned int parentese_a, parentese_f;
	unsigned int indice_aberto[TAM/2], indice_fechado[TAM/2];
};

dado *Cabeca;
Descritor *descritor;

int crialista(dado **Cabeca, Descritor **descritor){
	Cabeca=(dado**)malloc(sizeof(dado*));
	(*descritor)=(Descritor*)malloc(sizeof(Descritor));
	if(Cabeca!=NULL && (*descritor)!=NULL){
		Cabeca=(dado**)NULL;
		(*descritor)->inicio=(dado*)NULL;
		(*descritor)->fim=(dado*)NULL;
		(*descritor)->tam=0;
		return SUCESSO;
	}
		else{FALHA;}
}

int insere(dado *exp){
	dado *aux;
	aux=(dado*)malloc(sizeof(dado));
	if(aux==NULL)return FALHA;
	else{
		if(descritor->tam==0){
			strcpy(aux->expressao, exp->expressao);
			descritor->inicio=aux;
			descritor->fim=aux;
			aux->ant=descritor->fim;
			aux->proximo=descritor->inicio;
		    descritor->tam++;
		    Cabeca=descritor->inicio;
			return SUCESSO;
		}
		strcpy(aux->expressao, exp->expressao);
		(descritor->fim)->proximo=aux;
		aux->ant=descritor->fim;
		aux->proximo=descritor->inicio;
		(descritor->inicio)->ant=aux;
		descritor->fim=aux;
	    descritor->tam++;
	}
	Cabeca=descritor->inicio;
	return SUCESSO;
}

int verifica(dado **p){
	dado *aux;
	Comp *comp;
	unsigned int i=0, j=0, k=0, n=0, cont=0;
	comp=(Comp*)malloc(sizeof(Comp));
	if(comp==NULL){
		puts("falha\n");
	}
		else{
			comp->parentese_a=0;
			comp->parentese_f=0;
		}
	aux=(*p);
		for(i=0, j=0, k=0; i<strlen(aux->expressao); i++){
			if(aux->expressao[i]=='('){
				comp->parentese_a+=1;
				comp->indice_aberto[j]=i;
				j++;
			}
				if(aux->expressao[i]==')'){
					comp->parentese_f+=1;
					comp->indice_fechado[k]=i;
					k++;
				}
		}
		if(comp->parentese_a==comp->parentese_f){
			for(cont=0, i=0; i<j; i++){
				for(n=0; n<k; n++){
					 if(aux->expressao[comp->indice_aberto[i]]=='(' && aux->expressao[comp->indice_fechado[n]]==')'){
						if(comp->indice_aberto[i]<comp->indice_fechado[n]){
							cont+=1;
						}
					 }
				}
			}
		}
			else{return FALHA;}
		if(cont==k){
			return SUCESSO;
		}
			else{return FALHA;}
}

int main(){
	dado expressoes;
	dado *aux;
	unsigned int i;
	if(crialista(&Cabeca, &descritor)==FALHA)puts("falha");
		scanf("%[^\n]", expressoes.expressao);
		getchar();
		insere(&expressoes);
		if(verifica(&Cabeca)==SUCESSO){
			puts("Correta");
		}
			else{puts("Incorreta");}
	return 0;
}