#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  int i = 0, qtd = 0, a1, a2, a3, a4;

  scanf("%d", &qtd);

  if (qtd > 0) {
    int nums[qtd], tmp = 0;
    char *str[qtd];

  //char *str;
  //str = "";

    for (i = 0; i < qtd; i++) {
      scanf("%d", &nums[i]);

      tmp = nums[i];

      a4  = tmp % 10;
      tmp = tmp / 10;

      a3  = tmp % 10;
      tmp = tmp / 10;

      a2  = tmp % 10;
      tmp = tmp / 10;

      a1  = tmp % 10;

      tmp = a4 * 1000 + a3 * 100 + a2 * 10 + a1;

      str[i] = tmp == nums[i] ? "yes" : "no";

    //strcat(str, (tmp == nums[i]) ? "yes " : "no ");
    }

    printf("\n");
    for (i = 0; i < qtd; i++)
      printf("%s ", str[i]);
  }

  return 0;
}
