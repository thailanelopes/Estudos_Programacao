#include <stdio.h>
#include <stdlib.h>

int anoBissexto(int ano) {
  int logico = 0;
  int baseAnoBissexto = 1582; // A PARTIR DESTE ANO PODE SER BISSEXTO

  if (ano > baseAnoBissexto) {
    if (ano % 100 > 0) {
      if (ano % 4 == 0)
        logico = 1;
    } else {
      if (ano % 400 == 0)
        logico = 1;
    }
  }

  return logico;
}

int main() {
  int baseAnoBissexto  = 1582;
  int SINCR            = 1986;
  int INTERV           = 76;

  int i, anoAtual = 0, anoProxPass = SINCR, qtdDias = 0;
  printf("Informe o ano atual: ");
  scanf("%d", &anoAtual);

  int found = 0;
  int nI = anoAtual < SINCR ? anoAtual : SINCR;
  int nF = anoAtual > SINCR ? anoAtual : SINCR;
  while (found < 1) {
    for (i = nI; i < nF; i++) {
      if (anoBissexto(i) == 1)
        qtdDias++;
    }

    if (anoAtual < SINCR) {
      anoProxPass = anoProxPass - INTERV;
      if (anoProxPass <= anoAtual) {
        anoProxPass = anoProxPass + INTERV;
      //if (anoProxPass < baseAnoBissexto)
        //anoProxPass--;
        found = 1;
        break;
      }
    } else {
      anoProxPass = anoProxPass + INTERV;
      if (anoProxPass > anoAtual) {
        found = 1;
        break;
      }
    }
  }

  int qtdAnos = qtdDias % 365;
  if (qtdAnos > 0) {
    if (anoAtual < baseAnoBissexto)
      anoProxPass = anoProxPass + qtdAnos;

    /*
    if (anoAtual < SINCR)
      anoProxPass = anoProxPass + qtdAnos;
    else
      anoProxPass = anoProxPass - qtdAnos;
    */
  }

  printf("O cometa Halley sera visivel novamente em: %d\n", anoProxPass);
  printf("\nqtdDias = %d  |  qtdAnos = %d", qtdDias, qtdAnos);

  return 0;
}
