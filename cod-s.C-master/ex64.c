#include <stdio.h>
#include <string.h>
#include <math.h>

int main(){

    char texto[2001];

    fgets(texto, 2000, stdin);
    setbuf(stdin, NULL);

    int verificador, i;

    // verifica se existe o caractere ; no texto;
    verificador = 0;
    for(i = 0; texto[i] != '\0'; i++){
        if(texto[i] == ';'){
            verificador = 1;
            break;
        }
    }
    // Se não existir o caractere ';' no texto, então imprime FORMATO INVALIDO.
    if(verificador == 0){
        printf("FORMATO INVALIDO!\n");
    }
    else{
        int j;
        char A[1000];
        char B[1000];
        char vogais[] = "aeiouAEIOU";
        int vogaisA[5] = {0, 0, 0, 0, 0}, vogaisB[5] = {0, 0, 0, 0, 0};
        int a, e, I, o, u;
        float distancia;

        // Separa a primeira string -> A[].
        for(i = 0; texto[i] != ';'; i++){
            A[i] = texto[i];
        }
        // Separa a primeira string -> B[].
        j = 0;
        for(i = strlen(A) + 1; texto[i] != '\0'; i++){
            B[j] = texto[i];
            j++;
        }
        // Conta vogais da string A[] e coloca no vetor vogaisA[0..n].
        a = e = I = o = u = 0;
        for (i = 0; A[i] != '\0'; i++) {
            for (j = 0; vogais[j] != '\0'; j++) {
                if(vogais[j] == A[i] && (vogais[j] == 'a' || vogais[j] == 'A')){
                    a++;
                    vogaisA[0] = a;
                    break;
                }
                else if(vogais[j] == A[i] && (vogais[j] == 'e' || vogais[j] == 'E')){
                    e++;
                    vogaisA[1] = e;
                    break;
                }
                else if(vogais[j] == A[i] && (vogais[j] == 'i' || vogais[j] == 'I')){
                    I++;
                    vogaisA[2] = I;
                    break;
                }
                else if(vogais[j] == A[i] && (vogais[j] == 'o' || vogais[j] == 'O')){
                    o++;
                    vogaisA[3] = o;
                    break;
                }
                else if(vogais[j] == A[i] && (vogais[j] == 'u' || vogais[j] == 'U')){
                    u++;
                    vogaisA[4] = u;
                    break;
                }
            }
        }
        // Conta vogais da string B[] e coloca no vetor vogaisB[0..n].
        a = e = I = o = u = 0;
        for (i = 0; B[i] != '\0'; i++) {
            for (j = 0; vogais[j] != '\0'; j++) {
                if(vogais[j] == B[i] && (vogais[j] == 'a' || vogais[j] == 'A')){
                    a++;
                    vogaisB[0] = a;
                    break;
                }
                else if(vogais[j] == B[i] && (vogais[j] == 'e' || vogais[j] == 'E')){
                    e++;
                    vogaisB[1] = e;
                    break;
                }
                else if(vogais[j] == B[i] && (vogais[j] == 'i' || vogais[j] == 'I')){
                    I++;
                    vogaisB[2] = I;
                    break;
                }
                else if(vogais[j] == B[i] && (vogais[j] == 'o' || vogais[j] == 'O')){
                    o++;
                    vogaisB[3] = o;
                    break;
                }
                else if(vogais[j] == B[i] && (vogais[j] == 'u' || vogais[j] == 'U')){
                    u++;
                    vogaisB[4] = u;
                    break;
                }
            }
        }
        // Calcula distancia.
        distancia = 0;
        for(i = 0; i < 5; i++){
            distancia += pow((vogaisA[i]-vogaisB[i]), 2);
        }
        distancia = sqrt(distancia);
        // Imprime na tela o vetor vogaisA[0..n].
        for(i = 0; i < 5; i++){
            if(i == 0){
                printf("(%d", vogaisA[i]);
            }
            else if(i < 4){
                printf(",%d", vogaisA[i]);
            }
            else{
                printf(",%d)\n", vogaisA[i]);
            }
        }
         // Imprime na tela o vetor vogaisB[0..n].
        for(i = 0; i < 5; i++){
            if(i == 0){
                printf("(%d", vogaisB[i]);
            }
            else if(i < 4){
                printf(",%d", vogaisB[i]);
            }
            else{
                printf(",%d)\n", vogaisB[i]);
            }
        }
        // Imprime distancia.
        printf("%.2f\n", distancia);
    }

    return 0;
}
