#include <stdio.h>

void conversor(int n){
	if (n > 0) {
		    conversor(n/2);
            printf("%d", n%2);
        }
}

int main(){
int i;

int k;
scanf("%d", &k);

for(i = 0; i < k; i++){
	int n; scanf("%d", &n);
	conversor(n);
	printf("\n");
}

return(0);
}