#include <stdio.h>

void conversaoDecimalBinario(int num);

int main() {
  int qtd, i;

  scanf("%d", &qtd);

  if (qtd > 0 && qtd <= 1000) {
    int vet[qtd];

    for (i = 0; i < qtd; i++)
      scanf("%d", &vet[i]);

    printf("\n");

    for (i = 0; i < qtd; i++) {
      conversaoDecimalBinario(vet[i]);
      printf("\n");
    }
  }

  return 0;
}

void conversaoDecimalBinario(int num) {
  int resto;

  resto = num % 2;
  num = num / 2;

  if (num > 0)
    conversaoDecimalBinario(num);

  printf("%d", resto);
}
