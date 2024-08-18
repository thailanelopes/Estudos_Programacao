#include <stdio.h>

int main(){

    int qntd_pessoas, escola, etnia;
    float renda_bruta;

    scanf("%f %d %d %d", &renda_bruta, &qntd_pessoas, &escola, &etnia);

    if(escola == 2){
        if((renda_bruta / qntd_pessoas) <= (937 * 1.5)){
            if(etnia != 4){
                printf("ALUNO COTISTA (L2)\n");
            }
            else{
                printf("ALUNO COTISTA (L1)\n");
            }
        }
        else if(etnia != 4){
            printf("ALUNO COTISTA (L4)\n");
        }
        else{
            printf("ALUNO COTISTA (L3)\n");
        }
    }
    else{
        printf("ALUNO NAO COTISTA\n");
    }

    return 0;
}
