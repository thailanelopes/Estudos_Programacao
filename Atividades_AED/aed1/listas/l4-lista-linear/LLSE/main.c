#include <stdio.h>
#include <stdlib.h>

#include "LLSE.h"


enum opcoes {opSair, opCriarVazio, opCriarComCelula,
             opInsInicio, opInsFim, opInsOrdem,
             opRemInicio, opRemFim, opRemChave,
             opConcatListas, opTamLista, opMostraLista
             };


// VARI�VEIS GLOBAIS
unsigned int     op = 1;
Celula           celula;
ApontadorCelula  lista1, lista2;


// FUN��ES
unsigned int     menu();
void             execOp(unsigned int op);
ApontadorCelula  getListaEscolhida();


int main() {
  printf("Lista Linear Simplesmente Encadeada\n\n\n");
//intResultado = CriarListaVazia(&prim);

  do {
    op = menu();
    execOp(op);
  } while(op != opSair);

  return 0;
}


unsigned int menu() {
  printf("Selecione a op��o desejada:");
  printf("\n[1]  Criar Lista Vazia");
  printf("\n[2]  Criar Lista com C�lula");
  printf("\n[3]  Inserir no In�cio");
  printf("\n[4]  Inserir no Fim");
  printf("\n[5]  Inserir em Ordem");
  printf("\n[6]  Remover no In�cio");
  printf("\n[7]  Remover no Fim");
  printf("\n[8]  Remover Chave");
  printf("\n[9]  Concatenar Listas");
  printf("\n[10]  Obter Tamanho da Lista");
  printf("\n[11] Mostrar Lista\n");

  printf("\n[0]  Terminar o programa\n\n");

  scanf("%d", &op);

  return op;
}


void execOp(unsigned int op) {
  unsigned int ret, x = 0;
  ApontadorCelula listaTmp;

  printf("\n");

  switch (op) {

    case opCriarVazio:
      if (lista1 && lista2) {
        printf("As Listas j� foram criados!");
      } else {
        if (!lista1) {
          if (criaListaVazia(&lista1)) {
            printf("Lista criada com sucesso!\n\nDeseja criar outra Lista? 1 (SIM) ou 0 (N�O) ");
            scanf("%d", &x);
            printf("\n");

            if (x == 0)
              break;
          } else {
            printf("ERRO: N�o foi poss�vel criar a Lista.\n");

            exit(EXIT_FAILURE);
          }

          printf("\n");
        }

        if (!lista2) {
          if (criaListaVazia(&lista2))
            printf("Lista 2 criada com sucesso!");
          else
            printf("ERRO: N�o foi poss�vel criar a Lista 2!");

          printf("\n");
        }
      }
    break;


    case opCriarComCelula:
      if (lista1 && lista2) {
        printf("As Listas j� foram criados!");
      } else {
        // LISTA 1
        printf("Digite a chave: ");
        scanf("%d", &celula.chave);

        if (celula.chave != CHAVE_INVALIDA) {
          printf("Digite o dado: ");
          scanf("%d", &celula.dado);

          if (!lista1) {
            if (criaListaChave(&lista1, celula)) {
              printf("Lista CRIADA com sucesso!\nDeseja criar outra Lista? 1 (SIM) ou 0 (N�O) ");
              scanf("%d", &x);

              if (x == 0)
                break;
            } else {
              printf("ERRO: N�o foi poss�vel CRIAR a Lista.");

              exit(EXIT_FAILURE);
            }
          }
        }

        printf("\n");

        // LISTA 2
        printf("Digite a chave: ");
        scanf("%d", &celula.chave);

        if (celula.chave != CHAVE_INVALIDA) {
          printf("Digite o dado: ");
          scanf("%d", &celula.dado);

          if (!lista2) {
            if (criaListaChave(&lista2, celula))
              printf("Lista 2 CRIADA com sucesso!");
            else
              printf("ERRO: N�o foi poss�vel CRIAR a Lista 2!");
          }
        }

        printf("\n");
      }
    break;


    case opInsInicio:
    case opInsFim:
    case opInsOrdem:
      listaTmp = getListaEscolhida();

      printf("Digite a chave: ");
      scanf("%d", &celula.chave);

      if (celula.chave != CHAVE_INVALIDA) {
        printf("Digite o dado: ");
        scanf("%d", &celula.dado);

        switch (op) {
          case opInsInicio:
            ret = insInicio(&listaTmp, celula);
          break;

          case opInsFim:
            ret = insFinal(&listaTmp, celula);
          break;

          case opInsOrdem:
            ret = insOrdem(&listaTmp, celula);
          break;
        }

        printf("\n");

        if (ret)
          printf("C�lula INSERIDA com Sucesso!");
        else
          printf("ERRO: N�o foi poss�vel INSERIR c�lula!");

        printf("\n");
      }
    break;


    case opRemInicio:
    case opRemFim:
    case opRemChave:
      listaTmp = getListaEscolhida();

      switch (op) {
        case opRemInicio:
          ret = remInicio(&listaTmp);
        break;

        case opRemFim:
          ret = remFinal(&listaTmp);
        break;

        case opRemChave:
          printf("Digite a chave: ");
          scanf("%d", &celula.chave);

          if (celula.chave != CHAVE_INVALIDA)
            ret = remChave(&listaTmp, celula);

          printf("\n");
        break;
      }

      if (ret)
        printf("C�lula REMOVIDA com Sucesso!");
      else
        printf("ERRO: N�o foi poss�vel REMOVER c�lula!");

      printf("\n");
    break;


    /*
    case opRemChave:
      ApontadorCelula listaTmp = getListaEscolhida();

      printf("Digite a chave: ");
      scanf("%d", &celula.chave);

      if (celula.chave != CHAVE_INVALIDA) {
        if (remChave(&listaTmp, celula))
          printf("C�lula REMOVIDA com Sucesso!");
        else
          printf("ERRO: N�o foi poss�vel REMOVER c�lula!");
      }
    break;
    */


    case opConcatListas:
      if (concatListas(lista1, lista2, &listaTmp) == SUCESSO)
        printf("Listas Concatenadas com Sucesso!");
      else
        printf("ERRO: N�o foi poss�vel CONCATENAR as Listas!");;

      printf("\n");
    break;


    case opTamLista:
      listaTmp = getListaEscolhida();

      x = tamLista(listaTmp);
      x ? printf("Lista Vazia!") : printf("Lista com %d c�lulas!", x);

      printf("\n");
    break;


    case opMostraLista:
      listaTmp = getListaEscolhida();

      x = mostraLista(listaTmp);

      printf("\n");
    break;


    case opSair:
      printf("\nSAINDO...");
    break;


    default:
      printf("Op��o Inv�lida!");


  }

  printf("\n\n");

}


ApontadorCelula getListaEscolhida(){
  ApontadorCelula listaTmp = (ApontadorCelula) NULL;

  if (lista2) {
    unsigned int x;

    printf("Selecionar Lista 1 ou 2? ");
    scanf("%d", &x);
    printf("\n");

    listaTmp = (x == 1 ? lista1 : lista2);
  } else if (lista1)
    listaTmp = lista1;

  return listaTmp;
}
