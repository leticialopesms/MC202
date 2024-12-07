#include <stdio.h>
#include <stdlib.h>
#include "hash.h"
 
 
p_hash aloca_hash () {
    p_hash tabela;
    tabela = malloc(sizeof(struct Hash));
 
    for (int i = 0; i < MAX; i++) {
        tabela->dados[i].ID = -1;
        // "-1" quer dizer vazio
    }
    return tabela;
}
 
 
int funcao_hash (long long identificador) {
    return identificador % MAX;
}
 
 
void insere_hash (p_hash tabela, Processo arquivo) {
    int f = funcao_hash(arquivo.ID);
 
    while (tabela->dados[f].ID != -1) {
        f = (f+1) % MAX; // Percorre todo vetor, voltando pro inicio na última posição.
    }
    tabela->dados[f] = arquivo;
    printf("PROCESSO %lld INSERIDO!\n", arquivo.ID);
}
 
 
void remove_hash (p_hash tabela) {
    long long id;
    scanf("%lld", &id);
 
    int f = funcao_hash(id);
 
    while (tabela->dados[f].ID != id) {
        f = (f+1) % MAX; // Percorre todo vetor, voltando pro inicio na última posição.
    }
    tabela->dados[f].ID = -1;
    printf("PROCESSO %lld REMOVIDO!\n", id);
}
 
 
void consulta_nome (p_hash tabela) {
    long long id;
    scanf("%lld", &id);
 
    int f = funcao_hash(id);
 
    while (tabela->dados[f].ID != -1) {
        if (tabela->dados[f].ID == id) {
            printf("PROCESSO %lld: %s\n", id, tabela->dados[f].nome);
            break;
        }
        f = (f+1) % MAX; // Percorre todo vetor, voltando pro inicio na última posição.
    }
    if (tabela->dados[f].ID == -1) {
        printf("PROCESSO %lld NAO ENCONTRADO!\n", id);
    }
}
 
 
void consulta_tempo (p_hash tabela) {
    long long id;
    scanf("%lld", &id);
    int f = funcao_hash(id);
 
    while (tabela->dados[f].ID != id) {
        f = (f+1) % MAX; // Percorre todo vetor, voltando pro inicio na última posição.
    }
    printf("TEMPO DO PROCESSO %lld: %d DIAS.\n", id, tabela->dados[f].tempo);
}