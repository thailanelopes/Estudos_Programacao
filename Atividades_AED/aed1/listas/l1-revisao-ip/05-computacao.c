#include <stdio.h>
#include <stdlib.h>

int main() {
  int qtd, lim = 100;

  scanf("%d", &qtd);

  if (qtd > 0 && qtd <= lim) {
    int i, x, y;
    int nums[qtd], resto[lim];

    for (i = 0; i < qtd; i++)
      scanf("%d", &nums[i]);

    printf("\n");

    for (i = 0; i < qtd; i++) {
      int aux = nums[i];

      for (x = 0; aux > 0; x++) {
        resto[x] = aux % 4;
        aux = aux / 4;
      }

      for (y = x-1; y >= 0; y--) {
        switch (resto[y]) {
          case 0:
            printf("A");
            break;
          case 1:
            printf("C");
            break;
          case 2:
            printf("G");
            break;
          case 3:
            printf("T");
            break;
          default:
            printf(" ");
        }
      }

      printf("\n");
    }
  }

  return 0;
}
