#include<stdio.h>

int main(){

	//DECLARAÇÃO DE VARIÁVEIS
	int n;

	//ENTRADAS
	printf("informe um nùmero: ");
	scanf("%d", &n);

	//PROCESSAMENTO
	if(n > 100){
		printf("%d", n);
	}
	else{
		n = 0;
		printf("%d", n);

	}
}
