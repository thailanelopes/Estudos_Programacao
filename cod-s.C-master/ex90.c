#include <stdio.h>

int main(){
    int casos, n_pessoas, i;
    float popular, geral, arquibancada, cadeiras, renda;

    scanf("%d", &casos);

    for(i = 1; i <= casos; i++){
        scanf("%d %f %f %f %f", &n_pessoas, &popular, &geral, &arquibancada, &cadeiras);

        popular = popular/100 * n_pessoas * 1;
        geral = geral/100 * n_pessoas * 5;
        arquibancada = arquibancada/100 * n_pessoas * 10;
        cadeiras = cadeiras/100 * n_pessoas * 20;
        renda = popular + geral + arquibancada + cadeiras;

        printf("A RENDA DO JOGO N. %d E = %.2f\n", i, renda);
    }
}
