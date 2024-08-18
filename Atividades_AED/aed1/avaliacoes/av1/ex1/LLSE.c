#include <stdio.h>
#include <stdlib.h>

#include "LLSE.h"


int  criaListaVazia (Apontador *p);
int  criaListaChave (Apontador *p, unsigned int chave, float dado);
int  insInicio      (Apontador *p, unsigned int chave, float dado);
int  remInicio      (Apontador *p);
int  tamLista       (Apontador p);
void mostraLista    (Apontador p);


int criaListaVazia(Apontador *p) {
  *p = (Apontador) NULL;

  return SUCESSO;
}

int criaListaChave(Apontador *p, unsigned int chave, float dado) {
  *p = (Apontador) NULL;

  return insInicio(p, chave, dado);
}

int insInicio(Apontador *p, unsigned int chave, float dado) {
  Apontador aux;

  aux = (Apontador) malloc(sizeof(Apontador));

  if (aux != NULL) {
    aux->chave = chave;
    aux->dado  = dado;
    aux->prox  = (Apontador) (*p);

    (*p) = aux;

    return SUCESSO;
  } else
    return FALHA;
}

int remInicio(Apontador *p) {
  if ((*p) == NULL)
    return FALHA;
  else {
    Apontador r = (*p);

    (*p) = (*p)->prox;

    free(r);

    return SUCESSO;
  }
}

int tamLista(Apontador p) {
  Apontador r;
  int qtd = 0;

  if (p != NULL) {
    qtd = 1;
    r = p;

    while (r->prox != NULL) {
    //qtd++;
      ++qtd;
      r = r->prox;
    }
  }

  return qtd;
}

void mostraLista(Apontador p) {
  Apontador r;

  if (p == NULL) {
    printf("A lista está VAZIA.\n\n");
  } else {
    r = p;

    while (r->prox != NULL) {
      printf("[%u, (%f)] ->\n", r->chave, r->dado);
      r = r->prox;
    }

    printf("[%u, (%f)] -|\n", r->chave, r->dado);
  }
}


int insMeio(Apontador *p, unsigned int chave, float dado) {
  int qtd = 0;

  if ((*p) != (Apontador) NULL)
    qtd = tamLista(*p);

  if (qtd > 1) {
    int i = 1, pos = qtd / 2;

    Apontador r, aux;

    r = (*p);

    while (i != pos) {
      i++;
      r = r->prox;
    }

  //if (i == pos) {
    aux = (Apontador) malloc(sizeof(Apontador));

    if (aux != NULL) {
      aux->chave = chave;
      aux->dado  = dado;
      aux->prox  = r->prox;
    //aux->prox  = r;

      r->prox = aux;

      return SUCESSO;
    } else {
      return FALHA;
    }
    /*
    } else {
      return FALHA;
    }
    */
  } else {
    return insInicio(p, chave, dado);
  }
}


int remChave(Apontador *p, unsigned int chave) {
  if ((*p) == NULL)
    return FALHA;
  else {
    if ((*p)->chave == chave)
      return remInicio(p);
    else {
      Apontador r, s;

      r = (*p);
      s = (*p);

      while ((r->prox != NULL) && (r->chave != chave)) {
        s = r;
        r = r->prox;
      }

      if (r->chave == chave) {
        s->prox = r->prox;

        free(r);

        return SUCESSO;
      } else
        return FALHA;
    }
  }
}

