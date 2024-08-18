#include <stdio.h>
#include <stdlib.h>

#include "LLSE.h"


enum opcoes {opSair, opInsMeio, opRemChave};


// VARI�VEIS GLOBAIS
unsigned int  op = 1;
Apontador     prim;


// FUN��ES
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
  printf("Selecione a op��o desejada:");
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
        printf("ERRO: N�o foi poss�vel INSERIR o Nodo!");

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
        printf("ERRO: N�o foi poss�vel REMOVER o Nodo!");

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

