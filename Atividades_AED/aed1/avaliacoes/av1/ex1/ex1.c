//==============================================================================
// LLSE.h
//==============================================================================


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



//==============================================================================
// LLSE.c
//==============================================================================


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
    qtd = tamLista(p);

  if (qtd > 1) {
    int i = 0, pos = qtd / 2;

    Apontador r, s, aux;

    r = (*p);
    s = (*p);

    while ((i != pos) && (r->prox != NULL)) {
      s = r;
      r = r->prox;
      i++;
    }

    if (i == pos) {
      aux = (Apontador) malloc(sizeof(Apontador));

      if (aux != NULL) {
        aux->chave = chave;
        aux->dado  = dado;
        aux->prox  = r;

        s->prox = aux;

        return SUCESSO;
      } else {
        return FALHA;
      }
    } else {
      return FALHA;
    }
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


//==============================================================================
// main.c
//==============================================================================


enum opcoes {opSair, opInsMeio, opRemChave};


// VARIÁVEIS GLOBAIS
unsigned int  op = 1;
Apontador     prim;


// FUNÇÕES
unsigned int  menu();
void          execOp(unsigned int op);


int main() {
  printf("Lista Linear Simplesmente Encadeada\n\n");

  do {
    op = menu();
    execOp(op);
  } while(op != opSair);

  return 0;
}


unsigned int menu() {
  printf("Selecione a opção desejada:");
  printf("\n[1]  Inserir Nodo");
  printf("\n[2]  Remover Chave");

  printf("\n[0]  Terminar o programa\n\n");

  scanf("%d", &op);

  return op;
}


void execOp(unsigned int op) {
  unsigned int ret, chave;
  float dado;

  printf("\n");

  switch (op) {

    case opInsMeio:
      printf("Informe a chave: ");
      scanf("%u", &chave);

      printf("Informe o dado: ");
      scanf("%f", &dado);

      ret = insMeio(&prim, chave, dado);

      printf("\n");

      if (ret) {
        printf("Nodo INSERIDO com Sucesso!\n");
        mostraLista(prim);
      } else
        printf("ERRO: Não foi possível INSERIR o Nodo!");

      printf("\n");
    break;


    case opRemChave:
      printf("Informe a chave: ");
      scanf("%u", &chave);

      ret = remChave(&prim, chave);

      printf("\n");

      if (ret)
        printf("Nodo REMOVIDO com Sucesso!");
      else
        printf("ERRO: Não foi possível REMOVER o Nodo!");

      printf("\n");
    break;


    case opSair:
      printf("\nSAINDO...");
    break;


    default:
      printf("Opção Inválida!");


  }

  printf("\n\n");

}
