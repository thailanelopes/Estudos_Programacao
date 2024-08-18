#include<stdio.h>

int numerosNaturais(int n, int i){
	if(i == n){
		return n;
	}else{
		//if(i == 0){
		//	printf("%d ", i);
		//}
		printf("%d ", i);
		return numerosNaturais(n, i+1);
	}
}

int main(){

//printf("Digite um número");
int n; scanf("%d", &n);

//printf("Estes são os número naturais até %d:\n", n);

printf("%d\n",numerosNaturais(n, 1));

return 0;
}