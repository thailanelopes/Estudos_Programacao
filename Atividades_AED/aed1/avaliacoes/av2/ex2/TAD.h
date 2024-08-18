#ifndef TAD_H_INCLUDED
#define TAD_H_INCLUDED


#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


#define _SUCESSO      1
#define _FALHA        0
#define _CRESCENTE    1
#define _DECRESCENTE  0

#define LONG_MIN      0
#define LONG_MAX      1000000


int  Crescente   (int *lista, int tam);
int  Decrescente (int *lista, int tam);
int  Maior       (int *lista, int tam);
int  Menor       (int *lista, int tam);
void MostraLista (int *lista, int tam);


#endif // TAD_H_INCLUDED
