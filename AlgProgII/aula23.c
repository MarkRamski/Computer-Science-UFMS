#include <stdio.h>

void matriz_identidade(int n, int *p) {

    int *inicio = p;
    int *fim = p + n *n;

    for (; p < fim; p++) {

        if ((p - inicio) % (n + 1) == 0) {
            *p = 1;
        } 
        else {
            *p = 0;
        }
    }
}

int main(void) {
    int n;

    printf("Digite o N: ");
    scanf("%d", &n);
    
    int matriz[n][n];

    matriz_identidade(n, (int *)matriz);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}