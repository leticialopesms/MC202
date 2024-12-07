#include <stdio.h>
#include "represa.h"
 
 
Represa le_dados() {
    Represa r;
    scanf("%s", r.nome);
    scanf("%f", &r.nivel_max);
    scanf("%d", &r.qtd_medidas);
    int i, soma = 0;;
    for (i = 0; i < r.qtd_medidas; i++){
        scanf("%d", &r.medidas[i]);
        soma += r.medidas[i];
    }
    r.media = soma / r.qtd_medidas;
    return r;
}
 
 
int verifica_capacidade(Represa r) {
    int i;
    for (i = 0; i < r.qtd_medidas; i++)
        if (r.medidas[i] >= 0.9 * (r.nivel_max))
            return 1;
    return 0;
}
 
 
void imprime_dados(Represa r) {
    r = padroniza_nome(r);
    printf("NOME: %s\n", r.nome);
    printf("QTD NIVEIS: %d\n", r.qtd_medidas);
    printf("MEDIA: %d\n", r.media);
    if (verifica_capacidade(r) == 1)
        printf("CAPACIDADE ACIMA DE %d%c DA MAXIMA!\n", 90, '%');
    printf("#####\n");
}
 
int calcula_tamanho_str (char str[]) {
    int i = 0;
    while(str[i] != '\0') {
        i++;
    }
    return i;
}
 
Represa padroniza_nome(Represa r) {
    r = remove_prefixo(r);
    r = remove_num(r);
    r = adiciona_espaco(r);
    r = retira_maiusculas(r);
    return r;
}
 
int tem_prefixo(char str[], int tamanho) {
    char referencia[] = "represa_de_";
    int i;
    for (i = 0; i < 11; i++) {
        if (str[i] != referencia[i]) {
            return 0;
        }
    }
    return 1;
}
 
Represa remove_prefixo(Represa r) {
    int tamanho_nome = calcula_tamanho_str(r.nome);
    int i, j = 0;
    if (tem_prefixo(r.nome, tamanho_nome) == 1) {
        int fim_do_pref = 11;
        for (i = fim_do_pref; i <= tamanho_nome; i++) {
            r.nome[j] = r.nome[i];
            j++;
        }
    }
    return r;
}
 
Represa remove_num(Represa r) {
    int tamanho_nome = calcula_tamanho_str(r.nome);
    int i = tamanho_nome - 1;
    while (r.nome[i] >= 48 && r.nome[i] <= 57) {
    // while (sizeof((int)r.nome[i]) == sizeof(int)) {
        r.nome[i] = '\0';
        i--;
    }
    return r;
}
 
Represa adiciona_espaco(Represa r) {
    int tamanho_nome = calcula_tamanho_str(r.nome);
    int i;
    for (i = 0; i < tamanho_nome; i++)
        if (r.nome[i] == '_')
            r.nome[i] = ' ';
    return r;
}
 
Represa retira_maiusculas(Represa r) {
    int tamanho_nome = calcula_tamanho_str(r.nome);
    int i;
    for (i = 0; i < tamanho_nome; i++) {
        if (r.nome[i] >= 65 && r.nome[i] <= 90) {
            r.nome[i] = r.nome[i] + 32;
        }
    }
    return r;
}