#define MAX 1001

typedef struct {
    char nome[MAX];
    float nivel_max;
    int qtd_medidas;
    int medidas[MAX];
    int media;
} Represa;

Represa le_dados();

int verifica_capacidade(Represa r);

void imprime_dados(Represa r);

Represa padroniza_nome(Represa r);

Represa remove_prefixo(Represa r);

Represa remove_num(Represa r);

Represa adiciona_espaco(Represa r);

Represa retira_maiusculas(Represa r);
#define MAX 1001
 
typedef struct {
    char nome[MAX];
    float nivel_max;
    int qtd_medidas;
    int medidas[MAX];
    int media;
} Represa;
 
Represa le_dados();
 
int verifica_capacidade(Represa r);
 
void imprime_dados(Represa r);
 
Represa padroniza_nome(Represa r);
 
Represa remove_prefixo(Represa r);
 
Represa remove_num(Represa r);
 
Represa adiciona_espaco(Represa r);
 
Represa retira_maiusculas(Represa r);