#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"
 
//-------------------------------------------------------------------
// Lista Ligada
 
p_no insere_na_lista (p_no lista, int v) {
    p_no novo = malloc(sizeof(struct no));
    novo->v = v;
    novo->prox = lista;
    return novo;
}
 
p_no remove_da_lista (p_no lista, int v) {
    p_no proximo;
    if (lista == NULL)
        return NULL;
    else if (lista->v == v) {
        proximo = lista->prox;
        free(lista);
        return proximo;
    } else {
        lista->prox = remove_da_lista(lista->prox, v);
        return lista;
    }
}
 
void libera_lista (p_no lista) {
    if (lista != NULL) {
        libera_lista(lista->prox);
        free(lista);
    }
}
 
//-------------------------------------------------------------------
// Grafo
 
p_grafo cria_grafo (int tam) {
    int i;
    p_grafo g = malloc(sizeof(struct grafo));
    g->n = tam;
    g->adjacencia = malloc(tam * sizeof(p_no));
    for (i = 0; i < tam; i++)
        g->adjacencia[i] = NULL;
    return g;
}
 
void libera_grafo (p_grafo g) {
    int i;
    for (i = 0; i < g->n; i++)
        libera_lista(g->adjacencia[i]);
    free(g->adjacencia);
    free(g);
}
 
void insere_aresta (p_grafo g, int u, int v) {
    g->adjacencia[v] = insere_na_lista(g->adjacencia[v], u);
    g->adjacencia[u] = insere_na_lista(g->adjacencia[u], v);
}
 
void remove_aresta (p_grafo g, int u, int v) {
    g->adjacencia[v] = remove_da_lista(g->adjacencia[v], u);
    g->adjacencia[u] = remove_da_lista(g->adjacencia[u], v);
    printf("ARESTA %d -> %d REMOVIDO\n", u, v);
}
 
int tem_aresta (p_grafo g, int u, int v) {
    p_no t;
    for (t = g->adjacencia[u]; t != NULL; t = t->prox) {
        if (t->v == v)
            return 1;
    }
    return 0;
}
 
//-------------------------------------------------------------------
// Fila
 
p_fila cria_fila () {
    p_fila f;
    f = malloc(sizeof(struct fila));
    f->ini = NULL;
    f->fim = NULL;
    return f;
}
 
void libera_fila (p_fila f) {
    libera_lista(f->ini);
    free(f);
}
 
void enfileira(p_fila f, int x) {
    p_no novo;
    novo = malloc(sizeof(struct no));
    novo->v = x;
    novo->prox = NULL;
    if (f->ini == NULL)
        f->ini = novo;
    else
        f->fim->prox = novo;
    f->fim = novo;
}
 
int desenfileira(p_fila f) {
    // Supõe que a lista não é vazia
    p_no primeiro = f->ini;
    int x = primeiro->v;
    f->ini = f->ini->prox;
    if (f->ini == NULL)
        f->fim = NULL;
    free(primeiro);
    return x;
}
 
//-------------------------------------------------------------------
// Operações
 
void insertionsort (int v[], int n) {
    int i, j, t;
    for (i = 1; i < n; i++) {
        t = v[i];
        for (j = i; j > 0 && t < v[j-1]; j--)
            v[j] = v[j-1];
        v[j] = t;
    }
}
 
int * busca_em_largura(p_grafo g, int s) {
    int w, v;
    int *pai = malloc(g->n * sizeof(int));
    int *visitado = malloc(g->n * sizeof(int));
    p_fila f = cria_fila();
    for (v = 0; v < g->n; v++) {
        pai[v] = -1;
        visitado[v] = 0;
    }
    enfileira(f,s);
    pai[s] = s;
    visitado[s] = 1;
    while(f->ini != NULL) {
        v = desenfileira(f);
        for (w = 0; w < g->n; w++)
            if (tem_aresta(g, v, w) && !visitado[w]) {
                visitado[w] = 1; /*evita repetição na fila*/
                pai[w] = v;
                enfileira(f, w);
        }
    }
    libera_fila(f);
    free(visitado);
    return pai;
}
 
int consulta_menor_distancia (p_grafo g, int no_origem, int no_fim) {
    int *caminho = busca_em_largura(g, no_fim);
    int no = no_origem;
    int i = 0;
    do {
        no = caminho[no];
        i++;
    } while (no != no_fim);
    free(caminho);
    printf("DISTANCIA %d -> %d = %d\n", no_origem, no_fim, i);
    return i;
}
 
void adiciona_vertice (p_grafo g, int no_novo, int no) {
    g->n++;
    g->adjacencia = realloc(g->adjacencia, g->n * sizeof(p_no));
    g->adjacencia[g->n - 1] = NULL;
 
    int *nos_conectados = malloc(g->n * sizeof(int));   // Quantidade arbitraria
    p_no vertice;
    int n = 0;
    nos_conectados[n] = no;
    for (vertice = g->adjacencia[no]; vertice != NULL; vertice = vertice->prox) {
        n++;
        nos_conectados[n] = vertice->v;
    }
    n++;
    insertionsort(nos_conectados, n);
 
    printf("%d ADICIONADO E CONECTADO A", no_novo);
    for (int i = 0; i < n; i++) {
        insere_aresta(g, nos_conectados[i], no_novo);
        printf(" %d", nos_conectados[i]);
    }
    printf("\n");
    free(nos_conectados);
}