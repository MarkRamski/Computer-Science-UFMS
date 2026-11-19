/******
Marcos Henrique de Souza Almeida
202419040110
Professor (a): Marco Aurélio Stefanes
******/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct No {
    int digito;
    struct No *ant;
    struct No *prox;
} No;

typedef struct {
    No *inicio; 
    No *fim;    
    int tamanho;
} BigInt;

BigInt *criar_bigint(void) {
    BigInt *num;

    num = (BigInt *) malloc(sizeof(BigInt));

    if (num == NULL) {
        exit(EXIT_FAILURE);
    }

    num -> inicio = NULL;
    num -> fim = NULL;
    num -> tamanho = 0;

    return num;
}


void liberar_bigint(BigInt *num) {
    No *atual;
    No *proximo;

    if (num == NULL) {
        return;
    }

    atual = num -> inicio;

    while (atual != NULL) {
        proximo = atual -> prox;
        free(atual);
        atual = proximo;
    }

    free(num);
}

void inserir_inicio(BigInt *num, int digito) {
    No *novo;

    novo = (No *) malloc(sizeof(No));

    if (novo == NULL) {
        exit(EXIT_FAILURE);
    }

    novo -> digito = digito;
    novo -> ant = NULL;
    novo -> prox = num -> inicio;

    if (num -> inicio != NULL) {
        num -> inicio -> ant = novo;
    } else {
        num -> fim = novo;
    }

    num -> inicio = novo;
    num -> tamanho++;
}

void inserir_fim(BigInt *num, int digito) {
    No *novo;

    novo = (No *) malloc(sizeof(No));

    if (novo == NULL) {
        exit(EXIT_FAILURE);
    }

    novo -> digito = digito;
    novo -> prox = NULL;
    novo -> ant = num -> fim;

    if (num -> fim != NULL) {
        num -> fim -> prox = novo;
    } else {
        num -> inicio = novo;
    }

    num -> fim = novo;
    num -> tamanho++;
}

/* Remove zeros a esquerda */ 
void remover_zeros_esquerda(BigInt *num) {
    No *temp;

    while (num -> fim != NULL && num -> fim != num -> inicio &&
           num -> fim -> digito == 0) {
        temp = num -> fim;
        num -> fim = num -> fim -> ant;
        num -> fim -> prox = NULL;
        free(temp);
        num -> tamanho--;
    }
}

BigInt *ler_bigint(void) {
    BigInt *num;
    int ch;

    num = criar_bigint();

    while ((ch = getchar()) != EOF && isspace(ch)) {
    }

    while (ch != EOF && isdigit(ch)) {
        inserir_inicio(num, ch - '0');
        ch = getchar();
    }

    if (num -> tamanho == 0) {
        inserir_fim(num, 0);
    } else {
        remover_zeros_esquerda(num);
    }

    return num;
}

/* Imprime o numero do digito mais significativo ao menos significativo */
void imprimir_bigint(const BigInt *num) {
    No *atual;

    if (num == NULL || num -> fim == NULL) {
        printf("0\n");
        return;
    }

    atual = num -> fim;

    while (atual != NULL) {
        printf("%d", atual -> digito);
        atual = atual -> ant;
    }
    printf("\n");
}

int comparar_bigint(const BigInt *a, const BigInt *b) {
    No *pa;
    No *pb;

    if (a -> tamanho > b -> tamanho) {
        return 1;
    }
    if (a -> tamanho < b -> tamanho) {
        return -1;
    }

    pa = a -> fim;
    pb = b -> fim;
    while (pa != NULL && pb != NULL) {
        if (pa -> digito > pb -> digito) {
            return 1;
        }
        if (pa -> digito < pb -> digito) {
            return -1;
        }
        pa = pa -> ant;
        pb = pb -> ant;
    }

    return 0;
}

/* Realiza a adicao: a + b */
BigInt *somar_bigint(const BigInt *a, const BigInt *b) {
    BigInt *res;
    No *pa;
    No *pb;
    int vai_um;
    int soma;

    res = criar_bigint();
    pa = a -> inicio;
    pb = b -> inicio;
    vai_um = 0;

    while (pa != NULL || pb != NULL || vai_um > 0) {
        soma = vai_um;

        if (pa != NULL) {
            soma += pa -> digito;
            pa = pa -> prox;
        }

        if (pb != NULL) {
            soma += pb -> digito;
            pb = pb -> prox;
        }

        inserir_fim(res, soma % 10);
        vai_um = soma / 10;
    }

    remover_zeros_esquerda(res);
    return res;
}

/* Realiza a subtracao: a - b (assumindo a >= b) */
BigInt *subtrair_bigint(const BigInt *a, const BigInt *b) {
    BigInt *res;
    No *pa;
    No *pb;
    int empresta;
    int diff;

    res = criar_bigint();
    pa = a -> inicio;
    pb = b -> inicio;
    empresta = 0;

    while (pa != NULL) {
        diff = pa -> digito - empresta;

        if (pb != NULL) {
            diff -= pb -> digito;
            pb = pb -> prox;
        }

        if (diff < 0) {
            diff += 10;
            empresta = 1;
        } else {
            empresta = 0;
        }

        inserir_fim(res, diff);
        pa = pa->prox;
    }

    remover_zeros_esquerda(res);
    return res;
}

/* Realiza a multiplicacao: a * b */
BigInt *multiplicar_bigint(const BigInt *a, const BigInt *b) {
    BigInt *total;
    BigInt *parcial;
    BigInt *novo_total;
    No *pa;
    No *pb;
    int deslocamento;
    int i;
    int vai_um;
    int prod;

    total = criar_bigint();
    inserir_fim(total, 0);

    pb = b -> inicio;
    deslocamento = 0;

    while (pb != NULL) {
        parcial = criar_bigint();

        for (i = 0; i < deslocamento; i++) {
            inserir_fim(parcial, 0);
        }

        pa = a -> inicio;
        vai_um = 0;
        while (pa != NULL || vai_um > 0) {
            prod = vai_um;

            if (pa != NULL) {
                prod += pa -> digito * pb -> digito;
                pa = pa -> prox;
            }

            inserir_fim(parcial, prod % 10);
            vai_um = prod / 10;
        }

        novo_total = somar_bigint(total, parcial);
        liberar_bigint(total);
        liberar_bigint(parcial);
        total = novo_total;

        deslocamento++;
        pb = pb -> prox;
    }

    remover_zeros_esquerda(total);
    return total;
}

/* Realiza a divisao inteira: a / b (assumindo a >= b e b > 0) */
BigInt *dividir_bigint(const BigInt *a, const BigInt *b) {
    BigInt *quociente;
    BigInt *resto;
    BigInt *novo_resto;
    No *pa;
    int q_dig;

    quociente = criar_bigint();
    resto = criar_bigint();
    inserir_fim(resto, 0);

    pa = a -> fim;

    while (pa != NULL) {
        inserir_inicio(resto, pa -> digito);
        remover_zeros_esquerda(resto);

        q_dig = 0;

        while (comparar_bigint(resto, b) >= 0) {
            novo_resto = subtrair_bigint(resto, b);
            liberar_bigint(resto);
            resto = novo_resto;
            q_dig++;
        }

        inserir_inicio(quociente, q_dig);
        pa = pa -> ant;
    }

    if (quociente -> tamanho == 0) {
        inserir_fim(quociente, 0);
    } else {
        remover_zeros_esquerda(quociente);
    }

    liberar_bigint(resto);
    return quociente;
}

int main(void) {
    int n;
    int i;
    char operador;
    BigInt *op1;
    BigInt *op2;
    BigInt *resultado;

    if (scanf("%d", &n) != 1) {
        return 0;
    }

    for (i = 0; i < n; i++) {
        op1 = ler_bigint();
        op2 = ler_bigint();

        if (scanf(" %c", &operador) != 1) {
            liberar_bigint(op1);
            liberar_bigint(op2);
            break;
        }

        resultado = NULL;

        if (operador == '+') {
            resultado = somar_bigint(op1, op2);

        } else if (operador == '-') {
            resultado = subtrair_bigint(op1, op2);

        } else if (operador == '*') {
            resultado = multiplicar_bigint(op1, op2);
            
        } else if (operador == '/') {
            resultado = dividir_bigint(op1, op2);
        }

        if (resultado != NULL) {
            imprimir_bigint(resultado);
            liberar_bigint(resultado);
        }

        liberar_bigint(op1);
        liberar_bigint(op2);
    }

    return 0;
}