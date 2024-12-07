typedef struct matriz * p_matriz;

struct matriz {
    int ** dados;
    int qtd_linhas_usadas;
    int qtd_colunas_usadas;
    int qtd_linhas_alocadas;
    int qtd_colunas_alocadas;
};

typedef struct vetor * p_vetor;

struct vetor {
    int * dados;
    int n;
};

p_matriz aloca_matriz (int m, int n);

p_vetor le_linha (p_matriz mat);

p_vetor le_coluna (p_matriz mat);

void desaloca_vetor (p_vetor vet);

void le_matriz (p_matriz mat);

void desaloca_matriz (p_matriz mat);

void imprime_matriz (p_matriz mat);

void verifica_tamanho (p_matriz mat);

void insere_linha (p_matriz mat, p_vetor linha);

void remove_linha (p_matriz mat, int X);

void insere_coluna (p_matriz mat, p_vetor coluna);

void remove_coluna (p_matriz mat, int Y);
 
typedef struct matriz * p_matriz;
 
struct matriz {
    int ** dados;
    int qtd_linhas_usadas;
    int qtd_colunas_usadas;
    int qtd_linhas_alocadas;
    int qtd_colunas_alocadas;
};
 
typedef struct vetor * p_vetor;
 
struct vetor {
    int * dados;
    int n;
};
 
p_matriz aloca_matriz (int m, int n);
 
p_vetor le_linha (p_matriz mat);
 
p_vetor le_coluna (p_matriz mat);
 
void desaloca_vetor (p_vetor vet);
 
void le_matriz (p_matriz mat);
 
void desaloca_matriz (p_matriz mat);
 
void imprime_matriz (p_matriz mat);
 
void verifica_tamanho (p_matriz mat);
 
void insere_linha (p_matriz mat, p_vetor linha);
 
void remove_linha (p_matriz mat, int X);
 
void insere_coluna (p_matriz mat, p_vetor coluna);
 
void remove_coluna (p_matriz mat, int Y);