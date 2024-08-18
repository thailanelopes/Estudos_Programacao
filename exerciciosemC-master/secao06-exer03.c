#include<stdio.h>

int main(){

    //VARIÁVEIS
  int numero, p = 0, i = 0;

   //ENTRADAS
  printf("Informe um número: ");
  scanf("%d", &numero);

  //PROCESSAMENTO
 if(numero % 2 == 0){
	 p = numero;

 }else{

	i = numero;

 }

  //SAÍDA
  printf("%d\n", p );
  printf("%d\n", i );

}
