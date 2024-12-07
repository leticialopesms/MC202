#include <stdio.h>
#include <stdlib.h>
#include "cobra.h"
 
int main () {
    p_no cobra;
    p_matriz tabuleiro;
    posicao fruta;
    char lixo[10];
    int M, N, a, b, tamanho_cobra;
 
    // Lê as entradas iniciais.
    scanf("%d %d", &M, &N);
    scanf("%s %d %d", lixo, &fruta.linha, &fruta.coluna);
    scanf("%s %d %d", lixo, &a, &b);
 
    // Inicializa a cobra (lista ligada).
    posicao cabeca;
    cabeca.linha = a;
    cabeca.coluna = b;
    cobra = inicializa_no(cabeca);
    tamanho_cobra = 1;
 
    // Inicializa o tabuleiro (matriz).
    tabuleiro = aloca_matriz(M, N);
    preenche_matriz_inicial(tabuleiro, cabeca, fruta);
    imprime_matriz(tabuleiro);
 
    char operacao;
    posicao nova_pos;
    int you_win, game_over;
 
    do {
        scanf(" %c", &operacao);
        nova_pos = verifica_nova_posicao(tabuleiro, cobra, operacao);
        game_over = GAME_OVER(tabuleiro, nova_pos);
 
        if (game_over == 1) {
            // Se a cobra não mover para posição inválida...
            cobra = move_cobra(tabuleiro, cobra, fruta, nova_pos, &tamanho_cobra);
            cabeca = cobra->dados;
            you_win = YOU_WIN(tabuleiro, tamanho_cobra);
            imprime_matriz(tabuleiro);
 
            if (pegou_fruta(cabeca, fruta) == 0 && YOU_WIN(tabuleiro, tamanho_cobra) == 1) {
                // Se a cobra pegou a fruta...
                scanf("%s %d %d", lixo, &fruta.linha, &fruta.coluna);
                tabuleiro->dados[fruta.linha][fruta.coluna] = -1;
                imprime_matriz(tabuleiro);
            }
        } else imprime_matriz(tabuleiro);
    } while (you_win == 1 && game_over == 1);
 
    if (you_win == 0) {
        printf("YOU WIN\n");
    }
    else {
        printf("GAME OVER\n");
    }
 
    destroi_matriz(tabuleiro);
    destroi_lista(cobra);
    return 0;
}