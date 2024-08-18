#include <stdio.h>
#include <string.h>

int main(){

	//variáveis
	char nome[100], senha[100];  //strings na linguagem C são representadas por vetores de caractéres.

	//Entradas
	printf("Informe o nome: ");
	gets(nome); //para receber representações de am string aqui, utilizamos o gets().
	printf("Informe a senha: ");
	gets(senha);


	//Processamento
	while(!strcmp(nome, senha)){  //se o nome e senha não forem diferentes, o programa continuará pedindo uma senha. str(menção a string), cmp(compara as strings)
		printf("Nome de usuário e senha devem ser diferentes.\n");
		printf("Informe o nome: ");
		gets(nome);
		printf("Informe a senha: ");
		gets(senha);
	}
}
