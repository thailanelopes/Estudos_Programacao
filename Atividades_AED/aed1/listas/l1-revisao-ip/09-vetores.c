#include <stdio.h>

int main() {
  unsigned int qtd, i;

  scanf("%u", &qtd);

  if (qtd > 0 && qtd <= 50) {
    double m, n, vet[qtd];

    for (i = 0; i < qtd; i++) {
      scanf("%lf %lf", &m, &n);
      vet[i] = (m * n);
    }

    printf("\n");
    for (i = 0; i < qtd; i++)
      printf("%lf\n", vet[i]);
  }

  return 0;
}
