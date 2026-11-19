#include <stdio.h>
#define DIM 100

int soma_matriz(int n, const int A[DIM][DIM]) {
    const int *p = &A[0][0];
    int soma = 0;

    for (int i = 0; i < n * n; i++) {
        soma += *p;
        p++;
    }
    return soma;
}