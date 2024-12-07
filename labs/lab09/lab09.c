# include <stdio.h>
# include <stdlib.h>
# include "heap.h"
 
int main () {
    int T; // Qtde da lista de pares
    scanf("%d", &T);
 
    p_fp fila_processos = cria_fp(T);
 
    for (int i = 0; i < T; i++) {
        int P;  // Número Identificador do Processo
        int C;  // Código de Prioridade do Processo
        scanf("%d %d", &P, &C);
        Item processo = cria_item(P, C);
        insere_item_no_heap(fila_processos, processo);
    }
 
    int Q;  // Qtde de comandos
    scanf("%d", &Q);
    
    for (int i = 0; i < Q; i++) {
        char comando;
        scanf(" %c", &comando);
        if (comando == 'M') {
            int P, C;
            scanf("%d %d", &P, &C);
            int posicao_processo_atual = verifica_posicao(fila_processos, P);
            muda_prioridade(fila_processos, posicao_processo_atual, C);
        }
        else if (comando == 'R') {
            int K;  // K processos mais prioritários
            scanf("%d", &K);
            remove_processos(fila_processos, K);
        }
    }
    printf("FINALIZADO!\n");
    desaloca_heap(fila_processos);
    return 0;
}