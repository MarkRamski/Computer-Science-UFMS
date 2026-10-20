/*
Marcos Henrique de Souza Almeida
202419040110
 */

#include "ordenacao.h"

int main() {
    int k, n;

    srand(time(NULL));

    printf("Digite a quantidade de casos de teste (k): ");
    scanf("%d", &k);

    for (int caso = 1; caso <= k; caso++) {
        printf("\n=-=-=-=-=-=-=-=-=-=- Caso %d/%d =-=-=-=-=-=-=-=-=-=\n", caso, k);
        printf("Digite o tamanho do vetor: ");
        scanf("%d", &n);

        int *vetor_original = (int *)malloc(n * sizeof(int));
        int *vetor_copia = (int *)malloc(n * sizeof(int));

        for (int i = 0; i < n; i++) {
            vetor_original[i] = rand();
        }

        clock_t inicio, fim;
        double tempo;

        printf("\nExecutando para N = %d (Decrescente):\n", n);

        // 1. Merge-Sort

        copiar_vetor(vetor_original, vetor_copia, n);
        inicio = clock();
        merge_sort(vetor_copia, 0, n - 1);
        fim = clock();
        tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
        printf("1. Merge-Sort:                  %.5f segundos\n", tempo);
        
        // 2. Quick-Sort
        copiar_vetor(vetor_original, vetor_copia, n);
        inicio = clock();
        quick_sort(vetor_copia, 0, n - 1);
        fim = clock();
        tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
        printf("2. Quick-Sort:                  %.5f segundos\n", tempo);

        // 3. Quick-Sort + Insertion-Sort
        copiar_vetor(vetor_original, vetor_copia, n);
        inicio = clock();
        quick_sort_insercao(vetor_copia, 0, n - 1);
        fim = clock();
        tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
        printf("3. Quick-Sort + Insertion-Sort: %.5f segundos\n", tempo);

        // 4. qsort (stdlib.h)
        copiar_vetor(vetor_original, vetor_copia, n);
        inicio = clock();
        usar_qsort(vetor_copia, n);
        fim = clock();
        tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
        printf("4. qsort (stdlib.h):            %.5f segundos\n", tempo);

        free(vetor_original);
        free(vetor_copia);
    }

    return 0;
}