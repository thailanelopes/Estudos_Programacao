#include <stdio.h>
#include <string.h>

int main(){

    int n, i, j, numVogais, numLetras, numConsoantes;
    char frase[10000];
    char vogais[] = "aeiouAEIOU";

    scanf("%d", &n);
    getchar();
    while(n--){
        fgets(frase, sizeof(frase), stdin);

        numVogais = 0;
        for (i = 0; frase[i] != '\0'; i++){
            for (j = 0; vogais[j] != '\0'; j++){
                if (vogais[j] == frase[i]){
                    numVogais++;
                    break;
                }
            }
        }
        numLetras = 0;
        for(i = 0; frase[i] != '\0'; i++){
            if((frase[i] >= 65 && frase[i] <= 90) || (frase[i] >= 97 && frase[i] <= 122)){
                numLetras++;
            }
        }
        numConsoantes = numLetras - numVogais;

        printf("Letras = %d\n", numLetras);
        printf("Vogais = %d\n", numVogais);
        printf("Consoantes = %d\n", numConsoantes);
    }

    return 0;
}
