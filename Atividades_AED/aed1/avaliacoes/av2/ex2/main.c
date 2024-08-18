#include <stdio.h>
#include <stdlib.h>

#include "TAD.h"


int main() {
	int num = 0, i = 1;
	char operacao;
	int *lista;

	lista = (int *) malloc(sizeof(int));
	if (! lista)
	  return EXIT_FAILURE;

	while (num != -1) {
    scanf("%d", &num);

    if (num != -1) {
      lista = (int *) realloc(lista, (i+1) * sizeof(int));
      if (! lista)
        return EXIT_FAILURE;

      lista[i-1] = num;

      i++;
    }
  }

	scanf(" %c", &operacao);

	switch (operacao) {
	  case 'C':
	    Crescente(&lista, i);
	    MostraLista(&lista, i);
    break;

	  case 'D':
	    Decrescente(&lista, i);
	    MostraLista(&lista, i);
    break;

	  case 'M':
	    printf("%d", Maior(&lista, i));
    break;

	  case 'm':
	    printf("%d", Menor(&lista, i));
    break;

    default:
      printf("Operacao Invalida!");
	}


	return 0;
}
