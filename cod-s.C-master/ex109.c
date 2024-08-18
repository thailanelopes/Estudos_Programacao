#include <stdio.h>

int main(){

    int l, c;
    scanf("%d %d", &l, &c);

    int i, j;
    for(i = 2; i <= l; i++){
        for(j = 1; j <= c; j++){
            if(i > j){
                if(i == 2 && j == 1){
                    printf("(%d,%d)", i, j);
                }
                else if(j == 1){
                    printf("(%d,%d)", i, j);
                }
                else{
                    printf("-(%d,%d)", i, j);
                }
            }
        }
        printf("\n");
    }

    return 0;
}
