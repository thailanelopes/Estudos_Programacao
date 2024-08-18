#include<stdio.h>

void base4(int num){
	if(num == 0){
		printf("A");
	}else if(num == 1){
		printf("C");
	}else if(num == 2){
		printf("G");
	}else if(num == 3){
		printf("T");
	}else{
	
		int r = num%4;

		num = num/4;
		base4(num);
		
		if(r == 0){
			printf("A");
		}else if(r == 1){
			printf("C");
		}else if(r == 2){
			printf("G");
		}else if(r == 3){
			printf("T");
		}
	}
}

int main(){
	int i;
	int n;
	scanf("%d", &n);
	
	int num; 
	for(i = 0; i < n; i++){
		scanf("%d", &num);
		base4(num);
		printf("\n");
	}

return(0);	
}