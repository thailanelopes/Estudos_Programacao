#include <stdio.h>
#include <stdlib.h>

int i = 0;
int *vet;

void imprimeSeqFibIterativo(int num);
void imprimeSeqFibRecursivo(int num);

int main() {
  int num, tipo = 1; // 0 = Iterativo; 1 = Recursivo;

  scanf("%d", &num);

  if (num >= 0 && num <= 1000) {
    vet = (int *) malloc(num * sizeof(int));

    if (!vet) {
      printf("Memoria insuficiente...");
      exit(1);
    }

    vet[0] = 0;
    vet[1] = 1;

    if (tipo == 0)
      imprimeSeqFibIterativo(num);
    else
      imprimeSeqFibRecursivo(num);
  }

  return 0;
}

void imprimeSeqFibIterativo(int num) {
  for (i = 0; i <= num; i++) {
    if (i > 1)
      vet[i] = vet[i-1] + vet[i-2];

    printf("%d%s", vet[i], i < num ? " " : "");
  }
}

void imprimeSeqFibRecursivo(int num) {
  printf("%d%s", vet[i], i < num ? " " : "");

  i++;

  if (i > num)
    return;
  else {
    if (i > 1)
      vet[i] = vet[i-1] + vet[i-2];

    imprimeSeqFibRecursivo(num);
  }
}
