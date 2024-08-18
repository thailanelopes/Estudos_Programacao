#include <stdio.h>
#include <stdlib.h>

#include "TAD.h"


void Ordena(int **lista, int tam, int ordem);


void Ordena(int **lista, int tam, int ordem) {
  if (*lista) {
    int i, j, aux;
    int swap = 0;

    for (i = 0; i < tam; i++) {
      for (j = 0; j < tam; j++) {
        swap = ( (ordem == _DECRESCENTE) && (*(&lista[j]) < *(&lista[i])) )
            || ( (ordem == _CRESCENTE)   && (*(&lista[j]) > *(&lista[i])) );

        if (swap) {
          aux = *(&lista[i]);
          *(&lista[i]) = *(&lista[j]);
          *(&lista[j]) = aux;
        }
      }
    }
  }
}

int Crescente(int *lista, int tam) {
  Ordena(&lista, tam, _CRESCENTE);

  return _SUCESSO;
}


int Decrescente(int *lista, int tam) {
  Ordena(&lista, tam, _DECRESCENTE);

  return _SUCESSO;
}


int Maior(int *lista, int tam) {
  int i, num = lista[0];

  for (i = 1; i < tam; i++) {
    if (lista[i] > num)
      num = lista[i];
  }

  return num;
}


int Menor(int *lista, int tam) {
  int i, num = lista[0];

  for (i = 1; i < tam; i++) {
    if (lista[i] < num)
      num = lista[i];
  }

  return num;
}


void MostraLista(int *lista, int tam) {
  int i;

  for (i = 0; i < tam; i++)
    printf("%d ", *(&lista[i]));
}
