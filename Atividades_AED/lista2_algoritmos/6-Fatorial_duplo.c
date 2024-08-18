#include <stdio.h>

int fatorialduplo(int n){
	if(n%2 == 0){
		fatorialduplo(n-1);
	}else{
		if(n >= 1)
		return(n * fatorialduplo(n-2));
	}
}

int main(){
	
	int n;
	scanf("%d", &n);
	printf("%d\n", fatorialduplo(n));

return (0);
}