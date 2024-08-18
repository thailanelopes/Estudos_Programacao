#ifndef CONJUNTO_H_INCLUDED
#define CONJUNTO_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

struct conjunto {
  int *elementos;
  int qtd;
};

typedef struct conjunto Conjunto;

int        criaConjunto(Conjunto *C);
int        conjuntoVazio(Conjunto *C);
int        insereElementoConjunto(int x, Conjunto *C);
int        excluirElementoConjunto(int x, Conjunto *C);
int        tamanhoConjunto(Conjunto *C);
int        maior(int x, Conjunto *C);
int        menor(int x, Conjunto *C);
int        pertenceConjunto(int x, Conjunto *C);
int        conjuntosIdenticos(Conjunto *C1, Conjunto *C2);
int        subconjunto(Conjunto *C1, Conjunto *C2);
Conjunto  *complemento(Conjunto *C1, Conjunto *C2);
Conjunto  *uniao(Conjunto *C1, Conjunto *C2);
Conjunto  *interseccao(Conjunto *C1, Conjunto *C2);
Conjunto  *diferenca(Conjunto *C1, Conjunto *C2);
Conjunto  *conjuntoPartes(Conjunto *C);
void       mostraConjunto(Conjunto *C, int ordem);
int        copiarConjunto(Conjunto *C1, Conjunto *C2);
int        destroiConjunto(Conjunto *C);

#endif // CONJUNTO_H_INCLUDED
