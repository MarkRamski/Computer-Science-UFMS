/*
//Exercício 1

#include <stdio.h>

#define MAX 100

void min_max(int n, int v[MAX], int *max, int *min) {
    *max = v[0];
    *min = v[0];

    for (int i = 0; i < n; i++) {
        
        if (v[i] > *max) {
            *max = v[i];
        }

        if (v[i] < *min) {
            *min = v[i];
        }
    }
}

int main(void) {
    int n, v[MAX], max, min;

    printf("Digite o N: ");
    scanf("%d", &n);

    printf("Escreva os %d elementos:\n", n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }

    min_max(n, v, &max, &min);

    printf("Maior = %d, Menor = %d", max, min);
}
*/

// Exercicio 2

#include <stdio.h>

#define MAX 100

void dois_maiores(int n, int v[MAX], int *pr, int *seg) {
    *pr = v[0];
    *seg = v[0];

    if (v[i])


    for (int i = 0; i < n; i++) {

        if (v[i] > *pr) {
            *seg = *pr;
       
    }
}