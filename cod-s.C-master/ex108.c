#include <stdio.h>

int main(){

    int n;
    scanf("%d", &n);

    int i, j, qntd = 0;

    for(i = 0; i < 8; i++){
        for(j = 0; j < 8; j++){
            if(i == 0 && j == 0){
                qntd += n;
            }
            else if(i % 2 == 0){
                if(j % 2 == 0){
                    qntd += n*2;
                }
                else{
                    qntd += n;
                }
            }
            else{
                if(j % 2 == 0){
                    qntd += n;
                }
                else{
                    qntd += n*2;
                }
            }
        }
    }

    printf("%d\n", qntd);
    return 0;
}
