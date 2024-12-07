#include <stdio.h>
#include "represa.h"
 
int main() {
    int T;
    scanf("%d", &T);
    Represa rep;
    for (int i = 0; i < T; i++) {
        rep = le_dados();
        imprime_dados(rep);
    }
    return 0;
}