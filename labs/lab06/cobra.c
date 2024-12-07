#include <stdio.h>
#include <stdlib.h>
#include "cobra.h"
 
// --------------------------------------------------------------
// Lista duplamente ligada
 
p_no inicializa_no (posicao pos) {
    // Insere o primeiro nó.
    // Se refere à posição inicial da cobra no tabuleiro.
    p_no novo = malloc(sizeof(struct no));
    novo->dados = pos;
    novo->ant = NULL;
    novo->prox = NULL;
    return novo;
}
 
 
p_no insere_novo_no (p_no cabeca, posicao pos) {
    // Insere um novo nó na lista ligada.
    // Está garantido que a lista não é NULL.
    p_no novo = malloc(sizeof(struct no));
    novo->dados = pos;
    cabeca->ant = novo;
    novo->prox = cabeca;
    cabeca = novo;
    return cabeca;
}
 
 
void remove_no (p_no no) {
    // Remove um nó da lista ligada.
    // O nó a ser removido é sempre o último da lista.
    (no->ant)->prox = NULL;
    free(no);
}
 
 
void destroi_lista (p_no lista) {
    if (lista != NULL) {
        destroi_lista(lista->prox);
        free(lista);
    }
}
 
 
// --------------------------------------------------------------
// Matriz
 
p_matriz aloca_matriz (int m, int n) {
    p_matriz mat;
    mat = malloc(sizeof(struct matriz));
    mat->M = m;
    mat->N = n;
 
    mat->dados = malloc(m * sizeof(int *));
   
    for (int i = 0; i < m; i++)
        mat->dados[i] = malloc(n * sizeof(int));
 
    return mat;
}
 
 
void preenche_matriz_inicial (p_matriz mat, posicao cobra, posicao fruta) {
    for (int i = 0; i < mat->M; i++)
        for (int j = 0; j < mat->N; j++)
            mat->dados[i][j] = 0;
    mat->dados[cobra.linha][cobra.coluna] = 1;
    mat->dados[fruta.linha][fruta.coluna] = -1;
}
 
 
void destroi_matriz (p_matriz mat) {
    for (int i = 0; i < mat->N; i++)
        free(mat->dados[i]);
    free(mat->dados);
    free(mat);
}
 
 
void imprime_matriz (p_matriz mat) {
    for (int i = 0; i < mat->M; i++) {
        for (int j = 0; j < mat->N; j++)
            if (mat->dados[i][j] == 0)
                printf("_ ");
            else if (mat->dados[i][j] == 1)
                printf("# ");
            else if (mat->dados[i][j] == -1)
                printf("* ");
        printf("\n");
    }
    printf("\n");
}
 
 
// --------------------------------------------------------------
// JOGO
 
posicao verifica_nova_posicao(p_matriz mat, p_no cabeca, char operacao) {
    posicao nova_pos;
    if (operacao == 'w') {
        if (cabeca->dados.linha == 0)
            nova_pos.linha = mat->M - 1;
        else
            nova_pos.linha = cabeca->dados.linha - 1;
        nova_pos.coluna = cabeca->dados.coluna;
    }
    else if (operacao == 'a') {
        nova_pos.linha = cabeca->dados.linha;
        if (cabeca->dados.coluna == 0)
            nova_pos.coluna = mat->N - 1;
        else
            nova_pos.coluna = cabeca->dados.coluna - 1;
    }
    else if (operacao == 's') {
        if (cabeca->dados.linha == mat->M - 1)
            nova_pos.linha = 0;
        else
            nova_pos.linha = cabeca->dados.linha + 1;
        nova_pos.coluna = cabeca->dados.coluna;
    }
    else if (operacao == 'd') {
        nova_pos.linha = cabeca->dados.linha;
        if (cabeca->dados.coluna == mat->N - 1)
            nova_pos.coluna = 0;
        else
            nova_pos.coluna = cabeca->dados.coluna + 1;
    }
    return nova_pos;
}