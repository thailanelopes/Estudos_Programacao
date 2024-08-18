#include <stdio.h>

int main(){

	int n1, n2;
	int a, b, c;

	//printf("Digite dois números de três digitos\n");
	scanf("%d %d", &n1, &n2);

	if(n1 == n2){
		printf("Os números são iguais");
	}
	
	a = n1/100;
	b = n1/10%10;
	c = n1%10;

	n1 = 100*c + 10*b + a;

	a = n2/100;
	b = n2/10%10;
	c = n2%10;

	n2 = 100*c + 10*b + a;

	if(n1 > n2){
		printf("%d", n1);
	} else{
		printf("%d", n2);
	}
return (0);
}