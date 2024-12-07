# include <stdio.h>
# include <stdlib.h>
# define PAI(i) ((i-1)/2)
# define F_ESQ(i) (2*i+1) // Filho esquerdo de i
# define F_DIR(i) (2*i+2) // Filho direito de i
# include "heap.h"
 
 
void troca (Item *a, Item *b) {
    Item t = *a;
    *a = *b;
    *b = t;
}
 
p_fp cria_fp (int tam) {
    p_fp fila_prio = malloc(sizeof(FP));
    fila_prio->v = malloc(tam*sizeof(Item));
    fila_prio->n = 0;
    fila_prio->tamanho = tam;
    return fila_prio;
}
 
Item cria_item (int valor, int chave) {
    Item item;
    item.dado = valor;
    item.chave = chave;
    return item;
}
 
void sobe_no_heap (p_fp fila_prio, int k) {
    while (k > 0) {
        if (k > 0 && fila_prio->v[PAI(k)].chave > fila_prio->v[k].chave) {
            troca(&fila_prio->v[k], &fila_prio->v[PAI(k)]);
        }
        else if (k > 0 && fila_prio->v[PAI(k)].chave == fila_prio->v[k].chave) {
            if (fila_prio->v[PAI(k)].dado < fila_prio->v[k].dado) {
                troca(&fila_prio->v[k], &fila_prio->v[PAI(k)]);
            }
        }
        k = PAI(k);
    }
}
 
void insere_item_no_heap (p_fp fila_prio, Item item) {
    fila_prio->v[fila_prio->n] = item;
    fila_prio->n++;
    sobe_no_heap(fila_prio, fila_prio->n - 1);
}
 
void desce_no_heap (p_fp fila_prio, int k) {
    int menor_filho;
    if (F_ESQ(k) < fila_prio->n) {
        menor_filho = F_ESQ(k);
        if (F_DIR(k) < fila_prio->n && fila_prio->v[F_ESQ(k)].chave > fila_prio->v[F_DIR(k)].chave)
            menor_filho = F_DIR(k);
        else if (F_DIR(k) < fila_prio->n && fila_prio->v[F_ESQ(k)].chave == fila_prio->v[F_DIR(k)].chave) {
            if (fila_prio->v[F_ESQ(k)].dado < fila_prio->v[F_DIR(k)].dado) {
                menor_filho = F_DIR(k);
            }
        }
        if (fila_prio->v[k].chave > fila_prio->v[menor_filho].chave) {
            troca(&fila_prio->v[k], &fila_prio->v[menor_filho]);
            desce_no_heap(fila_prio, menor_filho);
        }
        else if (fila_prio->v[k].chave == fila_prio->v[menor_filho].chave) {
            if (fila_prio->v[k].dado < fila_prio->v[menor_filho].dado) {
                troca(&fila_prio->v[k], &fila_prio->v[menor_filho]);
                desce_no_heap(fila_prio, menor_filho);
            }
        }
    }
}
 
Item extrai_maximo_no_heap (p_fp fila_prio) {
    Item item = fila_prio->v[0];
    troca(&fila_prio->v[0], &fila_prio->v[fila_prio->n - 1]);
    fila_prio->n--;
    desce_no_heap(fila_prio, 0);
    return item;
}
 
void muda_prioridade (p_fp fila_prio, int k, int valor) {
    if (fila_prio->v[k].chave > valor) {
        fila_prio->v[k].chave = valor;
        sobe_no_heap(fila_prio, k);
    } else {
        fila_prio->v[k].chave = valor;
        desce_no_heap(fila_prio, k);
    }
}
 
int verifica_posicao (p_fp fila_prio, int P) {
    int i = 0;
    while (fila_prio->v[i].dado != P) {
        i++;
    }
    return i;
}
 
void remove_processos (p_fp fila_prio, int K) {
    // Remove os K processos mais prioritários
    Item processo;
    printf("PROCESSOS REMOVIDOS:");
    for (int j = 0; j < K; j++) {
        processo = extrai_maximo_no_heap(fila_prio);
        printf(" %d", processo.dado);
    }
    printf("\n");
}
 
void desaloca_heap (p_fp fila_prio) {
    free(fila_prio->v);
    free(fila_prio);
}