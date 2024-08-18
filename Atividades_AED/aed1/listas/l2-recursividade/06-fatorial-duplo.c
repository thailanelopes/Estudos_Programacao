#include <stdio.h>

double fatorialDuplo(int num);

int main() {
  int num;

  scanf("%d", &num);

  if (num > 0 && num <= 100) {
    if (num % 2 == 0)
      num--;

    printf("\n%.0lf", fatorialDuplo(num));
  }

  return 0;
}

double fatorialDuplo(int num) {
  if (num == 1)
    return num;
  else
    return num * fatorialDuplo(num-2);
}
