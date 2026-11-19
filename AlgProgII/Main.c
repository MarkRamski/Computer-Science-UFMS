#include <stdio.h>
#include <stdlib.h>

struct cel {
    int chave;
    struct cel *prox;
};

typedef struct cel celula;

 celula *cria_lista(void) {
    celula *lst = (celula *) malloc(sizeof(celula));
    lst -> prox = NULL;
    return lst;
 }

 void imprime_lista(celula *lst) {

    for (celula *p = lst -> prox; p != NULL; p = p -> prox)
        printf("%d", p-> chave);
    
 }