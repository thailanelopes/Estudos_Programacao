#include <stdio.h>
#include <stdlib.h>

typedef char Char;

typedef struct Cx{
	Char c;
	struct Cx *prox;
}Caixa;
                 
typedef Caixa *Ponteiro;

typedef struct {
	Ponteiro topo;
	int tam;
}Pilha;    
             
void criarPilha(Pilha *pilha){ 
	pilha->topo= NULL;
	pilha->tam = 0;
 }

int verificaPilhaVazia(Pilha pilha){ 
	return(pilha.topo == NULL);
}
 
void empilhar(Pilha *P, Char X){
	Ponteiro A;
	A = (Ponteiro) malloc(sizeof (Caixa));
	A->c = X;
	A->prox = P->topo;
	P->topo = A;
	P->tam++;
}
 
Char desempilhar(Pilha *P){
	Ponteiro A;
	if(verificaPilhaVazia(*P)){
		printf("A Pilha esta vazia - Desempilhar\n");
	} else {
		A = P->topo;
		P->topo = A->prox;
		P->tam--;
	}	
	return(A->c);
		free(A);
}

int calcula(Pilha *pilha, int abri){
	if (pilha->topo->c == '('){
		abri++;
	}else if (pilha->topo->c == ')'){
		abri--;
	}
	desempilhar(pilha);
	return abri;
}
       
  int main(){

	Pilha pilha;
	Pilha pilha2;
	Char c;
	
	criarPilha(&pilha);
	criarPilha(&pilha2);
	
	int i;
	
	
	char string[100];
	scanf("%s", string);
	
	
	for (i = 0; string[i] != '\0'; i++){
		empilhar(&pilha, string[i]);
	}
	
	
	while (pilha.topo != NULL){
		c = desempilhar(&pilha);
		empilhar(&pilha2, c);
	}
	
	int abri = 0;
	while(pilha2.topo != NULL){
		abri = calcula(&pilha2, abri);
		if(abri < 0){ 
			break;
		}
	}
	
	
	if(abri < 0){
		printf("incorreta");
	}else{
		printf("correta");
	}
		
	 return 0;	
 }