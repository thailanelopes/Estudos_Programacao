#include <stdio.h>

int main(){
	//DECLARANDO VARIÁVEIS.
	int quantidade_minima, quantidade_maxima;
	float estoque_medio;

	//ENTRADAS
	printf("Informe a quantidade mínima: ");
	scanf("%d", &quantidade_minima);

	printf("Informe a quantidade máxima: ");
	scanf("%d", &quantidade_maxima);

	//PROCESSAMENTO
	estoque_medio = (quantidade_minima + quantidade_maxima) / 2;

   //SAÍDA
	printf("O estoque médio é %.2f", estoque_medio);


}
