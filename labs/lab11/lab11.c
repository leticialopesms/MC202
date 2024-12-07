#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"
 
int main () {
 
    // Construção do grafo
 
    int C;  // Quantidade de vértices do tipo C
    int P;  // Quantidade de vértices do tipo P
    int E;  // Quantidade de arestas
    
    scanf("%d %d", &C, &P);
    scanf("%d", &E);
 
    p_grafo grafo = cria_grafo(C+P);
 
    for (int i = 0; i < E; i++) {
        int v1, v2;
        scanf("%d %d", &v1, &v2);
        insere_aresta(grafo, v1, v2);
    }
    printf("GRAFO AMZ CONSTRUIDO!\n");
 
    // Operações
 
    int Q;  // Quantidade de operações:
    char operacao;
    scanf("%d", &Q);
 
    for (int i = 0; i < Q; i++) {
        scanf(" %c", &operacao);
        if (operacao == 'D') {
            int no_C, no_P, x, distancia;
            scanf("%d %d %d", &no_C, &no_P, &x);
 
            distancia = consulta_menor_distancia(grafo, no_C, no_P);
 
            if (distancia > x)
                adiciona_vertice(grafo, grafo->n, no_P);
        }
        if (operacao == 'R') {
            int no_C, no_P;
            scanf("%d %d", &no_C, &no_P);
            remove_aresta(grafo, no_C, no_P);
        }
    }
    libera_grafo(grafo);
    return 0;
}