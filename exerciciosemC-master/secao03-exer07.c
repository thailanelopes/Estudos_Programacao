#include <stdio.h>

int main(){

	//DECLARAÇÃO DE VARIÁVEIS
	float altura, peso_ideal;




	//ENTRADAS
	printf("Qual sua altura?");
	scanf("%f", &altura);


	//PROCESSAMENTO
	peso_ideal = (72.7 * altura) - 58;


	//SAÍDA
	printf("seu peso ideal é: %.2f", peso_ideal);



}
