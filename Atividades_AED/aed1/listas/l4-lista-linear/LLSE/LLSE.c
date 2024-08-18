#include <stdio.h>
#include <stdlib.h>

#include "LLSE.h"


#define SUCESSO          1
#define FALHA            0
#define CHAVE_INVALIDA   0


int criaListaVazia(ApontadorCelula *p) {
  *p = (ApontadorCelula) NULL;

  return SUCESSO;
}

int criaListaChave(ApontadorCelula *p, Celula celula) {
  *p = (ApontadorCelula) NULL;

  return insInicio(p, celula);
}

int insInicio(ApontadorCelula *p, Celula celula) {
  ApontadorCelula aux = (ApontadorCelula) malloc(sizeof(Celula));

//if (aux) {
  if (aux != NULL) {
    aux->chave = celula.chave;
    aux->dado  = celula.dado;
    aux->prox  = (ApontadorCelula) *p;

    *p = aux;

    return SUCESSO;
  } else
    return FALHA;
}

int insFinal(ApontadorCelula *p, Celula celula) {
  if (! *p)
    return insInicio(p, celula);
  else {
    ApontadorCelula aux, r;

    aux = (ApontadorCelula) malloc(sizeof(Celula));

    if (aux) {
      aux->chave = celula.chave;
      aux->dado  = celula.dado;
      aux->prox  = (ApontadorCelula) NULL;

      r = *p;

      while (r->prox != NULL)
        r = r->prox;

      r->prox = aux;

      return SUCESSO;
    } else
      return FALHA;
  }
}

int insOrdem       (ApontadorCelula *p, Celula celula) {

}

int remInicio(ApontadorCelula *p) {
  if ((*p) == NULL)
    return FALHA;
  else {
    ApontadorCelula r = (*p);

    (*p) = (*p)->prox;

    free(r);

    return SUCESSO;
  }
}

int remFinal(ApontadorCelula *p) {
  if ((*p) == NULL)
    return FALHA;
  else if ((*p)->prox == NULL)
    return remInicio(p);
  else {
    ApontadorCelula r, s;

    r = (*p);
    s = (*p);

    while (r->prox != NULL) {
      s = r;
      r = r->prox;
    }

    s->prox = (ApontadorCelula) NULL;

    free(r);

    return SUCESSO;
  }
}

int remChave(ApontadorCelula *p, Celula celula) {
  if ((*p) == NULL)
    return FALHA;
  else {
    if ((*p)->chave == celula.chave)
      return remInicio(p);
    else {
      ApontadorCelula r, s;

      r = (*p);
      s = (*p);

      while ((r->prox != NULL) && (r->chave != celula.chave)) {
        s = r;
        r = r->prox;
      }

      if (r->chave == celula.chave) {
        s->prox = r->prox;

        free(r);

        return SUCESSO;
      } else
        return FALHA;
    }
  }
}

int concatListas(ApontadorCelula p, ApontadorCelula q, ApontadorCelula *lista) {
  if (criaListaVazia(&lista)) {
    int i;
    Celula c;
    ApontadorCelula r;

    for (i = 0; i < 2; i++) {
      r = (i == 0) ? p : q;

      while (r->prox != NULL) {
        c.chave = r->chave;
        c.dado  = r->dado;

        if (insFinal(&lista, c))
          r = r->prox;
        else
          return FALHA;
      }
    }
  } else
    return FALHA;
}

int tamLista(ApontadorCelula p) {
  ApontadorCelula r;
  int qtd = 0;

  if (p != NULL) {
    r = p;

    while (r->prox != NULL) {
      r = r->prox;
      qtd++;
    }
  }

  return qtd;
}

int mostraLista(ApontadorCelula p) {
  ApontadorCelula r;

  if (p == NULL) {
    printf("A lista está VAZIA.\n\n");

    return FALHA;
  } else {
    r = p;

    while (r->prox != NULL) {
      printf("[%d, (%d)] -> ", r->chave, r->dado);
      r = r->prox;
    }

    printf("[%d, (%d)] -|", r->chave, r->dado);
  }

  return SUCESSO;
}

