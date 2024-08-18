#include <stdio.h>
#include <stdlib.h>

typedef struct Pessoa{ 
	int cod;
}Pessoa;

typedef struct Caixa{
	Pessoa pessoa;
	struct Caixa *prox;
}Caixa;
                 
typedef Caixa *Ponteiro;

typedef struct Fila{
	Ponteiro inicio;
	Ponteiro fim;
	int tam;
}Fila;

void criarFilaVazia(Fila *F){
	Ponteiro A;
	A = (Ponteiro) malloc(sizeof(Caixa)); 
	A->prox = NULL; 
	F->inicio = A; 
	F->fim = A; 
	F->tam = 0; 
 }	

int verificaFilaVazia(Fila fila){ 
	return (fila.inicio == fila.fim);
}

void enfileirar(Fila *F, Pessoa pessoa){
	Ponteiro A;
	A = (Ponteiro) malloc(sizeof (Caixa)); 
	A->pessoa = pessoa; 
	F->fim->prox = A; 
	F->fim = A; 
	F->tam++; 
}

void desenfileirar(Fila *F, Pessoa *X){
	Ponteiro A;
	if(verificaFilaVazia(*F)){
		printf("A Fila esta vazia - Desenfileirar\n");
	}else {
		A = F->inicio;  
		F->inicio = A->prox;   
		*X = F->inicio->pessoa;  
		F->tam--;      
		free(A); 
	}		
}
 
void exibirPessoa(Pessoa X){
	printf("%d ", X.cod);
}

void exibirFila(Fila *F){
	Pessoa X;
	Fila F1;
	criarFilaVazia(&F1);
	if(verificaFilaVazia(*F)){
		printf("A Fila esta vazia - Exibir Fila\n");
	}else {
		
		while(F->inicio != F->fim){
			desenfileirar(&(*F),&X);
			enfileirar(&F1,X);
			exibirPessoa(X);
		}
	
		while((F1.inicio)!= (F1.fim)){
			desenfileirar(&F1,&X);
			enfileirar(&(*F),X);
		}
	}
}

void sairDaFila(Fila *F, int ident){
	Pessoa X;
	Fila F1;
	criarFilaVazia(&F1);
	if(verificaFilaVazia(*F)){
		printf("A Fila esta vazia - Exibir Fila\n");
	}else {
		
		while(F->inicio != F->fim){
			desenfileirar(&(*F),&X);
			if(X.cod != ident){
				enfileirar(&F1,X);
			}
		}
	
		while((F1.inicio)!= (F1.fim)){
			desenfileirar(&F1,&X);
			enfileirar(&(*F),X);
		}
	}
}
       
void ler(Pessoa *pessoa){
	//printf("\nEntre com o Código: ");
	scanf("%d", &pessoa->cod);
}
   
int main(){
	int i = 0;
	Pessoa pessoa;
	Fila fila;
	criarFilaVazia(&fila);
	
	int qtdPessoasNaFila;
	//printf("\nDigite a quatidade de pessoas na fila\n");
	scanf("%d", &qtdPessoasNaFila);
	
	for(i = 0; i<qtdPessoasNaFila; i++){
		ler(&pessoa);
		enfileirar(&fila, pessoa);	
	}
		
	int qtdSairamFila;
	//printf("\nDigite a quatidade de pessoas que saíram da fila\n");
	scanf("%d",&qtdSairamFila);
	
	for(i = 0; i<qtdSairamFila; i++){
		int iden; scanf("%d", &iden);
		sairDaFila(&fila, iden);	
	}
	
	exibirFila(&fila);

	 return 0;	
    }