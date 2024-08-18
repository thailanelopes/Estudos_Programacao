#include <stdio.h>


int main(){

    int n, m, soma, i;
    char str[11];

    while(1){
        scanf("%d %d", &n, &m);
        setbuf(stdin, NULL);

        if(m == 0 && n == 0){
            break;
        }

        soma = m+n;

        sprintf(str, "%d", soma);

        for(i = 0;  str[i] != '\0'; i++){
            if(str[i] != '0'){
                printf("%c", str[i]);
            }
        }
        printf("\n");
    }

    return 0;
}
