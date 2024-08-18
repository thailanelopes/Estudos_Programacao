#include <stdio.h>
#include <stdlib.h>

int main() {
  int baseAnoBissexto = 1582;
  int baseAnoSincr    = 1986;
  int intervAnos      = 76;
  int anoAtual = 0, anoProxPass = baseAnoSincr;

  scanf("%d", &anoAtual);

  int found = 0;
  while (found < 1) {
    if (anoAtual < baseAnoSincr) {
      anoProxPass = anoProxPass - intervAnos;
      if (anoProxPass <= anoAtual) {
        anoProxPass = anoProxPass + intervAnos;
        if (anoProxPass < baseAnoBissexto)
          anoProxPass--;
        found = 1;
        break;
      }
    } else {
      anoProxPass = anoProxPass + intervAnos;
      if (anoProxPass > anoAtual) {
        found = 1;
        break;
      }
    }
  }

//printf("O cometa Halley sera visivel novamente em: %d\n", anoProxPass);
  printf("%d", anoProxPass);

  return 0;
}
