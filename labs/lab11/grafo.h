typedef struct no *p_no;
struct no {
    int v;
    p_no prox;
};

typedef struct grafo *p_grafo;
struct grafo {
    p_no *adjacencia;   // Lista de adjacência
    int n;              // Tamanho do grafo
};

typedef struct fila * p_fila;
struct fila {
    p_no ini;
    p_no fim;
};

//-------------------------------------------------------------------
// Lista Ligada

p_no insere_na_lista (p_no lista, int v);

p_no remove_da_lista (p_no lista, int v);

void libera_lista (p_no lista);

//-------------------------------------------------------------------
// Grafo

p_grafo cria_grafo(int tam);

void libera_grafo(p_grafo g) ;

void insere_aresta (p_grafo g, int u, int v);

void remove_aresta (p_grafo g, int u, int v);

int tem_aresta (p_grafo g, int u, int v);

//-------------------------------------------------------------------
// Fila

p_fila cria_fila ();

void libera_fila (p_fila f);

void enfileira(p_fila f, int x);

int desenfileira(p_fila f);

//-------------------------------------------------------------------
// Operações

void insertionsort (int v[], int n);

int * busca_em_largura(p_grafo g, int s);

int consulta_menor_distancia (p_grafo g, int no_origem, int no_fim);

void adiciona_vertice (p_grafo g, int no_novo, int no);
typedef struct no *p_no;
struct no {
    int v;
    p_no prox;
};
 
typedef struct grafo *p_grafo;
struct grafo {
    p_no *adjacencia;   // Lista de adjacência
    int n;              // Tamanho do grafo
};
 
typedef struct fila * p_fila;
struct fila {
    p_no ini;
    p_no fim;
};
 
//-------------------------------------------------------------------
// Lista Ligada
 
p_no insere_na_lista (p_no lista, int v);
 
p_no remove_da_lista (p_no lista, int v);
 
void libera_lista (p_no lista);
 
//-------------------------------------------------------------------
// Grafo
 
p_grafo cria_grafo(int tam);
 
void libera_grafo(p_grafo g) ;
 
void insere_aresta (p_grafo g, int u, int v);
 
void remove_aresta (p_grafo g, int u, int v);
 
int tem_aresta (p_grafo g, int u, int v);
 
//-------------------------------------------------------------------
// Fila
 
p_fila cria_fila ();
 
void libera_fila (p_fila f);
 
void enfileira(p_fila f, int x);
 
int desenfileira(p_fila f);
 
//-------------------------------------------------------------------
// Operações
 
void insertionsort (int v[], int n);
 
int * busca_em_largura(p_grafo g, int s);
 
int consulta_menor_distancia (p_grafo g, int no_origem, int no_fim);
 
void adiciona_vertice (p_grafo g, int no_novo, int no);