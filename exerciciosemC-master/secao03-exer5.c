#include<stdio.h>

int main(){

	//DECLARAÇÃO DE VARIÁVEIS
	int metros, centimetros;


	//ENTRADAS
	printf("Informe o valor em metros: ");
	scanf("%d", &metros);


     //PROCESSAMENTO
	 centimetros = (metros * 100);

	 //SAÍDA
	 printf("%d metros em centimetros é %d", metros, centimetros);

}
