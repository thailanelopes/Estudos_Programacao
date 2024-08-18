#include <stdio.h>

int main(){

    int n1, n2, n3, n4;

    scanf("%d %d %d %d", &n1, &n2, &n3, &n4);

    if((n1 > n2) && (n1 > n2) && (n1 > n4)){
        printf("%d\n", n2 + n3 + n4);
    }
    else if((n2 > n3) && (n2 > n4) && (n2 > n1)){
        printf("%d\n", n1 + n3 + n4);
    }
    else if((n3 > n1) && (n3 > n2) && (n3 > n4)){
        printf("%d\n", n2 + n1 + n4);
    }
    else{
        printf("%d\n", n2 + n3 + n1);
    }


    return 0;
}
