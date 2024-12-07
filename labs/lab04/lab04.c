#include <stdio.h>
#include <stdlib.h>
#define MENOR_SOMA -101
 
typedef struct vetor * p_vetor;
struct vetor {
    int *dados;
    int tamanho;
};
 
p_vetor le_vetor (int tamanho) {
    p_vetor vet = malloc(sizeof(struct vetor));
    vet->dados = malloc(tamanho * sizeof(int));
    vet->tamanho = tamanho;
    for (int i = 0; i < tamanho; i++)
        scanf("%d", &vet->dados[i]);
    return vet;
}
 
p_vetor cria_vetor(int tam) {
    p_vetor vet = malloc(sizeof(struct vetor));
    vet->dados = malloc(tam * sizeof(int));
    vet->tamanho = 0;
    return vet;
}
 
void destroi_vetor (p_vetor vet) {
    free(vet->dados);
    free(vet);
}
 
void copia_elementos(p_vetor v1, p_vetor v2) {
    // Adiciona os elemnentos de um vetor v1 para outro v2
    v2->dados = realloc(v2->dados, (v1->tamanho + v2->tamanho) * sizeof(int));
    for (int i = 0; i < v1->tamanho; i++) {
        v2->dados[v2->tamanho + i] = v1->dados[i];
    }
    v2->tamanho += v1->tamanho;
}
 
void remove_elemento (p_vetor vet, int inicio, int fim) {
    int posicao;
    int i = 0;
    for (posicao = inicio; posicao < vet->tamanho; posicao++) {
        vet->dados[i] = vet->dados[posicao];
        i++;
    }
    vet->tamanho = fim - inicio + 1;
}
 
void imprime_vetor (p_vetor vet) {
    for (int i = 0; i < vet->tamanho; i++) {
        printf("%d ", vet->dados[i]);
    }
    printf("\n");
}
 
void sub_tropa_forte (p_vetor vet) {
    int inicio = 0;
    int fim = vet->tamanho;
    int soma_atual = 0;
    int maior_soma = MENOR_SOMA;
    int i, j;
    for (i = 0; i < vet->tamanho; i++) {
        if (vet->dados[i] != 0) {
            for (j = i; j < vet->tamanho; j++) {
                soma_atual = soma_atual + vet->dados[j];
                if (soma_atual > maior_soma) {
                    maior_soma = soma_atual;
                    inicio = i;
                    fim = j;
                }
            }
            soma_atual = 0;
        }
    }
    remove_elemento(vet, inicio, fim);
    // printf("Maior soma = %d, início = %d, fim = %d\n", maior_soma, inicio, fim);
}
 
void sub_tropa_elite (p_vetor vet) {
    int i, soma = 0, media;
    for (i = 0; i < vet->tamanho; i++) {
        soma += vet->dados[i];
    }
    media = soma/vet->tamanho;
    for (i = 0; i < vet->tamanho; i++) {
        vet->dados[i] -= media;
    }
    // printf("media = %d", media);
    sub_tropa_forte(vet);
    for (i = 0; i < vet->tamanho; i++) {
        vet->dados[i] += media;
    }
}
 
int main () {
    int Q;              // Qtde de tropas
    scanf("%d", &Q);
    p_vetor tropa_elite = cria_vetor(1);
    for (int i = 0; i < Q; i++) {
        int N_i;        // Tamanho da tropa i
        scanf("%d", &N_i);
        p_vetor tropa_i = le_vetor(N_i);
        sub_tropa_forte(tropa_i);
        printf("Sub-tropa Forte %d: ", i+1);
        imprime_vetor(tropa_i);
        copia_elementos(tropa_i, tropa_elite);
        destroi_vetor(tropa_i);
    }
    sub_tropa_elite(tropa_elite);
    printf("Sub-tropa Elite: ");
    imprime_vetor(tropa_elite);
    destroi_vetor(tropa_elite);
    return 0;
}