#ifndef LLSE_H_INCLUDED
#define LLSE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>


#define SUCESSO          1
#define FALHA           -1

#define CHAVE_INVALIDA   0


typedef struct Celula*  ApontadorCelula;

typedef struct Celula {
  int              chave;
  int              horasChegada;
  int              minutosChegada;
  int              minutosCritico;
  ApontadorCelula  prox;
} Celula;

int  criaListaVazia  (ApontadorCelula *p);
int  criaListaChave  (ApontadorCelula *p, Celula celula);
int  insInicio       (ApontadorCelula *p, Celula celula);
int  insFinal        (ApontadorCelula *p, Celula celula);
int  insOrdem        (ApontadorCelula *p, Celula celula);
int  remInicio       (ApontadorCelula *p);
int  remFinal        (ApontadorCelula *p);
int  remChave        (ApontadorCelula *p, Celula celula);
int  concatListas    (ApontadorCelula  p, ApontadorCelula q, ApontadorCelula *lista);
int  tamLista        (ApontadorCelula  p);
int  mostraLista     (ApontadorCelula *p);


#endif // LLSE_H_INCLUDED
