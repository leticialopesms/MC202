#include <stdio.h>
#include <stdlib.h>
#include "hash.h"
 
int main() {
    int N;
    scanf("%d", &N);
 
    p_hash tabela = aloca_hash();
 
    // Leitura
    for (int i = 0; i < N; i++) {
        Processo atual;
        char operacao;
        scanf(" %c ", &operacao);
        if (operacao == 'I') {
            scanf("%lld ", &atual.ID);
            scanf("%s ", atual.nome);
            scanf("%d", &atual.tempo);
            insere_hash(tabela, atual);
        }
        else if (operacao == 'R') {
            remove_hash(tabela);
        }
        else if (operacao == 'C') {
            consulta_nome(tabela);
        }
        else if (operacao == 'T') {
            consulta_tempo(tabela);
        }
 
    }
    free(tabela);
    printf("FINALIZADO!");
    return 0;
}