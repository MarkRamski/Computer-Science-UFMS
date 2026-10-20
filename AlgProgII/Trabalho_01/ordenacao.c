/*
Marcos Henrique de Souza Almeida
202419040110
*/

#include "ordenacao.h"

void trocar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// 1. MERGE-SORT (DECRESCENTE)
void intercalar(int vetor[], int inicio, int meio, int fim) {
    int i = inicio;
    int j = meio + 1;
    int k = 0;
    int tamanho = fim - inicio + 1;

    int *temp = (int *)malloc(tamanho * sizeof(int));

    while (i <= meio && j <= fim) {
        if (vetor[i] >= vetor[j]) { 
            temp[k] = vetor[i];
            i++;
        } else {
            temp[k] = vetor[j];
            j++;
        }
        k++;
    }

    while (i <= meio) {
        temp[k] = vetor[i];
        i++;
        k++;
    }

    while (j <= fim) {
        temp[k] = vetor[j];
        j++;
        k++;
    }

    for (i = 0; i < tamanho; i++) {
        vetor[inicio + i] = temp[i];
    }

    free(temp);
}

void merge_sort(int vetor[], int inicio, int fim) {
    if (inicio < fim) {
        int meio = (inicio + fim) / 2;
        merge_sort(vetor, inicio, meio);
        merge_sort(vetor, meio + 1, fim);
        intercalar(vetor, inicio, meio, fim);
    }
}

// 2. QUICK-SORT TRADICIONAL (DECRESCENTE)
int particionar(int vetor[], int inicio, int fim) {
    int pivo = vetor[fim]; 
    int i = inicio - 1;

    for (int j = inicio; j < fim; j++) {
        if (vetor[j] >= pivo) {
            i++;
            trocar(&vetor[i], &vetor[j]);
        }
    }
    trocar(&vetor[i + 1], &vetor[fim]);
    return i + 1;
}

void quick_sort(int vetor[], int inicio, int fim) {
    if (inicio < fim) {
        int pivo_pos = particionar(vetor, inicio, fim);
        quick_sort(vetor, inicio, pivo_pos - 1);
        quick_sort(vetor, pivo_pos + 1, fim);
    }
}

// 3. QUICK-SORT + INSERTION-SORT
void insertion_sort(int vetor[], int inicio, int fim) {
    for (int i = inicio + 1; i <= fim; i++) {
        int chave = vetor[i];
        int j = i - 1;
        while (j >= inicio && vetor[j] < chave) {
            vetor[j + 1] = vetor[j];
            j--;
        }
        vetor[j + 1] = chave;
    }
}

void quick_sort_insercao(int vetor[], int inicio, int fim) {
    if (inicio < fim) {
        if ((fim - inicio + 1) <= 15) {
            insertion_sort(vetor, inicio, fim);
        } else {
            int pivo_pos = particionar(vetor, inicio, fim);
            quick_sort_insercao(vetor, inicio, pivo_pos - 1);
            quick_sort_insercao(vetor, pivo_pos + 1, fim);
        }
    }
}

// 4. QSORT DA C STANDARD LIBRARY
int comparar_decrescente(const void *a, const void *b) {
    int valor_a = *(const int *)a;
    int valor_b = *(const int *)b;
    return valor_b - valor_a; 
}

void usar_qsort(int vetor[], int n) {
    qsort(vetor, n, sizeof(int), comparar_decrescente);
}

void copiar_vetor(int origem[], int destino[], int n) {
    for (int i = 0; i < n; i++) {
        destino[i] = origem[i];
    }
}

int esta_ordenado_decrescente(int vetor[], int n) {
    for (int i = 0; i < n - 1; i++) {
        if (vetor[i] < vetor[i + 1]) {
            return 0; 
        }
    }
    return 1;
}

void imprimir_vetor(int vetor[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}