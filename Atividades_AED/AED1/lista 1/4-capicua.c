#include<stdio.h>

main(){

int i, n;
scanf("%d", &n);
int v[n];

for(i = 0; i < n; i++){
    scanf("%d", &v[i]);
}

int a, b, c, d, novo;
for(i = 0; i < n; i++){
    a = v[i]/1000%10;
    b = v[i]/100%10;
    c = v[i]/10%10;
    d = v[i]%10;

    novo = d*1000 + c*100 + b*10 + a;

    if(v[i] == novo){
        printf("yes ");
    }else{
        printf("no ");
    }
}

}