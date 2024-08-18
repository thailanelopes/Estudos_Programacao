#include <stdio.h>
#include <stdlib.h>

#include "LLSE.h"


int main() {
	int n, i;
	int h, m, c;
	int tempoAtendimento, tempoChegada, difTempo;
	int pacientesCritico = 0;
	int qtdElem = 0;

	Celula celula;
	ApontadorCelula prim, aux;

	criaListaVazia(&prim);

	scanf("%d", &n);

	for(i = 0; i < n; i++) {
    celula.chave = i+1;
		scanf("%d %d %d", &celula.horasChegada, &celula.minutosChegada, &celula.minutosCritico);
		if (insFinal(&prim, celula) == SUCESSO)
		  qtdElem++;
	}

	tempoAtendimento = 7 * 60;

	while(qtdElem != 0) {
    aux = prim;

    tempoChegada = aux->horasChegada * 60 + aux->minutosChegada;
    difTempo = tempoAtendimento - tempoChegada;

		if (difTempo >= 0) {
		  if (difTempo > aux->minutosCritico)
		    pacientesCritico++;

      if (remInicio(&prim) == SUCESSO)
        qtdElem--;
		}

		tempoAtendimento = tempoAtendimento + 30;
	}

	printf("%d\n", pacientesCritico);

	return 0;
}
