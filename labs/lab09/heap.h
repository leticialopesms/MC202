typedef struct {
    int dado;   // P - Número Identificador do Processo
    int chave;  // C - Código de Prioridade do Processo
} Item;

typedef struct {
    Item *v;     // vetor de Itens alocado dinamicamente;
    int n;       // Qtde de elementos
    int tamanho; // Qtde Alocada
} FP; // Fila de Prioridade

typedef FP * p_fp;



void troca (Item *a, Item *b);

p_fp cria_fp (int tam);

Item cria_item (int valor, int chave);

void sobe_no_heap (p_fp fila_prio, int k);

void insere_item_no_heap (p_fp fila_prio, Item item);

void desce_no_heap(p_fp fila_prio, int k);

Item extrai_maximo_no_heap (p_fp fila_prio);

void muda_prioridade (p_fp fila_prio, int k, int valor);

int verifica_posicao (p_fp fila_prio, int P);

void remove_processos (p_fp fila_prio, int K);

void desaloca_heap (p_fp fila_prio);
typedef struct {
    int dado;   // P - Número Identificador do Processo
    int chave;  // C - Código de Prioridade do Processo
} Item;
 
typedef struct {
    Item *v;     // vetor de Itens alocado dinamicamente;
    int n;       // Qtde de elementos
    int tamanho; // Qtde Alocada
} FP; // Fila de Prioridade
 
typedef FP * p_fp;
 
 
 
void troca (Item *a, Item *b);
 
p_fp cria_fp (int tam);
 
Item cria_item (int valor, int chave);
 
void sobe_no_heap (p_fp fila_prio, int k);
 
void insere_item_no_heap (p_fp fila_prio, Item item);
 
void desce_no_heap(p_fp fila_prio, int k);
 
Item extrai_maximo_no_heap (p_fp fila_prio);
 
void muda_prioridade (p_fp fila_prio, int k, int valor);
 
int verifica_posicao (p_fp fila_prio, int P);
 
void remove_processos (p_fp fila_prio, int K);
 
void desaloca_heap (p_fp fila_prio);