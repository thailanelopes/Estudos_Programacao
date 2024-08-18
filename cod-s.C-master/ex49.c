#include <stdio.h>

int main() {
    int num, bin, aux, dig, pot;

    while(scanf("%d", &num) != EOF){
      aux = num;
      bin = 0;
      pot = 1;
      while(aux > 0){
        dig = aux % 2;
        aux = aux / 2;
        bin = bin + dig * pot;
        pot = pot * 10;
      }
      printf("%d\n", bin);
    }
    return 0;
}
