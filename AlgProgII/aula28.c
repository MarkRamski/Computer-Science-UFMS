#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int chave;
    struct celula *prox;
} celula;

//Busca seguida Remoção:
void busca_remove(int x, celula *lst) {
    celula *p, *q;

    p = lst;
    q = lst -> prox;
    
    while (q != NULL && q -> chave != x) {
        p = q;
        q = q -> prox;
    }

    if (q != NULL) {
        p -> prox = q -> prox;
        free(q);
    }
}

//Busca seguida Inserção
void busca_insere(int y, int x, celula *lst) {
    celula *p, *q, *nova;
    
    nova = (celula *) malloc(sizeof (celula));
    nova -> chave = y;

    p = lst;
    q = lst -> prox;

    while (q != NULL && q -> chave != x) {
        p = q;
        q = q -> prox;
    }

    nova -> prox = q;
    p -> prox = nova;
}

int main(void) {
    return 0;
}
