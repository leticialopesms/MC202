typedef struct {
    int linha;
    int coluna;
} posicao;
 
 
typedef struct no * p_no;
struct no {
    p_no ant;
    p_no prox;
    posicao dados;
};
 
 
typedef struct matriz * p_matriz;
struct matriz {
    int ** dados;
    int M;   // Qtde Linhas
    int N;   // Qtde Colunas
};
 
 
// Lista duplamente ligada
 
p_no inicializa_no (posicao pos);
 
p_no insere_novo_no (p_no cabeca, posicao pos);
 
void remove_no (p_no no);
 
void destroi_lista (p_no lista);
 
 
// Matriz
 
p_matriz aloca_matriz (int m, int n);
 
void preenche_matriz_inicial (p_matriz mat, posicao cobra, posicao fruta);
 
void destroi_matriz (p_matriz mat);
 
void imprime_matriz (p_matriz mat);
 
 
// JOGO
 
posicao verifica_nova_posicao(p_matriz mat, p_no cabeca, char operacao);
 
int GAME_OVER (p_matriz mat, posicao nova_pos);
 
int YOU_WIN (p_matriz mat, int tamanho);
 
int pegou_fruta (posicao nova_pos, posicao fruta);
 
p_no move_cobra(p_matriz mat, p_no cabeca, posicao fruta, posicao nova_pos, int * tamanho_cobra);