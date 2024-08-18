#include <stdio.h>
#include <stdlib.h>
#define MAX 50

typedef struct Paciente {
	int h;
	int m;
	int c;
} Paciente;

typedef struct Lista{
	Paciente paciente[MAX];
	int prim;
	int ult;
	int tam;
} Lista;

void CriaListaVazia(Lista *lista) {
	lista->prim = 0;
	lista->ult = 0;
	lista->tam = 0;
}

int VerificaListaVazia(Lista lista){
	return(lista.prim == lista.ult);
}

int VerificaListaCheia(Lista lista){
	return(lista.ult == MAX);
}

void LerPaciente(Paciente *paciente){
	printf("LEITURA DO PACIENTE\n");
	printf("\nEntre com a hora de chegada: ");
	scanf("%d", &paciente->h);
	printf("\nEntre com os minutos da chegada: ");
	scanf("%d", &paciente->m);
	printf("\nEntre a quantidade de minutos até atingir a condição crítica: ");
	scanf("%d", &paciente->c);
}

void InsereElementoLista(Lista *lista, Paciente paciente){ 
	int i,j;
	if(VerificaListaCheia(*lista)){
	   printf("NAO FOI POSSIVEL INSERIR - A LISTA ESTA CHEIA\n");
	 }else { 
		 i = lista->prim;
		 while(i < lista->ult)
		     i++;
		    if(i == lista->ult){
				  lista->paciente[i] = paciente;
		      }else { 
				  for(j = lista->ult; j > i; j--)
				        lista->paciente[j]= lista->paciente[j-1];
				       lista->paciente[i] = paciente;
				       
			          }
		 lista->ult++;
		 lista->tam++;
		 printf("INSERCAO REALIZADA COM SUCESSO\n"); 
	 }
  }
   
void ExibirPaciente(Paciente paciente){
	printf("%d ", paciente.h);
	printf("%d ", paciente.m);  
	printf("%d\n", paciente.c);   
}

int atendimento(Lista lista){
	int i = 0;
	
	int horaAtual = 7;
	int minAtual = 0;
	int criticos = 0;

	while(i < lista.tam){
		if(horaAtual == lista.paciente[i].h){
			if(minAtual >= lista.paciente[i].m){
				int difHoras = horaAtual - lista.paciente[i].h;
				int difMin = minAtual - lista.paciente[i].m;
				while(difHoras > 0){
						difMin = difMin + 60;
						difHoras--;
				}
				if(difMin > lista.paciente[i].c){
						criticos++;
				}
				i++;
			}			
		}
		if(horaAtual > lista.paciente[i].h){
				int difHoras = horaAtual - lista.paciente[i].h;
				int difMin = minAtual - lista.paciente[i].m;
				
				while(difHoras > 0){
						difMin = difMin + 60;
						difHoras--;
				}
				if(difMin > lista.paciente[i].c){
						criticos++;
				}
				i++;			
		}
		if(minAtual == 0){
				minAtual = 30;
		}else{
				horaAtual++;
				minAtual = 0;
		}
	}		
	return (criticos);
}
     
int main(){
int i;

Lista lista;
CriaListaVazia(&lista);

Paciente paciente;

int n; scanf("%d", &n);

for(i=0; i<n; i++){
	LerPaciente(&paciente);
	InsereElementoLista(&lista,paciente);
}
printf("%d\n", atendimento(lista));

return 0;
}