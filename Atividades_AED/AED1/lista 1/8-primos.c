#include<stdio.h>

int main(){
int i, j;

int n;
scanf("%d", &n);

int v[n];
for(i = 0; i < n; i++){
    scanf("%d", &v[i]);
}

int flag;
for(i = 0; i < n; i++){
    flag = 0;

    for(j = 1; j <= v[i]/2; j++){
        if(v[i]%j == 0){
            flag++;
            if(flag >= 2) break; //
        }
    }
    if(flag > 1){
        printf("composto\n");
    }else{
        printf("primo\n");
    }
}
return 0;
}