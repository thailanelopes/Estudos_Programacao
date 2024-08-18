#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//#include "C:/Users/bryan/Documents/ufg/si/remoto/2020-2/aed1/lib/utilslib.h"

int main() {
  char *c, *s;
  int x, y, num;
  int resto[100];

  for (x = 0; num > 0; x++) {
    resto[x] = num % 4;
    num = num / 4;
  }

  c = (char *) malloc(1 * sizeof(char));
  s = (char *) malloc(1 * sizeof(char));

  if (!c || !s) {
    printf("ERRO: Memoria insuficiente!");
    exit(1);
  }

  strcpy(s, "");

  for (y = x-1; y >= 0; y--) {
    switch (resto[y]) {
      case 0:
        strcpy(c, "A");
      //c = "A";
        break;
      case 1:
        strcpy(c, "C");
      //c = "C";
        break;
      case 2:
        strcpy(c, "G");
      //c = "G";
        break;
      case 3:
        strcpy(c, "T");
      //c = "T";
        break;
      default:
        strcpy(c, " ");
      //c = " ";
    }

    if (y != x-1) { // primeiro indice
      s = (char *) realloc(s, 1 * sizeof(char));
      if (!s) {
        printf("ERRO: Memoria insuficiente!");
        exit(1);
      }
    }

    strcat(s, c);
  }

  printf("\n%s", s);

  free(c);
  free(s);

  return 0;
}
