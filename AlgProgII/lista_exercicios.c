/*
EXERCICIO 4.3

#include <stdio.h>

struct Data {
    int dia;
    int mes;
    int ano;
};

int calcular_n(struct Data d) {
    int f_ano_mes;
    int g_mes;

    if (d.mes <= 2) {
        f_ano_mes = d.ano - 1;
        g_mes = d.mes + 13;

    } else {
        f_ano_mes = d.ano;
        g_mes = d.mes + 1;
    }

    int N = ((1461 * f_ano_mes) / 4) + ((153 * g_mes) / 5) + d.dia;

    return N;
}

int main() {
    struct Data d1, d2;

    printf("Digite a primeira data (dd mm aaaa): ");
    scanf("%d %d %d", &d1.dia, &d1.mes, &d1.ano);

    printf("Digite a segunda data (dd mm aaaa): ");
    scanf("%d %d %d", &d2.dia, &d2.mes, &d2.ano);

    int N1 = calcular_n(d1);
    int N2 = calcular_n(d2);

    int diferenca = N2 - N1;

    if (diferenca < 0) {
        diferenca = -diferenca;
    }

    printf("\nN1 = %d\n", N1);
    printf("N2 = %d\n", N2);
    printf("Dias de diferença entre as datas: %d\n", diferenca);

    return 0;
}
-----------------------
EXERCICIO 5.4

#include <stdio.h>

#define TAM 10

struct Material {
    int codigo;
    char descricao[21];
    float quantidade;
};

int main() {
    struct Material galpao[TAM][TAM];

    int codigos_unicos[100];
    float soma_quantidade[100] = {0};
    int total_unicos = 0;

    printf("CADASTRO DOS MATERIAIS\n");

    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("\nPosição [%d][%d]:", i, j);

            printf("Codigo: ");
            scanf("%d", &galpao[i][j].codigo);

            printf("Descrição: ");
            scanf(" %s", galpao[i][j].descricao);

            printf("Quantidade: ");
            scanf("%f", &galpao[i][j].quantidade);

        }
    }
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            int cod = galpao[i][j].codigo;
            int encontrado = -1;

            for (int k = 0; k < total_unicos; k++) {
                if (codigos_unicos[k] == cod) {
                    encontrado = k;
                    break;
                }
            }
        
            if (encontrado != -1) {
                soma_quantidade[encontrado] += galpao[i][j].quantidade;
            
            } else {
                codigos_unicos[total_unicos] = cod;
                soma_quantidade[total_unicos] = galpao[i][j].quantidade;
                total_unicos++;
            }
        }
    }
    printf("\nQUANTIDADE TOTAL POR MATERIAL");

    for (int k = 0; k < total_unicos; k++) {
        printf("Codigo: %d | Quantidade Total: %.2f\n",
            codigos_unicos[k], soma_quantidade[k]);
    }

    return 0;
}
--------------------
EXERCICIO 6.4

#include <stdio.h>
#include <string.h>

#define MAX 100

struct torneio {
    char nome[50];
    int pontos;
};

void ordena(struct torneio equipe[MAX], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {

            int trocar = 0;

            if (equipe[j].pontos < equipe[j + 1].pontos) {
                trocar = 1;
            }
            else if (equipe[j].pontos == equipe[j + 1].pontos) {
                if (strcmp(equipe[j].nome, equipe[j + 1].nome) > 0) {
                    trocar = 1;
                }
            }
            if (trocar) {
                struct torneio aux = equipe[j];
                equipe[j] = equipe[j + 1];
                equipe[j + 1] = aux;
            }
        }
    }
}

int main() {
    struct torneio equipe[MAX];
    int n;

    printf("Digite o número de equipes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("\nEQUIPE %d:\n", i + 1);

        printf("Nome: ");
        scanf("%s", equipe[i].nome);

        printf("Pontos: ");
        scanf("%d", &equipe[i].pontos);
    }

    ordena(equipe, n);

    printf("\nRESULTADO DO TORNEIO\n");
    
    for (int i = 0; i < n; i++) {
        printf("%dº Lugar: %s | %d pontos\n", i + 1, equipe[i].nome, equipe[i]. pontos);
    }
    return 0;
}
-----------------
EXERCICIO 7.8
#include <stdio.h>

//Letra (a)
int ciclo(int n) {
    int contador = 1;

    while (n != 1) {
        printf("%d ", n);
        
        if (n % 2 == 0) {
            n = n / 2;

        } else {
            n = 3 * n + 1;
        }
        contador++;
    }
    
    printf("1\n");
    return contador;
}

// Letra (b)
int cicloR(int n) {
    printf("%d ", n);

    if (n == 1) {
        printf("\n");
        return 1;
    }

    if (n % 2 == 0) {
        return 1 + cicloR(n / 2);

    } else {
        return 1 + cicloR(3 * n + 1);
    }
}

// Letra (c)
int main() {
    int n;

    printf("Digite um numero inteiro positivo: ");
    scanf("%d", &n);

    if (n < 1) {
        printf("Por favor, digite um numero valido (n >= 1).\n");
        return 1;


    printf("\nFunção Não-Recursiva\n");
    printf("Sequencia: ");

    int comp1 = ciclo(n);

    printf("Comprimento do ciclo: %d\n", comp1);

    printf("\nFunção Recursiva\n");
    printf("Sequencia: ");

    int comp2 = cicloR(n);
    
    printf("Comprimento do ciclo: %d\n", comp2);

    return 0;
}
-----------------
EXERCICIO 7.9
*/
#include <stdio.h>

int potencia(int x, int n) {
    if (n == 0) {
        return 1;
    }
    
    if (n % 2 == 0) {
        int metade = potencia(x, n / 2);
        return metade * metade;
    } 

    else {
        return x * potencia(x, n - 1);
    }
}

int main() {
    int a, b;

    printf("Digite a base (a): ");
    scanf("%d", &a);

    printf("Digite o expoente (b >= 0): ");
    scanf("%d", &b);

    if (b < 0) {
        printf("O expoente deve ser um inteiro não- negativo.\n");
        return 1;
    }

    int resultado = potencia(a, b);

    printf("\n%d^%d = %d\n", a, b, resultado);

    return 0;
}

