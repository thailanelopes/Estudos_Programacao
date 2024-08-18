#include <stdio.h>
#include <stdlib.h>

#define SUCESSO 1
#define FALHA -1

typedef struct Dados dado;

struct Dados{
	unsigned int cor_touca;
	dado *prox;
	dado *ant;
};

typedef struct Descricao Descritor;

struct Descricao{
	unsigned int tam;
	dado *inicio;
	dado *fim;
};

dado *Cabeca;
Descritor *descritor;

int insere(dado *fila){
	dado *aux;
	aux=(dado*)malloc(sizeof(dado));
	if(aux==NULL)return FALHA;
	else{
		if(descritor->tam==0){
			aux->cor_touca=fila->cor_touca;
			descritor->inicio=aux;
			descritor->fim=aux;
			aux->ant=descritor->fim;
			aux->prox=descritor->inicio;
		  	descritor->tam++;
		  	Cabeca=descritor->inicio;
			return SUCESSO;
		}
		aux->cor_touca=fila->cor_touca;
		(descritor->fim)->prox=aux;
		aux->ant=descritor->fim;
		aux->prox=descritor->inicio;
		descritor->fim=aux;
	  	descritor->tam++;
	}
	Cabeca=descritor->inicio;
	return SUCESSO;
}

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

void libera(){
	dado *aux;
	dado *aux2;
	unsigned int i;
	aux=Cabeca;
		for(i=0;i<descritor->tam;i++){
			aux2=aux->prox;
			free(aux);
			aux=aux2;
		}
		descritor->tam=0;
}

int verifica(unsigned int a, unsigned int b, unsigned int *x){
	unsigned int i, cor=0, cores=0, elementos=0;
	int *maior;
	int *vcor;
	cores=(*x);
	vcor=(int*)calloc(sizeof(int), cores);
	maior=(int*)calloc(sizeof(int), 2);
	dado *aux;
	dado *aux2;
	if(a==1){
		aux=Cabeca;
		aux2=aux;
	}
		else{
			for(i=0, aux=Cabeca; i<descritor->tam; i++){
				if(i+1==a)break;
				aux=aux->prox;
			}
		}
			aux2=aux;
			for(cor=0; cor<cores; cor++){
				for(aux=aux2, elementos=0, i=a; i<=b; i++){
					elementos+=1;
					if(aux->cor_touca==cor+1){
						vcor[cor]+=1;
					}
					aux=aux->prox;
				}
			}
				for(i=0; i<cores; i++){
					if(vcor[i]>maior[0]){
						maior[0]=vcor[i];
						maior[1]=i;
					}
				}
				if(maior[0] > elementos/2){
					return maior[1]+1;
				}
					else{return FALHA;}

}
void mostra(dado **p){
	dado *aux;
	int i;
	aux=(*p);
		for(i=0;i<descritor->tam;i++){
			printf("%d ", aux->cor_touca);
			aux=aux->prox;
		}
}

int main(){
	unsigned int caso_teste;
	unsigned int anoes, cores, fotos, i, j, a, b, status=0;
	dado fila;
	if(crialista(&Cabeca, &descritor)==FALHA)puts("Falha");
	scanf("%d", &caso_teste);
		for(i=0; i<caso_teste; i++){
			scanf("%d %d", &anoes, &cores);
				for(j=0; j<anoes; j++){
					scanf("%d", &fila.cor_touca);
						insere(&fila);
				}
					scanf("%d", &fotos);
						for(j=0; j<fotos; j++){
							scanf("%d %d", &a, &b);
							status=verifica(a, b, &cores);
							if(status==FALHA)puts("Nao");
								else{
									printf("Sim %d\n", status);
								}
						}
				libera();
		}
return 0;
}