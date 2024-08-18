#include <stdio.h>
#include <stdlib.h>

#include "LLSE.h"


int criaListaVazia(ApontadorCelula * p) {
  (*p) = (ApontadorCelula) NULL;

  return SUCESSO;
}

int criaListaChave(ApontadorCelula * p, Celula celula) {
  (*p) = (ApontadorCelula) NULL;

  return insInicio(p, celula);
}

int insInicio(ApontadorCelula *p, Celula celula) {
  ApontadorCelula q;

  q = (ApontadorCelula) malloc( sizeof (Celula) );

  if (q == NULL) {
    return FALHA;
  } else {
    q->chave          = celula.chave;
    q->horasChegada   = celula.horasChegada;
    q->minutosChegada = celula.minutosChegada;
    q->minutosCritico = celula.minutosCritico;
    q->prox           = (ApontadorCelula) (*p);

    (*p) = q;

    return SUCESSO;
 }
}

int insFinal(ApontadorCelula *p, Celula celula) {
  ApontadorCelula q, r;

  if ((*p) == NULL)
    return (insInicio (p, celula));
  else {
    q = (ApontadorCelula) malloc( sizeof (Celula) );

    if (q == NULL) {
      return (FALHA);
    } else {
      q->chave          = celula.chave;
      q->horasChegada   = celula.horasChegada;
      q->minutosChegada = celula.minutosChegada;
      q->minutosCritico = celula.minutosCritico;
      q->prox           = (ApontadorCelula) NULL;

      r = (*p);

      while (r->prox != NULL) {
        r = r->prox;
      }

      r->prox = q;

      return (SUCESSO);
    }
  }
}


int insOrdem(ApontadorCelula *p, Celula celula) {
  ApontadorCelula q, r, s;

  if ((*p) == NULL) {
    return insInicio(p, celula);
  } else {
    if ((*p) -> prox == NULL) {
      if (celula.chave < (*p)->chave) {
        return insInicio(p, celula);
      } else {
        return insFinal(p, celula);
      }
    } else {
      if (celula.chave < (*p) -> chave) {
        return insInicio(p, celula);
      } else {
        q = (ApontadorCelula) malloc( sizeof (Celula) );

        if (q == NULL) {
          return FALHA;
        }

        q->chave = celula.chave;
        r = (*p);

        while (((r->chave) < celula.chave) && ((r->prox) != NULL)) {
          s = r;
          r = r->prox;
        }

        if (r->chave < celula.chave) {
          q->prox = (ApontadorCelula) NULL;
          r->prox = q;
        } else {
          q->prox = r;
          s->prox = q;
        }
      }
    }

    return SUCESSO;
  }
}

int remInicio(ApontadorCelula *p) {
  ApontadorCelula r;

  if ((*p) == NULL) {
    return FALHA;
  } else {
    r = (*p);

    (*p) = (*p)->prox;

    free(r);

    return SUCESSO;
  }
}

int remFinal(ApontadorCelula *p) {
  ApontadorCelula r, s;

  if ((*p) == NULL) {
    return FALHA;
  } else {
    r = (*p);
    s = (*p);

    if ((r->prox) == NULL) {
      return remInicio(p);
    } else {
      while ((r->prox) != NULL) {
        s = r;
        r = (r->prox);
      }

      (s ->prox) = (ApontadorCelula) NULL;

      free(r);

      return SUCESSO;
    }
  }
}

int remChave(ApontadorCelula *p, Celula celula) {
  ApontadorCelula r, s;

  if ((*p) == NULL) {
     return FALHA;
  } else {
    r = (*p);
    s = (*p);

    if ((r ->prox) == NULL) {
      if (r->chave == celula.chave) {
        return remInicio(p);
      } else {
        return FALHA;
      }
    } else {
      if (r->chave == celula.chave) {
        return remInicio(p);
      } else {
        while (((r->prox) != NULL) && (r->chave != celula.chave)) {
          s = r;
          r = r->prox;
        }

        if (r->chave == celula.chave) {
          s->prox = r->prox;

          free(r);

          return SUCESSO;
         } else {
          return FALHA;
         }
      }
    }
  }
}

int ConcatListas (ApontadorCelula p, ApontadorCelula q, ApontadorCelula *lista) {
  if (criaListaVazia(&lista)) {
    int i;
    Celula c;
    ApontadorCelula r;

    for (i = 0; i < 2; i++) {
      r = (i == 0) ? p : q;

      while (r->prox != NULL) {
        c.chave          = r->chave;
        c.horasChegada   = r->horasChegada;
        c.minutosChegada = r->minutosChegada;
        c.minutosCritico = r->minutosCritico;

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
  int tam = 0;

  if (p == NULL) {
    return (tam);
  } else {
    tam = 1;
    r   = p;

    while (r->prox != NULL) {
      ++tam;
      r = r->prox;
    }

    return tam;
  }
}

int mostraLista(ApontadorCelula * p) {
  ApontadorCelula r;

  if (p == NULL) {
    printf("A lista está VAZIA.\n\n");

    return FALHA;
  } else {
    r = p;

    while (r->prox != NULL) {
    //printf("[%d, (%d)] -> ", r->chave, r->dado);
      r = r->prox;
    }

  //printf("[%d, (%d)] -|", r->chave, r->dado);
  }

  return SUCESSO;

  /*
  ApontadorCelula r;

  if ((*p) == NULL) {
    printf("A lista está VAZIA.\n\n");
  }
  else {
    r = (*p);

    while (r->prox != NULL) {
      printf("[%d, (%d)] -> ", (r -> chave), (r -> dado));
      r = r->prox;
    }

    printf("[%d, (%d)] -| \n\n", (r -> chave), (r -> dado));
  }
  return(SUCESSO);
  */
}
