#include <stdio.h>
#include <stdlib.h>

int qtdEnvelopes(int n, int k, int vet[]);

int main() {
  int i, qtd, tipos;

  scanf("%d %d", &qtd, &tipos);

  if (qtd > 0 && qtd <= 1000 && tipos > 0 && tipos <= 20) {
    int vet[qtd];

    for (i = 0; i < qtd; i++)
      scanf("%d", vet[i]);

    int qtdEnv = qtdEnvelopes(qtd, tipos, vet);
    printf("%d\n", qtdEnv);
  }

  return 0;
}

int qtdEnvelopes(int n, int k, int vet[]) {
  // é preciso enviar um envelope contendo um rótulo de cada tipo de bala que a SBC produz.

  int i, j, qtdEnv;
  int rotulos[n];

  for (j = 1; j <= k; j++) {
    for (i = 0; i < n; i++) {
      if (vet[i] == j)
        rotulos[j-1] += 1;
    }
  }

  qtdEnv = vet[0];
  for (i = 0; i < n; i++) {
    if (qtdEnv > vet[j])
      qtdEnv = vet[j];
  }

  return qtdEnv;
}
