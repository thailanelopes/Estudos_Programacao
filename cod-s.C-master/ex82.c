#include <stdio.h>

int inverte(int n);

int main(){

    int A, B, A_invertido, B_invertido, T;

    scanf("%d", &T);

    while(T--){
        scanf("%d %d", &A, &B);
        A_invertido = inverte(A);
        B_invertido = inverte(B);

        if(A_invertido > B_invertido){
            printf("%d\n", A_invertido);
        }
        else{
            printf("%d\n", B_invertido);
        }
    }

    return 0;
}

int inverte(int n){

    int ret=0;
    int i=1;

    while(i<=n){
       ret*=10;
       ret+=(n%(i*10)-n%i)/i;
       i*=10;
    }
    return ret;
}
