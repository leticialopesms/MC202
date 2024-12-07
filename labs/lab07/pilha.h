#define MAX 1000
#define POSICOES 50
 
typedef struct no *p_no;
struct no {
    char dado[POSICOES + 1];    // String
    p_no prox;                  // Próxima camada da pilha
    int n;                      // Qtde preenchida
};
 
typedef struct pilha *p_pilha;
struct pilha {
    p_no topo;
};
 
 
p_no cria_lista ();
 
p_pilha cria_pilha ();
 
void empilha (p_pilha pilha);
 
void desempilha (p_pilha pilha);
 
void destroi_pilha (p_pilha pilha);