#include <stdio.h>
#define MAX 100

void troca(int *a, int *b) {
    int aux = *a;
    *a = *b;
    *b = aux;
}

/*ordenação decrescente usando o Método de Bolha*/
void bubble_sort(int n, int v[MAX]) {
    int i, j;

    for (i = n - 1; i > 0; i--) 

        for (j = 0; j < i; j++)

            if (v[j] < v[j + 1])
                troca(&v[j], &v[j + 1]);       
}

/*ordenação decrescente usando o Método de Inserção*/
void insertion_sort(int n, int v[MAX]) {
    int i, j, x;

    for(i = 1; i < n; i++) {
        x = v[i];

        for (j = i - 1; j >= 0 && v[j] < x; j--)
            v[j + 1] = v[j];
        
        v[j + 1] = x;
    }
}

/*ordenação decrescente usando o Método de Seleção*/
void selection_sort(int n, int v[MAX]) {
    int i, j, max;

    for (i = 0; i < n - 1; i++) {
        max = i;

        for (j= i + 1; j < n; j++) {

            if (v[j] > v[max])
                max = j;
            
            troca(&v[i], &v[max]);
        }
    }
}

int main() {
    int n, metodo, v[MAX];
    
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);

    printf("Digite os %d elementos:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);    
    }

    printf("Digite o Método Desejado [1] Bolha | [2] Inserção | [3] Seleção: ");
    scanf("%d", &metodo);

    if (metodo == 1) {
        bubble_sort(n, v);
    }
    else if (metodo == 2) {
        insertion_sort(n, v);
    }
    else if (metodo == 3) {
        selection_sort(n, v);
    }

    printf("\nVetor ordenado em Ordem Decrescente:\n");

    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    
    printf("\n");
    return 0;
}