#include <stdio.h>

int main(){
	//Variáveis
	int numero;

	//Entradas
	printf("Informe um número: ");
	scanf("%d", &numero);

	//Processamento
	if(numero % 2 == 0){
	if(numero > 0){
		printf("O número %d é par e positivo.", numero);

	}else{
		printf("O número %d é par e negativo.", numero);
	}

	}else{
		if(numero > 0){
			printf("O número %d é ínpar e positivo.", numero);
		}else{
			printf("O número %d é ínpar e negativo.", numero);
		}
	}

}
