#include <stdio.h>
#include <stdlib.h>

int main() {
  int i, num;
  
  scanf("%d", &num);

  char respostas[] = {'V', 'F', 'V', 'V', 'F'};

  for (i = 0; i < 5; i++)
    printf("%c", respostas[i]);

  return 0;
}
