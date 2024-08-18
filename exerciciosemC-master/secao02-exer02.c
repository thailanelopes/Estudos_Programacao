#include <stdio.h>
// std = Standard(padrão)
// io = output (Entrada/Saída)


int main(){
	//DECLARANDO VARIÁVEIS.
	int num1, num2, soma, multiplicacao;


	//ENTRADAS
	printf("Informe o primeiro número: ");
	scanf("%d", &num1);

	printf("Informe o segundo número: ");
		scanf("%d", &num2);

	//PROCESSAMENTO
	soma  = num1 + num2;
	multiplicacao = soma + num1;

    //SAÍDA
	printf("O resultado da multiplicação é %d", multiplicacao);


}
