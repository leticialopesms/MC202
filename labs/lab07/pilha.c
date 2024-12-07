#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"

p_no cria_lista () {
    p_no lista;
    lista = malloc(sizeof(struct no));
    lista->dado[0] = '\0';
    lista->prox = NULL;
    lista->n = 0;
    return lista;
}

p_pilha cria_pilha () {
    p_pilha p = malloc(sizeof(struct pilha));
    p_no superficie = cria_lista();
    p->topo = superficie;
    return p;
}

void empilha (p_pilha pilha) {
    p_no novo = malloc(sizeof(struct no));
    novo->dado[0] = '\0';
    novo->prox = pilha->topo;
    novo->n = 0;
    pilha->topo = novo;
}

void desempilha (p_pilha pilha) {
    p_no topo = pilha->topo;
    pilha->topo = pilha->topo->prox;
    free(topo);
}

void destroi_pilha (p_pilha pilha) {
    while (pilha->topo != NULL) {
        desempilha(pilha);
    }
    free(pilha);
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"
 
p_no cria_lista () {
    p_no lista;
    lista = malloc(sizeof(struct no));
    lista->dado[0] = '\0';
    lista->prox = NULL;
    lista->n = 0;
    return lista;
}
 
p_pilha cria_pilha () {
    p_pilha p = malloc(sizeof(struct pilha));
    p_no superficie = cria_lista();
    p->topo = superficie;
    return p;
}
 
void empilha (p_pilha pilha) {
    p_no novo = malloc(sizeof(struct no));
    novo->dado[0] = '\0';
    novo->prox = pilha->topo;
    novo->n = 0;
    pilha->topo = novo;
}
 
void desempilha (p_pilha pilha) {
    p_no topo = pilha->topo;
    pilha->topo = pilha->topo->prox;
    free(topo);
}
 
void destroi_pilha (p_pilha pilha) {
    while (pilha->topo != NULL) {
        desempilha(pilha);
    }
    free(pilha);
}