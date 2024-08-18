#include <stdio.h>

int main() {
  int vrNotas[] = {2, 5, 10, 20, 50, 100};
  int qtdElem = 6, qtdNotasATM[qtdElem], qtdNotasSaque[qtdElem];
  int vrSaque, i;

  scanf("%d", &vrSaque);
  for (i = 0; i < qtdElem; i++)
    scanf("%d", &qtdNotas[i]);

  if (vrSaque >= 0  && vrSaque <= 5000) {
    for (i = 0; i < qtdElem; i++) {
      qtdNotas[i] = vrSaque / vrNotas[i];
      vrSaque = vrSaque % vrNotas[i];
    }
    
    printf("\n");
    for (i = 0; i < qtdElem; i++)
      printf("NOTAS DE %d = %d\n", vrNotas[i], qtdNotas[i]);
  }

  return 0;
}
