#include <stdio.h>
#include <stdbool.h>

int main() {
  unsigned short int qtd, i, j;
  bool ehPrimo;

  scanf("%d", &qtd);

  if (qtd > 0 && qtd <= 100) {
    int vet[qtd];

    for (i = 0; i < qtd; i++)
      scanf("%d", &vet[i]);

    for (i = 0; i < qtd; i++) {
      ehPrimo = vet[i] > 1;

      for (j = 2; j <= (vet[i]-1); j++) {
        if (vet[i] % j == 0) {
          ehPrimo = false;
          break;
        }
      }

      printf("%s\n", ehPrimo ? "primo" : "composto");
    }
  }


  return 0;
}
