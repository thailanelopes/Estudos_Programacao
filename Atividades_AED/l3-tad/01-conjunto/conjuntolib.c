#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#include "conjuntolib.h"

#define _SUCESSO      1
#define _FALHA        0
#define _TRUE         1
#define _FALSE        0
#define _CRESCENTE    1
#define _DECRESCENTE  0

#define LONG_MIN      0
#define LONG_MAX      1000000

// FUNÇÕES ACESSÓRIAS
Conjunto *constructor();
int       getIndexElementoConjunto(int x, Conjunto *C);
void      ordenaConjunto(Conjunto *C, int ordem);

Conjunto *constructor() {
  Conjunto *conjAux;

  conjAux = (Conjunto *) malloc(sizeof(Conjunto));

  if (conjAux)
    conjAux->qtd = 0;

  return conjAux;
}

int getIndexElementoConjunto(int x, Conjunto *C) {
  int i, y = -1;

  if (C) {
    for (i = 0; i < C->qtd; i++) {
      if (C->elementos[i] == x) {
        y = i;
        break;
      }
    }
  }

  return y;
}

void ordenaConjunto(Conjunto *C, int ordem) {
  if (C) {
    int i, j, aux;
    int swap = _FALSE;

    for (i = 0; i < C->qtd; i++) {
      for (j = 0; j < C->qtd; j++) {
        swap = ( (ordem == _DECRESCENTE) && (C->elementos[j] < C->elementos[i]) )
            || ( (ordem == _CRESCENTE)   && (C->elementos[j] > C->elementos[i]) );

        if (swap) {
          aux = C->elementos[i];
          C->elementos[i] = C->elementos[j];
          C->elementos[j] = aux;
        }

        /*
        if (ordem == 0) {
          if (C->elementos[j] < C->elementos[i]) {
            aux = C->elementos[i];
            C->elementos[i] = C->elementos[j];
            C->elementos[j] = aux;
          }
        } else if (ordem == 1) {
          if (C->elementos[j] > C->elementos[i]) {
            aux = C->elementos[i];
            C->elementos[i] = C->elementos[j];
            C->elementos[j] = aux;
          }
        }
        */
      }
    }
  }
}


// FUNÇÕES TAD
int criaConjunto(Conjunto *C) {
  C = (Conjunto *) malloc(sizeof(Conjunto));

  if (C) {
  //C->elementos = (int *) malloc(0);
    C->qtd = 0;
  //printf("%d\n\n", C->qtd);

    return _SUCESSO;
  } else
    return _FALHA;
}

int conjuntoVazio(Conjunto *C) {
  if (C)
    return (C->qtd == 0 ? _TRUE : _FALSE);
  else
    return _FALSE;
}

int insereElementoConjunto(int x, Conjunto *C) {
  int ret = _FALHA;

  if (C) {
    if ( (getIndexElementoConjunto(x, C) < 0) && (C->qtd < LONG_MAX) ) {
      if (C->qtd == 0)
        C->elementos = (int *) malloc(sizeof(int));
      else
        C->elementos = (int *) realloc(C->elementos, (C->qtd+1) * sizeof(int));

      C->elementos[C->qtd] = x;
      C->qtd++;

      ret = _SUCESSO;
    }
  }

  return ret;
}

int excluirElementoConjunto(int x, Conjunto *C) {
  int ret = _FALHA;

  if (C) {
    int y = getIndexElementoConjunto(x, C);

    if (y >= 0) {
      int i;

      for (i = y; i < C->qtd; i++) {
        C->elementos[i] = C->elementos[i+1];
      }

      free(&C->elementos[i]);
      C->qtd--;

      ret = _SUCESSO;
    }
  }

  return ret;
}

int tamanhoConjunto(Conjunto *C) {
  return (C ? C->qtd : 0);
}

int maior(int x, Conjunto *C) {
  int qtd = 0;

  if (C) {
    int i;

    for (i = 0; i < C->qtd; i++) {
      if (C->elementos[i] > x)
        qtd++;
    }
  }

  return qtd;
}

int menor(int x, Conjunto *C) {
  int qtd = 0;

  if (C) {
    int i;

    for (i = 0; i < C->qtd; i++) {
      if (C->elementos[i] < x)
        qtd++;
    }
  }

  return qtd;
}

int pertenceConjunto(int x, Conjunto *C) {
  int i = getIndexElementoConjunto(x, C);

  return (i < 0 ? _FALSE : _TRUE);
}

int conjuntosIdenticos(Conjunto *C1, Conjunto *C2) {
  int ret = _FALSE;

  if (C1 && C2) {
    ret = _TRUE;

    int i, y;

    for (i = 0; i < C1->qtd; i++) {
      y = getIndexElementoConjunto(C1->elementos[i], C2);

      if (y < 0) {
        ret = _FALSE;
        break;
      }
    }
  }

  return ret;
}

int subconjunto(Conjunto *C1, Conjunto *C2) {
  int ret = _FALSE;

  if (C1 && C2) {
    ret = _TRUE;

    int i, y;

    for (i = 0; i < C1->qtd; i++) {
      y = getIndexElementoConjunto(C1->elementos[i], C2);

      if (y < 0) {
        ret = _FALSE;
        break;
      }
    }
  }

  return ret;
}

Conjunto *complemento(Conjunto *C1, Conjunto *C2) {
  Conjunto *conjAux;
  conjAux = constructor();

  if (C1 && C2) {
    int i, y;

    for (i = 0; i < C2->qtd; i++) {
      y = getIndexElementoConjunto(C2->elementos[i], C1);

      if (y < 0)
        insereElementoConjunto(C2->elementos[i], conjAux);
    }
  }

  return conjAux;
}

Conjunto *uniao(Conjunto *C1, Conjunto *C2) {
  Conjunto *conjAux, *conjTmp;
  conjAux = constructor();

  if (C1 && C2) {
    conjAux = C1;
    conjTmp = complemento(C1, C2);

    int i;

    for (i = 0; i < conjTmp->qtd; i++)
      insereElementoConjunto(conjTmp->elementos[i], conjAux);
  }

  return conjAux;
}

Conjunto *interseccao(Conjunto *C1, Conjunto *C2) {
  Conjunto *conjAux;
  conjAux = constructor();

  if (C1 && C2) {
    int i, y;

    for (i = 0; i < C1->qtd; i++) {
      y = getIndexElementoConjunto(C1->elementos[i], C2);

      if (y >= 0)
        insereElementoConjunto(C1->elementos[i], conjAux);
    }
  }

  return conjAux;
}

Conjunto *diferenca(Conjunto *C1, Conjunto *C2) {
  Conjunto *conjAux;
  conjAux = constructor();

  if (C1 && C2) {
    int i, y;

    for (i = 0; i < C1->qtd; i++) {
      y = getIndexElementoConjunto(C1->elementos[i], C2);

      if (y < 0)
        insereElementoConjunto(C1->elementos[i], conjAux);
    }
  }

  return conjAux;
}

Conjunto *conjuntoPartes(Conjunto *C) {

  return C;
}

void mostraConjunto(Conjunto *C, int ordem) {
  int i;

  if (C) {
    if (ordem == _DECRESCENTE || ordem == _CRESCENTE)
      ordenaConjunto(C, ordem);

    printf("[");

    for (i = 0; i < C->qtd; i++)
      printf("%d%s", C->elementos[i], (i < C->qtd-1 ? ", " : ""));

    printf("]");
  }
}

int copiarConjunto(Conjunto *C1, Conjunto *C2) {
  int ret = _FALHA;

  if (C1 && C2) {
    int i;

    for (i = 0; i < C1->qtd; i++)
      insereElementoConjunto(C1->elementos[i], C2);

    ret = _SUCESSO;
  }

  return ret;
}

int destroiConjunto(Conjunto *C) {
  if (C) {
    int i;

    for (i = C->qtd-1; i <= 0 ; i--)
      free(C->elementos[i]);

    if (C->elementos)
      free(C->elementos);

    free(C);

    C = NULL;

    return _SUCESSO;
  } else
    return _FALHA;
}
