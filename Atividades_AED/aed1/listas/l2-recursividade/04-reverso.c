#include <stdio.h>

int reverso(int num);

int main() {
  int num;

  scanf("%d", &num);

  if (num >= 0 && num <= 1000000) // n, 1 <= n <= 10^6
    printf("%d\n", reverso(num));

  return 0;
}

int reverso(int num) {
  if (num < 10)
    return num;
  else {
    if (num % 10 != 0)
      printf("%d", num % 10);

    num = num / 10;

    return reverso(num);
  }
}
