#include <stdio.h>
#define MAX 100

float soma(int n, float v[MAX]) {
    if (n == 1) {
        return v[0];
    }
    else
        return soma(n - 1, v) + v[n - 1];
}

int main() {
    float vetor[MAX];
    int n;

    printf("Digite a quantidade de elementos: ");
    scanf("%d", &n);

    printf("Digite os %d elementos:\n", n);
    
    for (int i = 0; i < n; i++) {
        printf("Elemento [%d]: ", i);
        scanf("%f", & vetor[i]);
    }
    
    float resultado = soma(n, vetor);
    printf("A soma dos valores é: %.2f\n", resultado);

    return 0;
}