#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <locale.h>



//==============================================================================
// conjuntolib.h
//==============================================================================

/*
#ifndef CONJUNTO_H_INCLUDED
#define CONJUNTO_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
*/

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

//#endif // CONJUNTO_H_INCLUDED



//==============================================================================
// conjuntolib.c
//==============================================================================

/*
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#include "conjuntolib.h"
*/

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



//==============================================================================
// main.c
//==============================================================================

/*
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#include "conjuntolib.h"
*/

enum opcoes {opSair, opCriar, opEstaVazio,
             opInserirElemento, opExcluirElemento,
             opTamanho, opMaior, opMenor, opPertencimento,
             opIdenticos, opSubconjunto, opComplemento,
             opUniao, opInterseccao, opDiferenca, opPartes,
             opMostrar, opCopiar, opDestruir
             };


// VARIÁVEIS
unsigned int op = 1;
Conjunto *C1, *C2;


// FUNÇÕES
unsigned int menu();
void execOp(unsigned int op);
Conjunto *getConjuntoEscolhido();


int main() {
  setlocale(LC_ALL, "portuguese");

  do {
    op = menu();
    execOp(op);
  } while(op != opSair);

  return 0;
}


unsigned int menu() {
  printf("Selecione a opção desejada:");
  printf("\n[1]  Criar Conjunto");
  printf("\n[2]  Verificar Conjunto Vazio");
  printf("\n[3]  Inserir Elemento");
  printf("\n[4]  Excluir Elemento");
  printf("\n[5]  Obter Tamanho");
  printf("\n[6]  Quantidade elementos MAIOR");
  printf("\n[7]  Quantidade elementos MENOR");
  printf("\n[8]  Verificar pertencimento ao Conjunto");
  printf("\n[9]  Conjuntos Idênticos");
  printf("\n[10] Verificar Subconjunto");
  printf("\n[11] Obter Complemento");
  printf("\n[12] Obter União");
  printf("\n[13] Obter Intersecção");
  printf("\n[14] Obter Diferença");
  printf("\n[15] Obter Partes");
  printf("\n[16] Mostrar Conjunto");
  printf("\n[17] Copiar Conjunto");
  printf("\n[18] DESTRUIR Conjunto\n");

  printf("\n[0]  Terminar o programa\n\n");

  scanf("%d", &op);

  return op;
}


void execOp(unsigned int op) {
  int x = 0;
  Conjunto *conjTmp;

  // CONJUNTO TESTE REFERÊNCIA
  /*
  Conjunto CTR;
  Conjunto **CTR;
  */

  printf("\n");

  switch (op) {

    case opCriar:
      /*
      x = criaConjunto(CTR);
      printf("local = %d\n", CTR->qtd);

      x = criaConjunto(conjTmp);
      printf("local = %d\n", conjTmp->qtd);

      if (x)
        printf("AGORA SIM CARAI, AINDA BEM!!!\n\n\n");
      else
        printf("AINDA NAO DEU CERTO..........\n\n\n");
      */

      if (C1 && C2) {
        printf("Os Conjuntos já foram criados!");
      } else {
        if (!C1) { // SE C1 NÃO TIVER SIDO INICIALIZADO
          C1 = constructor();
          if (C1) {
            printf("Conjunto criado com sucesso!\nDeseja criar outro Conjunto? 1 (SIM) ou 0 (NÃO) ");
            scanf("%d", &x);

            if (x == 0)
              break;
          } else
            printf("ERRO: Não foi possível criar o Conjunto!");
        }

        if (!C2) { // SE C2 NÃO TIVER SIDO INICIALIZADO
          C2 = constructor();
          if (C2)
            printf("Conjunto 2 criado com sucesso!");
          else
            printf("ERRO: Não foi possível criar o Conjunto 2!");
        }
      }
    break;


    case opEstaVazio:
      conjTmp = getConjuntoEscolhido();

      printf("%s", conjuntoVazio(conjTmp) ? "Conjunto Vazio!" : "Conjunto com elementos!");
    break;


    case opInserirElemento:
      conjTmp = getConjuntoEscolhido();

      printf("Informe o elemento: ");

      do {
        scanf("%d", &x);

        if (x >= 0) {
          if (insereElementoConjunto(x, conjTmp))
            printf("Inserido com sucesso! Informe outro elemento ou -1 para voltar.\n");
          else
            printf("ERRO: Não foi possível inserir o elemento!\n");
        }
      } while (x >= 0);
    break;


    case opExcluirElemento:
      conjTmp = getConjuntoEscolhido();

      printf("Informe o elemento: ");
      scanf("%d", &x);

      if ((x >= 0) && (excluirElementoConjunto(x, conjTmp)))
        printf("Elemento excluído com sucesso!");
      else
        printf("ERRO: Não foi possível excluir o elemento!");
    break;


    case opTamanho:
      conjTmp = getConjuntoEscolhido();

      printf("Conjunto com %d elemento(s)!", tamanhoConjunto(conjTmp));
    break;


    case opMaior:
      conjTmp = getConjuntoEscolhido();

      printf("Informe o elemento: ");
      scanf("%d", &x);

      printf("%d elemento(s) maiores que %d.", maior(x, conjTmp), x);
    break;


    case opMenor:
      conjTmp = getConjuntoEscolhido();

      printf("Informe o elemento: ");
      scanf("%d", &x);

      printf("%d elemento(s) menores que %d.", menor(x, conjTmp), x);
    break;


    case opPertencimento:
      conjTmp = getConjuntoEscolhido();

      printf("Informe o elemento: ");
      scanf("%d", &x);

      printf("O elemento %d%s pertente ao Conjunto", x, !pertenceConjunto(x, conjTmp) ? " não" : "");
    break;


    case opIdenticos:
      if (C1 && !C2) {
        printf("Conjunto 2 Inexistente!");
      } else {
        printf("Os Conjuntos são %s", (conjuntosIdenticos(C1, C2) ? "Idênticos" : "Diferentes"));
      }
    break;


    case opSubconjunto:
      if (C1 && !C2) {
        printf("Conjunto 2 Inexistente!");
      } else {
        printf("C1%s é subconjunto de C2", (subconjunto(C1, C2) ? " não" : ""));
      }
    break;


    case opComplemento:
      if (C1 && !C2) {
        printf("Conjunto 2 Inexistente!");
      } else {
        conjTmp = complemento(C1, C2);
        printf("Complemento(C1, C2) = ");
        mostraConjunto(conjTmp, -1);
      }
    break;


    case opUniao:
      if (C1 && !C2) {
        printf("Conjunto 2 Inexistente!");
      } else {
        conjTmp = uniao(C1, C2);
        printf("União(C1, C2) = ");
        mostraConjunto(conjTmp, -1);
      }
    break;


    case opInterseccao:
      if (C1 && !C2) {
        printf("Conjunto 2 Inexistente!");
      } else {
        conjTmp = interseccao(C1, C2);
        printf("Intersecção(C1, C2) = ");
        mostraConjunto(conjTmp, -1);
      }
    break;


    case opDiferenca:
      if (C1 && !C2) {
        printf("Conjunto 2 Inexistente!");
      } else {
        conjTmp = diferenca(C1, C2);
        printf("Diferença(C1, C2) = ");
        mostraConjunto(conjTmp, -1);
      }
    break;


    case opPartes:
      printf("\nOpção em desenvolvimento!\n");
    break;


    case opMostrar:
      conjTmp = getConjuntoEscolhido();

      printf("Mostrar em ordem CRESCENTE (1) ou DECRESCENTE (0)?: ");
      scanf("%d", &x);

      if (x == 0 || x == 1) {
        printf("\n");
        mostraConjunto(conjTmp, x);
      }
    break;


    case opCopiar:
      if (C1 && !C2) {
        printf("Conjunto 2 Inexistente!");
      } else {
        if (copiarConjunto(C1, C2))
          printf("Conjunto copiado com sucesso!");
        else
          printf("ERRO: Não foi possível copiar o Conjunto!");
      }
    break;


    case opDestruir:
      conjTmp = getConjuntoEscolhido();

      if (destroiConjunto(conjTmp))
        printf("Conjunto destruído com sucesso!");
      else
        printf("ERRO: Não foi possível destruir o Conjunto!");
    break;


    case opSair:
      printf("\nSAINDO...");
    break;


    default:
      printf("Opção Inválida!");
  }

  printf("\n\n");
}


Conjunto *getConjuntoEscolhido() {
  Conjunto *conjTmp = NULL;
  int x;

  if (C2) {
    printf("Selecionar Conjunto 1 ou 2? ");
    scanf("%d", &x);
    printf("\n");

    conjTmp = (x == 1 ? C1 : C2);
  } else if (C1)
    conjTmp = C1;

  return conjTmp;
}
