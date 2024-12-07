#define STR 100
#define MAX 2000
 
typedef struct Processo {
    long long int ID;   // Identificador do processo
    char nome[STR];     // Nome do arquivo do processo
    int tempo;          // Tempo pelo qual o processo espera para ser atendido (em dias)
} Processo;
 
typedef struct Hash * p_hash;
struct Hash {
    Processo dados[MAX];   // Dados do Processo
};
 
 
p_hash aloca_hash ();
 
int funcao_hash (long long identificador);
 
void insere_hash (p_hash tabela, Processo arquivo);
 
void remove_hash (p_hash tabela);
 
void consulta_nome (p_hash tabela);
 
void consulta_tempo (p_hash tabela);