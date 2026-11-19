#include <stdio.h>
#include <stdlib.h>

struct cel {
    int chave;
    struct cel *prox;
};
typedef struct cel celula;

celula *cria_lista(void) {
    celula *lst = (celula *) malloc(sizeof(celula));
    lst->prox = NULL;
    return lst;
}

void imprime_lista(celula *lst) {
    for (celula *p = lst->prox; p != NULL; p = p->prox)
        printf("%d ", p->chave);
    printf("\n");
}

celula *busca_ordenada(int x, celula *lst) {
    celula *p = lst->prox;
    while (p != NULL && p->chave < x)
        p = p->prox;
    return (p != NULL && p->chave == x) ? p : NULL;
}

void insere_ordenado(int y, celula *lst) {
    celula *p = lst, *q = lst->prox;
    while (q != NULL && q->chave < y) {
        p = q;
        q = q->prox;
    }
    celula *nova = (celula *) malloc(sizeof(celula));
    nova->chave = y;
    nova->prox = q;
    p->prox = nova;
}

void remove_ordenado(int x, celula *lst) {
    celula *p = lst, *q = lst->prox;
    while (q != NULL && q->chave < x) {
        p = q;
        q = q->prox;
    }
    if (q != NULL && q->chave == x) {
        p->prox = q->prox;
        free(q);
    }
}

celula *merge_listas(celula *lst1, celula *lst2) {
    celula *res = cria_lista();
    celula *fim = res;
    celula *p1 = lst1->prox, *p2 = lst2->prox;

    while (p1 != NULL && p2 != NULL) {
        celula *nova = (celula *) malloc(sizeof(celula));
        if (p1->chave <= p2->chave) {
            nova->chave = p1->chave;
            p1 = p1->prox;
        } else {
            nova->chave = p2->chave;
            p2 = p2->prox;
        }
        nova->prox = NULL;
        fim->prox = nova;
        fim = nova;
    }

    celula *resto = (p1 != NULL) ? p1 : p2;
    while (resto != NULL) {
        celula *nova = (celula *) malloc(sizeof(celula));
        nova->chave = resto->chave;
        nova->prox = NULL;
        fim->prox = nova;
        fim = nova;
        resto = resto->prox;
    }

    return res;
}

int main(void) {
    celula *lista1 = cria_lista();
    celula *lista2 = cria_lista();

    insere_ordenado(2, lista1);
    insere_ordenado(6, lista1);
    insere_ordenado(10, lista1);
    insere_ordenado(18, lista1);

    insere_ordenado(1, lista2);
    insere_ordenado(6, lista2);
    insere_ordenado(12, lista2);
    insere_ordenado(15, lista2);
    insere_ordenado(25, lista2);

    imprime_lista(lista1);
    imprime_lista(lista2);

    celula *lista_merged = merge_listas(lista1, lista2);
    imprime_lista(lista_merged);

    celula *achou = busca_ordenada(12, lista_merged);
    printf("%d\n", achou->chave);

    insere_ordenado(8, lista_merged);
    imprime_lista(lista_merged);

    remove_ordenado(10, lista_merged);
    imprime_lista(lista_merged);

    return 0;
}