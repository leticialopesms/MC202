#define MAX 1000
#define POSICOES 50
 
typedef struct fila *p_fila;
struct fila {
    char *v;
    int ini, fim;
    int N;          // Qtde alocada
    int tamanho;    // Qtde utilizada
};
 
 
p_fila cria_fila (int N);
 
void enfileira (p_fila f, char x);
 
char desenfileira (p_fila f);
 
void destroi_fila (p_fila fila);