#include <stdio.h>
#include <stdlib.h>

int main() {
  int lim, num1, num2, result;
  char opr;

  scanf("%d", &lim);
  scanf("%d %c %d", &num1, &opr, &num2);

  /*
  printf("num1 = %d\n", num1);
  printf("opr = %c\n", opr);
  printf("num2 = %d\n", num2);
  exit(0);
  */

  if (opr == '+') {
    result = num1 + num2;
    if (result > lim)
      printf("overflow\n");
    else
      printf("no overflow\n");
  } else if (opr == 'x') {
    result = num1 * num2;
    if (result > lim)
      printf("overflow\n");
    else
      printf("no overflow\n");
  } else
    printf("..................");

  return 0;
}
