#include <stdio.h>
#include <string.h>
#define MAX 100 
 
 
void cria_matriz(int M[][MAX], int dimensao) {
    // Tarefa a)
    // Lê as matrizes dadas na entrada.
    int i, j = 0, valor, contador = 0;
    
    for (i = 0; i < dimensao; i++) {
        contador += 1;
        for (j = 0; j < dimensao; j++) {
            if (j % 3 == 0)
                contador += 1;
            if (contador % 2 == 0)
                valor = 1;
            else
                valor = 0;
            M[i][j] = valor;
        }
    }
}
 
 
void imprime_matriz(int M[][MAX], int dimensao) {
    // Imprime uma dada matriz M quadrada na forma convencional.
    int i, j;
    printf("\n");
    for (i = 0; i < dimensao; i++) {
        for (j = 0; j < dimensao; j++)
            printf("%d ", M[i][j]);
        printf("\n");
    }
}
 
 
void TRANSPOSTA(int X[][MAX], int Y[][MAX], int aux[][MAX], int dimensao) {
    // Tarefa b)
    // Dada uma matriz X, ela é transposta e guardada na matriz Y.
    int i, j;
    for (i = 0; i < dimensao; i++)
        for (j = 0; j < dimensao; j++)
            aux[j][i] = X[i][j];
 
    for (i = 0; i < dimensao; i++) 
        for (j = 0; j < dimensao; j++) 
            Y[i][j] = aux[i][j]; 
 
    imprime_matriz(Y, dimensao);
}
 
 
void SOMA(int X[][MAX], int Y[][MAX], int Z[][MAX], int dimensao) {
    // Tarefa c)
    // Faz a soma de elemento a elemento entre duas matrizes X e Y.
    // A matriz resultante é guardada em Z.
    int i, j;
    for (i = 0; i < dimensao; i++)
        for (j = 0; j < dimensao; j++) {
            if (X[i][j] == 0 && Y[i][j] == 0)
                Z[i][j] = 0;
            else
                Z[i][j] = 1;
        }
 
    imprime_matriz(Z, dimensao);
}
 
 
void MULTI_ELEM(int X[][MAX], int Y[][MAX], int Z[][MAX], int dimensao) {
    // Tarefa d)
    // Multiplica elemento a elemento de duas matrizes quadradas X e Y.
    // A matriz resultante é guardada em Z.
    int i, j;
    for (i = 0; i < dimensao; i++)
        for (j = 0; j < dimensao; j++) {
            if (X[i][j] == 1 &&  Y[i][j] == 1)
                Z[i][j] = 1;
            else
                Z[i][j] = 0;
        }
 
    imprime_matriz(Z, dimensao);
}
 
 
void MULTI_MAT(int X[][MAX], int Y[][MAX], int Z[][MAX], int aux[][MAX], int dimensao) {
    // Tarefa e)
    // Multiplica duas matrizes quadradas X e Y.
    // A matriz resultante é guardada em Z.
    int i, j, k;
    for (i = 0; i < dimensao; i++)
        for (j = 0; j < dimensao; j++) {
            aux[i][j] = 0;
            for (k = 0; k < dimensao; k++)
                if (X[i][k] * Y[k][j] != 0)
                    aux [i][j] = 1;
        }
 
    for (i = 0; i < dimensao; i++)
        for (j = 0; j < dimensao; j++)
            Z[i][j] = aux[i][j];
 
    imprime_matriz(Z, dimensao);
}
 
 
void BORDAS(int X[][MAX], int Y[][MAX], int aux[][MAX], int dimensao) {
    // Tarefa f)
    // Define as bordas de X e guarda em Y.
    int i, j;
    for (i = 0; i < dimensao; i++)
        for (j = 0; j < dimensao; j++)
            aux[i][j] = X[i][j];
 
    for (i = 1; i < dimensao - 1; i++)
        for (j = 1; j < dimensao - 1; j++)
            if (X[i - 1][j - 1] == 1)
                if (X[i - 1][j] == 1)
                    if (X[i - 1][j + 1] == 1)
                        if (X[i][j + 1] == 1)
                            if (X[i + 1][j + 1] == 1)
                                if (X[i + 1][j] == 1)
                                    if (X[i + 1][j - 1] == 1)
                                        if (X[i][j - 1] == 1)
                                            aux[i][j] = 0;
    for (i = 0; i < dimensao; i++)
        for (j = 0; j < dimensao; j++)
            Y[i][j] = aux[i][j];
    
    imprime_matriz(Y, dimensao);
}
 
 
int main() {
    int N, O, A[MAX][MAX], B[MAX][MAX], i, aux[MAX][MAX];
    
    scanf("%d", &N);
    scanf("%d", &O);
    cria_matriz(A, N);
    cria_matriz(B, N);
 
    char operacao[MAX], X, Y, Z;
    for (i = 0; i < O; i++) {
        scanf("%s ", operacao);
 
        if (strcmp(operacao, "TRANSPOSTA") == 0) {
            scanf("%c %c", &X, &Y);
            if (X == 'A' && Y == 'A') 
                TRANSPOSTA(A, A, aux, N); 
            else if (X == 'A' && Y == 'B') 
                TRANSPOSTA(A, B, aux, N); 
            else if (X == 'B' && Y == 'A') 
                TRANSPOSTA(B, A, aux, N); 
            else if (X == 'B' && Y == 'B') 
                TRANSPOSTA(B, B, aux, N); 
        }
        if (strcmp(operacao, "SOMA") == 0) {
            scanf("%c %c %c", &X, &Y, &Z);
            if (X == 'A' && Y == 'A' && Z == 'A') 
                SOMA(A, A, A, N); 
            else if (X == 'A' && Y == 'A' && Z == 'B') 
                SOMA(A, A, B, N); 
            else if (X == 'A' && Y == 'B' && Z == 'B') 
                SOMA(A, B, B, N); 
            else if (X == 'B' && Y == 'B' && Z == 'B') 
                SOMA(B, B, B, N); 
            else if (X == 'B' && Y == 'B' && Z == 'A') 
                SOMA(B, B, A, N); 
            else if (X == 'B' && Y == 'A' && Z == 'A') 
                SOMA(B, A, A, N); 
            else if (X == 'B' && Y == 'A' && Z == 'B') 
                SOMA(B, A, B, N); 
            else if (X == 'A' && Y == 'B' && Z == 'A') 
                SOMA(A, B, A, N); 
        }
        if (strcmp(operacao, "MULTI_ELEM") == 0) {
            scanf("%c %c %c", &X, &Y, &Z);
            if (X == 'A' && Y == 'A' && Z == 'A') 
                MULTI_ELEM(A, A, A, N); 
            else if (X == 'A' && Y == 'A' && Z == 'B') 
                MULTI_ELEM(A, A, B, N); 
            else if (X == 'A' && Y == 'B' && Z == 'B') 
                MULTI_ELEM(A, B, B, N); 
            else if (X == 'B' && Y == 'B' && Z == 'B') 
                MULTI_ELEM(B, B, B, N); 
            else if (X == 'B' && Y == 'B' && Z == 'A') 
                MULTI_ELEM(B, B, A, N); 
            else if (X == 'B' && Y == 'A' && Z == 'A') 
                MULTI_ELEM(B, A, A, N); 
            else if (X == 'B' && Y == 'A' && Z == 'B') 
                MULTI_ELEM(B, A, B, N); 
            else if (X == 'A' && Y == 'B' && Z == 'A') 
                MULTI_ELEM(A, B, A, N); 
        }
        if (strcmp(operacao, "MULTI_MAT") == 0) {
            scanf("%c %c %c", &X, &Y, &Z);
            if (X == 'A' && Y == 'A' && Z == 'A') 
                MULTI_MAT(A, A, A, aux, N); 
            else if (X == 'A' && Y == 'A' && Z == 'B') 
                MULTI_MAT(A, A, B, aux, N); 
            else if (X == 'A' && Y == 'B' && Z == 'B') 
                MULTI_MAT(A, B, B, aux, N); 
            else if (X == 'B' && Y == 'B' && Z == 'B') 
                MULTI_MAT(B, B, B, aux, N); 
            else if (X == 'B' && Y == 'B' && Z == 'A') 
                MULTI_MAT(B, B, A, aux, N); 
            else if (X == 'B' && Y == 'A' && Z == 'A') 
                MULTI_MAT(B, A, A, aux, N); 
            else if (X == 'B' && Y == 'A' && Z == 'B') 
                MULTI_MAT(B, A, B, aux, N); 
            else if (X == 'A' && Y == 'B' && Z == 'A') 
                MULTI_MAT(A, B, A, aux, N); 
        }
        if (strcmp(operacao, "BORDAS") == 0) {
            scanf("%c %c", &X, &Y);
            if (X == 'A' && Y == 'A') 
                BORDAS(A, A, aux, N); 
            else if (X == 'A' && Y == 'B') 
                BORDAS(A, B, aux, N); 
            else if (X == 'B' && Y == 'A') 
                BORDAS(B, A, aux, N); 
            else if (X == 'B' && Y == 'B') 
                BORDAS(B, B, aux, N); 
        }
    }
    printf("\n");
    return 0;
}