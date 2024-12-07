#include <stdio.h>
#define MAX 1000
 
void le_vetor(int vetor[], int tamanho_vetor) {
    // Lê um vetor a partir de um input do usuário.
    for (int i = 0; i < tamanho_vetor; i++)
        scanf("%d", &vetor[i]);
}
 
 
void conjunto_banner(int vetor[], int tamanho_vetor) {
    // Operação que verifica se cada elemento de um dado vetor
    // está contido no vetor_banner, alterando seu valor para
    // zero caso não esteja.
    int B, vetor_banner[MAX];
    scanf("%d", &B);
    le_vetor(vetor_banner, B);
 
    int i, j, vetor_atual;
    for (i = 0; i < tamanho_vetor; i++) {
        j = 0;
        vetor_atual = vetor[i];
        while (vetor_atual != vetor_banner[j] && j < B) {
            vetor[i] = 0;
            j++;
        }
        if (j == B) {
            vetor[i] = 0;
        }else if (vetor_atual == vetor_banner[j]) {
            vetor[i] = vetor_atual;
        }  
    }
}
 
 
void multiplicacao_mobius(int vetor[], int tamanho_vetor) {
    // Multiplica por M cada elemento que esteja 
    // em uma posição ímpar de um dado vetor.
    int M;
    scanf("%d", &M);
    int i;
    for (i = 1; i < tamanho_vetor; i = i + 2) {
        vetor[i] *= M;
    }
}
 
 
void movimento_ciclico(int vetor[], int tamanho_vetor) {
    // Transpõe o valor da última posição para a posição zero,
    // movendo todos os outros valores para a posição seguinte 
    // à dele. Faz isso P vezes.
    int P, i, j, k, aux[MAX];
    scanf("%d", &P);
    for (i = 0; i < P; i++) {
        aux[0] = vetor[tamanho_vetor - 1];
        for (j = 1; j < tamanho_vetor; j++) {
            aux[j] = vetor[j - 1];
        }
        for (k = 0; k < tamanho_vetor; k++) {
            vetor[k] = aux[k];
        }
    }
}
 
 
void inversao_vetor(int vetor[], int tamanho_vetor) {
    // Inverte os elementos de um ado vetor.
    int i, troca;
    for (i = 0; i < tamanho_vetor / 2; i++) {
        troca = vetor[i];
        vetor[i] = vetor[tamanho_vetor - 1 - i];
        vetor[tamanho_vetor - 1 - i] = troca;
    }
}
 
 
void imprime_vetor(int vetor[], int n) {
    // Imprime os valores do vetor.
    for (int i = 0; i < n; i++)
        printf("%d ", vetor[i]);
    printf("\n");
}
 
 
int main() {
    int n, operacao, T, u[MAX];
    scanf("%d", &T);
    le_vetor(u, T);
 
    scanf("%d", &n);
 
    int i;
    for (i = 0; i < n ; i++) {
        scanf("%d", &operacao);
        if (operacao == 1) {
            conjunto_banner(u, T);
        } else if (operacao == 2) {
            multiplicacao_mobius(u, T);
        } else if (operacao == 3) {
            movimento_ciclico(u, T);
        } else if (operacao == 4) {
            inversao_vetor(u, T);
        }
        imprime_vetor(u, T);
    }
    return 0;
}