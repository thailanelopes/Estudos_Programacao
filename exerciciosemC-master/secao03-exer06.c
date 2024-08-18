#include <stdio.h>

int main(){

	//DECLARAÇÃO DE VARIÁVEIS
	float valor_por_hora, salario;
	int horas_trabalhadas;

	//ENTRADAS
	printf("Qual valor você ganha por hora? ");
	scanf("%f", &valor_por_hora);

	printf("Quantas horas você trabalhou neste mês? ");
	scanf("%d", &horas_trabalhadas);

	//PROCESSAMENTO
	salario = (horas_trabalhadas * valor_por_hora);


	//SAÍDA
    printf("Neste mês você vai receber R$ %.2f", salario);

}
