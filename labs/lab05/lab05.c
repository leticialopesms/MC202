#include <stdio.h>
#include "ultron.h"
#define MAX 7
 
 
int main() {
 
    int qtd_i_inicial, qtd_j_inicial, qtd_operacoes;
    // qtd_i_inicial indica a quantidade de linhas da matriz original.
    // qtd_j_inicial indica a quantidade de colunas da matriz original.
 
    scanf("%d %d", &qtd_i_inicial, &qtd_j_inicial);
 
    p_matriz ultron = aloca_matriz(qtd_i_inicial, qtd_j_inicial);
    le_matriz(ultron);
 
    scanf("%d", &qtd_operacoes);
    
    int i;
    for (i = 0; i < qtd_operacoes; i++) {
        verifica_tamanho(ultron);
        
        char operacao[MAX], orientacao;
        scanf("%s ", operacao);
        scanf("%c ", &orientacao);
        fflush(stdout);
        
        if (operacao[0] == 'I') {
            if (orientacao == 'L') {
                p_vetor linha;
                linha = le_linha(ultron);
                insere_linha(ultron, linha);
                desaloca_vetor(linha);
            }
            else if (orientacao == 'C') {
                p_vetor coluna;
                coluna = le_coluna(ultron);
                insere_coluna(ultron, coluna);
                desaloca_vetor(coluna);
            }
        }
        else if (operacao[0] == 'O') {
            if (orientacao == 'L') {
                int X;
                scanf("%d", &X);
                remove_linha(ultron, X);
            }
            else if (orientacao == 'C') {
                int Y;
                scanf("%d", &Y);
                remove_coluna(ultron, Y);
            }
        }
        imprime_matriz(ultron);
    }
    desaloca_matriz(ultron);
 
    printf("COMBINACAO MATRICIAL FINALIZADA!\n");
    return 0;
}