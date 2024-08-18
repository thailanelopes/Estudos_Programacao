#include <stdio.h>
#include <stdlib.h>

int main() {
  int num1, num2;
  int a1, a2, a3;

  scanf("%d %d", &num1, &num2);

  if (num1 != num2) {
    // NUMERO 1
    a3 = num1 % 10;
    num1 = num1 / 10;

    a2 = num1 % 10;
    num1 = num1 / 10;

    a1 = num1 % 10;

    num1 = a3 * 100 + a2 * 10 + a1;


    // NUMERO 2
    a3 = num2 % 10;
    num2 = num2 / 10;

    a2 = num2 % 10;
    num2 = num2 / 10;

    a1 = num2 % 10;

    num2 = a3 * 100 + a2 * 10 + a1;

    if (num1 > num2)
      printf("%d\n", num1);
    else
      printf("%d\n", num2);
  }

  return 0;
}
