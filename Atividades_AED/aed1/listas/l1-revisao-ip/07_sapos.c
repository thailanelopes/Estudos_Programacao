#include <stdio.h>

int main(){
  int i, j, cont = 1;
  int p, s;
  int posicao[100], pulo[100];
  unsigned short int teste = 0;

  scanf("%d %d", &p, &s);

  for(i = 0; i < s; i++)
    scanf("%d %d", &posicao[i], &pulo[i]);

  for(i = 0; i < p; i++) {
    teste = 0;
    for(j = 0; j < s; j++) {
      cont = 1;
      while ((posicao[j] + pulo[j] * cont) <= p) {
        if ((posicao[j] + pulo[j] * cont) == (i+1))
          teste = 1;

        cont++;
      }

      cont = 1;
      while ((posicao[j] - pulo[j] * cont) >= 1) {
        if ((posicao[j] - pulo[j] * cont) == (i+1))
          teste = 1;

        cont++;
      }

      if (posicao[j] == i+1)
        teste = 1;
    }

    printf("%d\n", teste);
  }

  return 0;
}
