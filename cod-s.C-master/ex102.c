#include <stdio.h>

int main() {
  int n, num, ant, comp, compmax, i;

  scanf("%d", &n);

  scanf("%d", &ant);
  comp = 1;
  compmax = 1;

    for (i = 1; i < n; i++){
        scanf("%d", &num);
        if (num > ant){
            comp = comp + 1;
            if (compmax < comp){
                compmax = comp;
            }
        }
        else{
            comp = 1;
        }
        ant = num;
    }
  printf("O comprimento do segmento crescente maximo e: %d\n", compmax);

  return 0;
}
