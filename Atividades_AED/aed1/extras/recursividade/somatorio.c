#include <stdio.h>
#include <stdlib.h>

// Somatorio dos elementos do vetor (recursivo): posicoes de 0 a (n−1)

unsigned long int somatorio (unsigned long int vetor[], unsigned int n) {
  if (n == 1) {
    return vetor[n-1];
  } else {
    return vetor[n-1] + somatorio(vetor, n-1);
  }
}

int main() {
  int vet[] = {7, 9, 4, 1};

  printf("O somatorio do vetor eh igual a: %d\n", somatorio(vet, 4));

  return 0;
}
