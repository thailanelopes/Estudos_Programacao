#include <stdio.h>

int i = 1;

void imprimeNumerosNaturaisIterativo(int num);
void imprimeNumerosNaturaisRecursivo(int num);

int main() {
  int num, tipo = 1;

  scanf("%d", &num);

  if (num > 0 && num <= 5000) {
    if (tipo == 0)
      imprimeNumerosNaturaisIterativo(num);
    else
      imprimeNumerosNaturaisRecursivo(num);
  }

  return 0;
}

void imprimeNumerosNaturaisIterativo(int num) {
  for (i = 1; i <= num; i++)
    printf("%d%s", i, i < num ? " " : "");
}

void imprimeNumerosNaturaisRecursivo(int num) {
  printf("%d%s", i, i < num ? " " : "");

  i++;

  if (i > num)
    return;
  else
    imprimeNumerosNaturaisRecursivo(num);
}
