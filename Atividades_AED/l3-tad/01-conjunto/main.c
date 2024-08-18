#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#include "conjuntolib.h"

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
