#ifndef LLSE_H_INCLUDED
#define LLSE_H_INCLUDED


#include <stdio.h>
#include <stdlib.h>

#define SUCESSO   1
#define FALHA    -1


typedef struct Nodo *Apontador;

struct Nodo {
  unsigned int  chave;
  float         dado;
  Apontador     prox;
};


int insMeio  (Apontador *p, unsigned int chave, float dado);
int remChave (Apontador *p, unsigned int chave);


#endif // LLSE_H_INCLUDED
