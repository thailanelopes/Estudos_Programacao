#include <stdio.h>
#include <ctype.h>  //possui algumas funções utilitárias, por exemplo tranformar a variável sexo em minúscula, para se caso o usuário digitar m ou F em maiúsculo seja processado da mesma forma quando digitado em minúsculo.

int main(){

	//VARIÁVEIS
	float altura, peso_ideal;
	char sexo;


	//Entradas
	printf("Informe sua altura: ");
	scanf("%f", &altura);

gets(stdin);  //corrige o bug, faz com que a segunda entrada seja "identificada".

	printf("Informe seu sexo m/f: ");
	scanf("%c", &sexo);

	//Processamento
	if(tolower(sexo) == 'm'){
		peso_ideal = (72.7 * altura) - 58;
		printf("Seu peso ideal é %.2f", peso_ideal);

	}
	if(tolower(sexo) == 'f'){
		peso_ideal = (62.1 * altura) - 44.7;
		printf("Seu peso ideal é %.2f", peso_ideal);

	}
	if(tolower(sexo) != 'm' && tolower(sexo) != 'f'){
		printf("sexo não reconhecido. \n");
	}
}
