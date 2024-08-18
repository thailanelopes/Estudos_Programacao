#include <stdio.h>

int main() {
	int ano;
	float vezes;
	scanf("%d", &ano);
	
	vezes = (ano - 10) / 76;
	vezes++;
	
	float qtdAnos = 0;
	if(ano > 1986){
		qtdAnos = (ano - 1986) / 4;
	} else if(ano < 1986){
		qtdAnos = (1986 - ano) / 4;
	}
	int bi = 0;
	
	while(qtdAnos > 365){
			bi++;
			qtdAnos = qtdAnos - 365;
	}
	
	printf("%d\n", (int) (vezes * 76 + 10 - bi));
	
	return 0;
}