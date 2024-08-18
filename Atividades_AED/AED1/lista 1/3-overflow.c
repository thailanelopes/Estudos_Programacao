#include <stdio.h>

int main(){

	int n, conta;
	scanf("%d", &n);

	int x, y; char c;
	scanf("%d %c %d", &x, &c, &y);

	if(c == '+'){
		conta = x + y;
	} else
	if(c == 'x' || c == 'X'){
		conta = x * y;
	}else{
		printf("Caractere inválido");
	}

	if(n >= conta){
		printf("no overflow");
	}else{
		printf("overflow");
	}
return (0);
}