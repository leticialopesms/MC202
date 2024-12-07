#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila.h"
 
p_fila cria_fila (int N) {
    p_fila f;
    f = malloc(sizeof(struct fila));
    f->v = malloc(N * sizeof(char));
    f->ini = 0;
    f->fim = 0;
    f->N = N;
    f->tamanho = 0;
    return f;
}
 
void enfileira (p_fila f, char x) {
    f->v[f->fim] = x;
    f->fim = (f->fim + 1) % f->N;
    f->tamanho++;
}
 
char desenfileira (p_fila f) {
    char x = f->v[f->ini];
    f->ini = (f->ini + 1) % f->N;
    f->tamanho--;
    return x;
}
 
void destroi_fila (p_fila fila) {
    free(fila->v);
    free(fila);
}