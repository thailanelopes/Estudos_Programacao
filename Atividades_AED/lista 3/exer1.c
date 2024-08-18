//==============================================================================
// Arquivo ponto.h
//==============================================================================
//

#ifndef __CONJUNTO_H__
#define __CONJUNTO_H__

#include <stdlib.h>
#include <stdbool.h>


typedef struct conjunto conjunto_t;


conjunto_t *
conjunto_novo(void);


conjunto_t *
conjunto_novo_lendo_vetor(int *vetor, size_t qtd);



bool
conjunto_contem(conjunto_t *conjunto, int elemento);


bool
conjunto_adiciona(conjunto_t *conjunto, int elemento);


bool
conjunto_remove(conjunto_t *conjunto, int elemento);



size_t
conjunto_qtd_itens(conjunto_t *conjunto);


conjunto_t *
conjunto_intersecao(conjunto_t *a, conjunto_t *b);



conjunto_t *
conjunto_uniao(conjunto_t *a, conjunto_t *b);


bool
conjunto_iguais(conjunto_t *a, conjunto_t *b);



const int *
conjunto_vetor(conjunto_t *conjunto);


void
conjunto_libera(conjunto_t *conjunto);

#endif


//======================
// Arquivo ponto.c
//=======================

#include "conjunto.h"
#include <stdlib.h>


struct conjunto {
    int *elementos; 
    size_t tamanho;     

    size_t qtd;     
};


#define CONJUNTO_VETOR_TAM_INICIAL 50
#define CONJUNTO_VETOR_FATOR_AUMENTO 1.5


static bool
conjunto_redimensiona_vetor(conjunto_t *conj, size_t novo_tamanho) {
    int *novo_elementos = realloc(conj->elementos, sizeof(int) * novo_tamanho);

    if (novo_elementos == NULL)
        return false;

    conj->elementos = novo_elementos;
    conj->tamanho = novo_tamanho;

    return true;
}


static bool
conjunto_vetor_cabe(conjunto_t *conj, size_t posicao) {
    if (posicao < conj->tamanho)
        return true; // posicao já cabe no vetor alocado

  
    size_t novo_tamanho = conj->tamanho == 0
                          ? CONJUNTO_VETOR_TAM_INICIAL
                          : conj->tamanho * CONJUNTO_VETOR_FATOR_AUMENTO;

    return conjunto_redimensiona_vetor(conj, novo_tamanho);
}

// Verifica se ha memoria alocada em excesso e libera
static void
conjunto_libera_desnecessario(conjunto_t *conj) {
    size_t tam_reduzido = conj->tamanho / CONJUNTO_VETOR_FATOR_AUMENTO;
    if (tam_reduzido > conj->qtd)
        conjunto_redimensiona_vetor(conj, tam_reduzido);
}


conjunto_t *
conjunto_novo_aloca(size_t tam) {
    conjunto_t *conj = conjunto_novo();

    if (conj == NULL)
        return NULL;

    if (!conjunto_redimensiona_vetor(conj, tam)) {
        conjunto_libera(conj);
        return NULL;
    }

    return conj;
}

conjunto_t *
conjunto_novo(void) {
    conjunto_t *conj = malloc(sizeof(conjunto_t));

    if (conj != NULL) {
        conj->qtd = 0;
        conj->tamanho = 0;
        conj->elementos = NULL;
    }

    return conj;
}

conjunto_t *
conjunto_novo_lendo_vetor(int *vetor, size_t qtd) {
    conjunto_t *conj = conjunto_novo_aloca(qtd);
    if (conj == NULL)
        return NULL;

    for (int i = 0; i < qtd; i++) {
        if (!conjunto_adiciona(conj, vetor[i])) {
            conjunto_libera(conj);
            return NULL;
        }
    }

    return conj;
}



static int
conjunto_encontra_item(conjunto_t *conj, int elemento) {
    for (int i = 0; i < conj->qtd; i++)
        if (conj->elementos[i] == elemento)
            return i;

    return -1;
}


bool
conjunto_contem(conjunto_t *conj, int elemento) {
    return conjunto_encontra_item(conj, elemento) != -1;
}


bool
conjunto_adiciona(conjunto_t *conj, int elemento) {
    if (conjunto_contem(conj, elemento))
        return true;

    if (!conjunto_vetor_cabe(conj, conj->qtd))
        return false;

    conj->elementos[conj->qtd] = elemento;
    conj->qtd++;

    return true;
}


bool
conjunto_remove(conjunto_t *conj, int elemento) {
    int i = conjunto_encontra_item(conj, elemento);
    if (i < 0)
        return false;

    conj->qtd--;
    conj->elementos[i] = conj->elementos[conj->qtd];

    conjunto_libera_desnecessario(conj);

    return true;
}


size_t
conjunto_qtd_itens(conjunto_t *conj) {
    return conj->qtd;
}

conjunto_t *
conjunto_intersecao(conjunto_t *a, conjunto_t *b) {
    conjunto_t *intersect = conjunto_novo_lendo_vetor(a->elementos, a->qtd);

    if (intersect == NULL)
        return NULL;

    for (int i = 0; i < intersect->qtd; i++) {
        if (!conjunto_contem(b, intersect->elementos[i]))
            conjunto_remove(intersect, intersect->elementos[i]);
    }

    return intersect;
}

conjunto_t *
conjunto_uniao(conjunto_t *a, conjunto_t *b) {
    conjunto_t *uniao = conjunto_novo_aloca(conjunto_qtd_itens(a) + conjunto_qtd_itens(b));

    if (uniao == NULL)
        return NULL;

    for (int i = 0; i < a->qtd; i++)
        conjunto_adiciona(uniao, a->elementos[i]);

    for (int i = 0; i < b->qtd; i++)
        conjunto_adiciona(uniao, b->elementos[i]);

    return uniao;
}

bool
conjunto_iguais(conjunto_t *a, conjunto_t *b) {
    if (a->qtd != b->qtd)
        return false;

    for (int i = 0; i < a->qtd; i++) {
        if (!conjunto_contem(b, a->elementos[i]))
            return false;
    }

    return true;
}

const int *
conjunto_vetor(conjunto_t *conj) {
    return conj->elementos;
}

void
conjunto_libera(conjunto_t *conj) {
    if (conj->elementos != NULL)
        free(conj->elementos);

    free(conj);
}

//'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''


#include "conjunto.h"
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdio.h>

static void
init_vetor_aleatorio(int *itens, size_t qtd) {
    for (int i = 0; i < qtd; i++)
        itens[i] = rand() % qtd;
}


static void
print_conjunto(conjunto_t *conj) {
    const int *vetor = conjunto_vetor(conj);
    size_t n = conjunto_qtd_itens(conj);

    for (int i = 0; i < n; i++)
        printf("%d ", vetor[i]);
    puts("");
}

static void
test_conjunto_novo(void) {
    conjunto_t *conjunto = conjunto_novo();
    assert(conjunto != NULL);
    assert(0 == conjunto_qtd_itens(conjunto));

    conjunto_libera(conjunto);


    int vetor_inicial[] = {2, 5, 2, 3, 4, 3};
    conjunto = conjunto_novo_lendo_vetor(vetor_inicial, 6);
    assert(4 == conjunto_qtd_itens(conjunto));

    conjunto_libera(conjunto);
}

static void
test_conjunto_contem(void) {
    conjunto_t *conj = conjunto_novo();
    assert(conj);

    int itens[1024];
    init_vetor_aleatorio(itens, 1024);

    for (int i = 0; i < 1024; i++) {
        conjunto_adiciona(conj, itens[i]);
        assert(conjunto_contem(conj, itens[i]));
    }

    for (int i = 0; i < 1024; i++) {
        assert(conjunto_contem(conj, itens[i]));
    }

    for (int i = 0; i < 1024; i++) {
        conjunto_remove(conj, itens[i]);
        assert(!conjunto_contem(conj, itens[i]));
    }

    conjunto_libera(conj);
}


static void
test_conjunto_adiciona_remove(void) {
    conjunto_t *conj = conjunto_novo();

    conjunto_adiciona(conj, 10);
    assert(conjunto_contem(conj, 10));

    conjunto_adiciona(conj, 20);
    assert(conjunto_contem(conj, 20));

    assert(!conjunto_contem(conj, 15));
    assert(2 == conjunto_qtd_itens(conj));

    assert(!conjunto_remove(conj, 15));
    assert(2 == conjunto_qtd_itens(conj));

    assert(conjunto_remove(conj, 10));
    assert(1 == conjunto_qtd_itens(conj));

    assert(!conjunto_remove(conj, 10));
    assert(1 == conjunto_qtd_itens(conj));

    assert(conjunto_remove(conj, 20));
    assert(0 == conjunto_qtd_itens(conj));

    conjunto_libera(conj);
}

static void
test_conjunto_iguais(void) {
    int itens[1024];
    init_vetor_aleatorio(itens, 1024);

    conjunto_t *a = conjunto_novo_lendo_vetor(itens, 1024);
    conjunto_t *b = conjunto_novo();
    for (int i = 1024 - 1; i >= 0; i--)
        conjunto_adiciona(b, itens[i]);

    assert(conjunto_iguais(a, b));

    conjunto_libera(a);
    conjunto_libera(b);

    a = conjunto_novo();
    conjunto_adiciona(a, 10);
    conjunto_adiciona(a, 10);
    conjunto_adiciona(a, 20);
    conjunto_adiciona(a, 30);

    b = conjunto_novo();
    conjunto_adiciona(b, 20);
    conjunto_adiciona(b, 30);
    conjunto_adiciona(b, 20);
    conjunto_adiciona(b, 10);

    assert(conjunto_iguais(a, b));

    conjunto_libera(a);
    conjunto_libera(b);


    a = conjunto_novo();
    conjunto_adiciona(a, 10);
    conjunto_adiciona(a, 20);

    b = conjunto_novo();
    conjunto_adiciona(b, 10);
    conjunto_adiciona(b, 20);
    conjunto_adiciona(b, 30);

    assert(!conjunto_iguais(a, b));

    conjunto_libera(a);
    conjunto_libera(b);

    a = conjunto_novo();
    conjunto_adiciona(a, 10);
    conjunto_adiciona(a, 20);
    conjunto_adiciona(a, 30);

    b = conjunto_novo();
    conjunto_adiciona(b, 10);
    conjunto_adiciona(b, 20);

    assert(!conjunto_iguais(a, b));

    conjunto_libera(a);
    conjunto_libera(b);

}

static void
test_conjunto_interseccao(void) {
    int itens_b[] = {10, 30, 50, 60, 70};
    conjunto_t *b = conjunto_novo_lendo_vetor(itens_b, 5);

    int itens_a[] = {10, 20, 30, 40, 50};
    conjunto_t *a = conjunto_novo_lendo_vetor(itens_a, 5);

    conjunto_t *c = conjunto_intersecao(a, b);
    assert(3 == conjunto_qtd_itens(c));
    assert(conjunto_contem(c, 10));
    assert(conjunto_contem(c, 30));
    assert(conjunto_contem(c, 50));

    conjunto_libera(a);
    conjunto_libera(b);
    conjunto_libera(c);
}

static void
test_conjunto_uniao(void) {
    int itens_a[] = {10, 20, 30, 40, 50};
    conjunto_t *a = conjunto_novo_lendo_vetor(itens_a, 5);

    int itens_b[] = {10, 30, 50, 60, 70};
    conjunto_t *b = conjunto_novo_lendo_vetor(itens_b, 5);

    conjunto_t *c = conjunto_uniao(a, b);
    assert(7 == conjunto_qtd_itens(c));
    assert(conjunto_contem(c, 10));
    assert(conjunto_contem(c, 20));
    assert(conjunto_contem(c, 30));
    assert(conjunto_contem(c, 40));
    assert(conjunto_contem(c, 50));
    assert(conjunto_contem(c, 60));
    assert(conjunto_contem(c, 70));

    conjunto_libera(a);
    conjunto_libera(b);
    conjunto_libera(c);
}


int
main(void) {
    test_conjunto_novo();
    test_conjunto_contem();
    test_conjunto_adiciona_remove();
    test_conjunto_iguais();
    test_conjunto_interseccao();
    test_conjunto_uniao();

    return 0;
}