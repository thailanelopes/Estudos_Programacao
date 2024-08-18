#include <stdio.h>

void torre(int nDiscos, char dePino, char paraPino, char auxPino) {

	if(nDiscos == 1) {
		printf("(%c,%c)\n", dePino, paraPino);
		return;
	}

	torre(nDiscos-1, dePino, auxPino, paraPino);

	printf("(%c,%c)\n", dePino, paraPino);

	torre(nDiscos-1, auxPino, paraPino, dePino);
}

main() {

	int n; scanf("%d",&n);
	
	torre(n, 'O', 'D', 'A');
	printf("\n");
 }