#include <stdio.h>

int fAck(int m, int n);

int main() {
  int m, n;

  scanf("%d %d", &m, &n);

  printf("\n%d", fAck(m, n));

  return 0;
}

int fAck(int m, int n) {
  if (m == 0)
    return (n + 1);
  else {
    if (n > 0)
      fAck(m-1, fAck(m, n-1));
    else
      fAck(m-1, 1);
  }
}
