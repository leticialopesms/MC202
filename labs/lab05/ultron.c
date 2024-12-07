#include <stdio.h>
#include <stdlib.h>
#include "ultron.h"
 
 
p_matriz aloca_matriz (int m, int n) {
    p_matriz mat;
    mat = malloc(sizeof(struct matriz));
    mat->qtd_linhas_usadas = m;
    mat->qtd_linhas_alocadas = m;
    mat->qtd_colunas_usadas = n;
    mat->qtd_colunas_alocadas = n;
 
    mat->dados = malloc(m * sizeof(int *));
    
    for (int i = 0; i < m; i++)
        mat->dados[i] = malloc(n * sizeof(int));
 
    return mat;
}
 
 
void le_matriz (p_matriz mat) {
    for (int i = 0; i < mat->qtd_linhas_alocadas; i++)
        for (int j = 0; j < mat->qtd_colunas_alocadas; j++)
            scanf("%d", &mat->dados[i][j]);
}
 
 
p_vetor le_linha (p_matriz mat) {
    p_vetor vet;
    vet = malloc(sizeof(struct vetor));
 
    vet->n = mat->qtd_colunas_usadas;
    vet->dados = malloc(vet->n * sizeof(int));
    
    for (int j = 0; j < vet->n; j++)
        scanf("%d", &vet->dados[j]);
    
    vet->n = 0;
    return vet;
}
 
 
p_vetor le_coluna (p_matriz mat) {
    p_vetor vet;
    vet = malloc(sizeof(struct vetor));
 
    vet->n = mat->qtd_linhas_usadas;
    vet->dados = malloc(vet->n * sizeof(int));
    
    for (int i = 0; i < vet->n; i++)
        scanf("%d", &vet->dados[i]);
    
    vet->n = 0;
    return vet;
}
 
 
void desaloca_vetor (p_vetor vet) {
    free(vet->dados);
    free(vet);
}
 
 
void imprime_matriz (p_matriz mat) {
    for (int i = 0; i < mat->qtd_linhas_usadas; i++) {
        for (int j = 0; j < mat->qtd_colunas_usadas; j++)
            printf("%d ", mat->dados[i][j]);
        printf("\n");
    }
    printf("###\n");
}
 
 
void desaloca_matriz (p_matriz mat) {
    for (int i = 0; i < mat->qtd_linhas_alocadas; i++)
        free(mat->dados[i]);
    free(mat->dados);
    free(mat);
}
 
 
// Operações:
 
// Operação 1 - IN L
void insere_linha (p_matriz mat, p_vetor linha) {
    for (int k = 0; k < mat->qtd_colunas_usadas; k++)
        mat->dados[mat->qtd_linhas_usadas][k] = linha->dados[k];
    // free(linha);
    mat->qtd_linhas_usadas++;
}
 
 
// Operação 2 - OUT L
void remove_linha (p_matriz mat, int X) {
    int i, j, aux;
    
    for (i = X; i < mat->qtd_linhas_usadas - 1; i++)
        for (j = 0; j < mat-> qtd_colunas_alocadas; j++) {
            aux = mat->dados[i + 1][j];
            mat->dados[i][j] = aux;
        }
    mat->qtd_linhas_usadas--;
}
 
 
// Operação 3 - IN C
void insere_coluna (p_matriz mat, p_vetor coluna) {
    for (int i = 0; i < mat->qtd_linhas_usadas; i++) {
        int j;
        for (j = mat->qtd_colunas_usadas - 1; j >= 0 && mat->dados[i][j] > coluna->dados[i]; j--)
            mat->dados[i][j + 1] = mat->dados[i][j];
        mat->dados[i][j + 1] = coluna->dados[i];
    }
    mat->qtd_colunas_usadas++;
}
 
 
// Operação 4 - OUT C
void remove_coluna (p_matriz mat, int Y) {
    int i, aux;
 
    for (i = 0; i < mat->qtd_linhas_usadas; i++)
        for (int j = 0; j < (mat->qtd_colunas_usadas - Y); j++) {
            aux = mat->dados[i][Y + j + 1];
            mat->dados[i][Y + j] = aux;
        }
    mat->qtd_colunas_usadas--;
}
 
 
void verifica_tamanho (p_matriz mat) {
    if (mat->qtd_linhas_usadas == mat->qtd_linhas_alocadas) {
        // Dobra a quantidade de linhas.
        mat->qtd_linhas_alocadas = (mat->qtd_linhas_alocadas) * 2;
        mat->dados = realloc(mat->dados, mat->qtd_linhas_alocadas * sizeof(int *));
 
        for (int i = (mat->qtd_linhas_alocadas)/2; i < mat->qtd_linhas_alocadas; i++)
            mat->dados[i] = malloc((mat->qtd_colunas_alocadas) * sizeof(int));
    }
 
    if (mat->qtd_colunas_usadas == mat->qtd_colunas_alocadas) {
        // Dobra a quantidade de colunas.
        mat->qtd_colunas_alocadas = (mat->qtd_colunas_alocadas) * 2;
            
        for (int i = 0; i < mat->qtd_linhas_alocadas; i++)
            mat->dados[i] = realloc(mat->dados[i], mat->qtd_colunas_alocadas * sizeof(int));
    }
 
    if (4 * mat->qtd_linhas_usadas <= (mat->qtd_linhas_alocadas)) {
        // Divide pela metade a quantidade de linhas.
        for (int i = mat->qtd_linhas_alocadas; i > (mat->qtd_linhas_alocadas)/2; i--)
            free(mat->dados[i]);
 
        mat->qtd_linhas_alocadas = (mat->qtd_linhas_alocadas) / 2;
    }
 
    if (4 * mat->qtd_colunas_usadas <= (mat->qtd_colunas_alocadas)) {
        // Divide pela metade a quantidade de colunas.
        mat->qtd_colunas_alocadas = (mat->qtd_colunas_alocadas) / 2;
 
        for (int i = 0; i < mat->qtd_linhas_alocadas; i++)
            mat->dados[i] = realloc(mat->dados[i], mat->qtd_colunas_alocadas * sizeof(int));
    }
}