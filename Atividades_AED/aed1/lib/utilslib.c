#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utilslib.h"


int ehAnoBissexto(int ano) {
  int logico = 0;

  if (ano > _ANOBISSEXTO) {
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

char *decimalToTetrade(int num) {
/*
0 = A
1 = C
2 = G
3 = T
*/

  char *c = "";
  int quoc = 0, resto;

  while (quoc == 0) {
    quoc  = num / _BASETETRADE;
    resto = num % _BASETETRADE;

    switch (resto) {
      case 0:
        strcat(c, "A");
        break;
      case 1:
        strcat(c, "C");
        break;
      case 2:
        strcat(c, "G");
        break;
      case 3:
        strcat(c, "T");
        break;
      default:
        strcat(c, "");
    }
  }

  return c;
}
