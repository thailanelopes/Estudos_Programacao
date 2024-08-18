#include <stdio.h>

int main(){

	//Variáveis
	float p, m;
	char e[8] = "excesso"; //e[8] equivale ao número de letras da string, lenbrando que toda string finaliza com '\0'(é colocado altomaticamente na linguagem C), que também é contada.


	//Entradas
	printf("Informe o peso dos peixes: ");
	scanf("%f", &p);

	//Processamento
	if(p > 50){
		m = (p - 50) * 4.00;
		//Saída
		printf("Você deverá pagar R$ %.2f em multas.", m);

	}else{
		//Processamento
		m = 0;
		e[0] = 0;
		//Saída
		printf("Multas: %.2f\n", m);
		printf("Excesso: %d", e[0]);

	}

}
