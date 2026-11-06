/*
PRIMEIRO EXEMPLO

#include <stdio.h>
void troca(int *a, int *b) {
    int aux;
    
    aux = *a;
    *a = *b;
    *b = aux;
}

int main(void) {
    int x, y;
    
    scanf("%d%d", &x, &y);
    printf("Antes da troca : x = %d e y = %d\n", x, y);
    
    troca(&x, &y);
    
    printf("Depois da troca: x = %d e y = %d\n", x, y);
    
    return 0;
}
-------------------------------------
EXERCICIO 1
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
    int n;
    int v[MAX];
    int maior = 0, menor = 0;

    printf("Digite um número inteiro N: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }

    min_max(n, v, &maior, &menor);

    printf("\nO maior número do vetor: %d", maior);
    printf("\nO menor número do vetor: %d\n", menor);

    return 0;
}
---------------------------------
EXERCICIO 2

#include  <stdio.h>

#define MAX 100

void dois_maiores(int n, int v[MAX], int *pr, int *seg) {
    *pr = v[0];
    *seg = v[0];

    if (v[0] > v[1]) {
        *pr = v[0];
        *seg = v[1];
    } 
    else {
        *pr = v[1];
        *seg = v[0];
    }

    for (int i = 2; i < n; i++) {
        if (v[i] > *pr) {
            *seg = *pr;
            *pr = v[i];
        }
        else if (v[i] > *seg) {
            *seg = v[i];
        }
    }
}

int main(void) {
    int n;
    int v[MAX];
    int primeiro = 0; 
    int segundo = 0;

    printf("Digite N: ");
    scanf("%d", &n);

    printf("Digite os %d valores: ", n);

    for (int i = 0; i < n; i++) {
        scanf("%d", v[i]);
    }

    dois_maiores(n, v, &primeiro, &segundo);

    printf("\nO primeiro maior: %d\n", primeiro);
    printf("O segundo maior: %d\n", segundo);

    return 0;
}
-----------------------------
EXERCICIO 3
#include <stdio.h>

void soma_prod(int a, int b, int *soma, int *prod) {
    *soma = a + b;
    *prod = a * b;
}

int main(void) {
    int a;
    int b;
    int somatorio;
    int produto;

    printf("Digite a: ");
    scanf("%d", &a);

    printf("Digite b: ");
    scanf("%d", &b);

    soma_prod(a, b, &somatorio, &produto);

    printf("\nA soma dos dois valores é: %d\n", somatorio);
    printf("O produto dos dois valores é: %d\n", produto);

    return 0;
}
------------------------------------------------
EXERCICIO 4
*/
#include <stdio.h>

#define MAX 100

int *maximo(int n, int v[MAX]) {
    int pos_max = 0;

    for (int i = 0; i < n; i++) {

        if (v[i] > v[pos_max]) {
            pos_max = i;
        }
    }
    return &v[pos_max];
}

int main(void) {
    int n;
    int v[MAX];

    printf("Digite N: ");
    scanf("%d", &n);

    printf("Digite os valores: ");

    for(int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }

    int *endereco = maximo(n, v);

    printf("\nO endereço do maior elemento é: %d\n", &endereco);

    return 0;
}

