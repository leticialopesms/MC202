#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila.h"
#include "pilha.h"
 
void le_string (char leitura[]) {
    fgets(leitura, MAX, stdin);
    if (leitura[strlen(leitura) - 1] == '\n')
        leitura[strlen(leitura) - 1] = '\0';
}
 
int converte_string (char string[], int inicio) {
    char aux[MAX];
    int i;
    for (i = 0; string[inicio + i] != '\0'; i++) {
        aux[i] = string[inicio + i];
    }
    aux[i] = '\0';
    // Função que converte uma string em um inteiro
    return atoi(aux);
}
 
void remove_caracteres_pilha (p_pilha p, int x) {
    while (x > p->topo->n) {
        x = x - p->topo->n;
        desempilha(p);
    }
    for (int i = 0; i < x; i++) {
        p->topo->dado[p->topo->n - 1] = '\0';
        p->topo->n--;
    }
}
 
void preenche_pilha (p_pilha p, p_fila f, int x) {
    while (x != 0) {
        if (p->topo->n == POSICOES) {
            empilha(p);
            p->topo->n = 0;
        }
        p->topo->dado[p->topo->n] = desenfileira(f);
        p->topo->n++;
        x--;
    }
}
 
void imprime_string (char string[], int inicio) {
    int i;
    for (i = inicio; string[i] != '\0'; i++) {
        printf("%c", string[i]);
    }
}
 
void imprime_fila (p_fila f) {
    imprime_string(f->v, f->ini);
    printf("\n");
}
 
void imprime_lista (p_no lista) {
    if (lista != NULL) {
        imprime_lista(lista->prox);
        imprime_string(lista->dado, 0);
    }
}
 
void imprime_pilha (p_pilha p) {
    imprime_lista(p->topo);
    printf("\n");
}
 
//-------------------------------------------------------------
 
int main () {
    char leitura[MAX];
    p_fila fila_str = cria_fila(MAX);
    p_pilha pilha_str = cria_pilha();
    int N, M;
    le_string(leitura);
    char * eh_operacao_EXEC;
    char * eh_operacao_DEL;
 
    while (strstr(leitura, "EXIT") == NULL) {
        eh_operacao_EXEC = strstr(leitura, "EXEC");
        eh_operacao_DEL = strstr(leitura, "DEL");
 
        if (eh_operacao_EXEC != NULL) {
            N = converte_string(leitura, 5);
            preenche_pilha(pilha_str, fila_str, N);
        }
        
        else if (eh_operacao_DEL != NULL) {
            M = converte_string(leitura, 4);
            remove_caracteres_pilha(pilha_str, M);
        }
        else {
            int tamanho = strlen(leitura);
            for (int i = 0; i < tamanho; i++) {
                enfileira(fila_str, leitura[i]);
            }
        }
        printf("FILA ATUAL: ");
        imprime_fila(fila_str);
        printf("PILHA ATUAL: ");
        imprime_pilha(pilha_str);
        printf("####\n");
        le_string(leitura);
    }
 
    destroi_fila(fila_str);
    destroi_pilha(pilha_str);
    return 0;
}