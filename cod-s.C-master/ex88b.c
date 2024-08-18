#include <stdio.h>
#include <string.h>

int string_cmp(const unsigned char * s1, const unsigned char * s2);
void string_swap(char * s1, char * s2);
char nome[100][32];

int main(){
    int N;
    scanf("%d\n", &N);

    int i, x, y, r;
    char nome[N][32];

    for(i = 0; i < N; i++){
        scanf("%s", nome[i]);
    }
    for(x = 0; x < N; x++){
        for(y = x+1; y < N; y++){
            r = string_cmp(nome[x], nome[y]);
            if(r > 0){
                string_swap(nome[x], nome[y]);
            }
        }
    }
    for(i = 0; i < N; i++){
        puts(nome[i]);
    }

    return 0;
}
int string_cmp(const unsigned char * s1, const unsigned char * s2){
    return strcmp(s1, s2);
}
void string_swap(char * s1, char * s2){
    char aux[32];
    strcpy(aux, s1);
    strcpy(s1, s2);
    strcpy(s2, aux);
}
