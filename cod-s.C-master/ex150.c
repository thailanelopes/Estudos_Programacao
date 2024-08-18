#include <stdio.h>
#include <string.h>

int main(){

    int n;
    scanf("%d",&n);
    setbuf(stdin, NULL);

    int x, tamanho;
    char letras[6];

    while(n--){
        scanf("%s", letras);

        tamanho = strlen(letras);

        if(tamanho == 5){
            printf("3\n");
        }
        else{
            x = 0;
            if(letras[0] == 'o'){
                x++;
            }
            if(letras[1] == 'n'){
                x++;
            }
            if(letras[2] == 'e'){
                x++;
            }
            if(x >= 2){
                printf("1\n");
            }
            else{
                printf("2\n");
            }
        }

    }

    return 0;
}
