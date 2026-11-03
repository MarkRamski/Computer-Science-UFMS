/*
EXERCICIO 1

#include <stdio.h>

int main(void) {
    
    struct {
        int dia;
        int mes;
        int ano;
    } data, proximo;

    printf("Informe uma data (dd/mm/aaaa): ");
    scanf("%d/%d/%d", &data.dia, &data.mes, &data.ano);

    proximo = data;
    proximo.dia += 1;

    if (proximo.dia > 31 
        || proximo.dia == 31 
            && (proximo.mes == 4 || proximo.mes == 6 
            || proximo.mes == 9 || proximo.mes == 11)
        || (proximo.dia == 30 && proximo.mes == 2)
        || (proximo.dia == 29 && proximo.mes == 2
            && (proximo.ano % 400 != 0
            && (proximo.ano % 100 == 0 || proximo.ano % 4 != 0)))) {

                proximo.dia = 1;
                proximo.mes += 1;

                if (proximo.mes > 12) {
                    proximo.mes = 1;
                    proximo.ano += 1;
                }
        }
    
    printf("%02d/%02d/02%d\n", proximo.dia, proximo.mes, proximo.ano);

    return 0;
}

---------------------------------------------------

EXERCICIO 2

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    
    struct horario {
        int hora;
        int minuto;
        int segundo;
    } prim_hora, seg_hora, diferenca;


    printf("Digite o primeiro horário (hh:mm:ss): ");
    scanf("%d:%d:%d", &prim_hora.hora, &prim_hora.minuto, &prim_hora.segundo);

    printf("Digite a segunda hora no mesmo dia (hh:mm:ss): ");
    scanf("%d:%d:%d", &seg_hora.hora, &seg_hora.minuto, &seg_hora.segundo);

    int total_seg1 = prim_hora.hora * 3600 + prim_hora.minuto * 60 + prim_hora.segundo;
    int total_seg2 = seg_hora.hora * 3600 + seg_hora.minuto * 60 + seg_hora.segundo;

    int diff_seg = total_seg2 - total_seg1;

    if (diff_seg < 0) {
        diff_seg = -diff_seg;
    }

    diferenca.hora = diff_seg / 3600;
    diferenca.minuto = (diff_seg % 3600) / 60;
    diferenca.segundo = diff_seg % 60;


    printf("Diferença dos dois horários: %02d:%02d:%02d\n", diferenca.hora, diferenca.minuto, diferenca.segundo);

    return 0;
}

-------------------------------------------

EXERCICIO 3

#include <stdio.h>
#include <stdlib.h>

struct data {
        int dia;
        int mes;
        int ano;
    } data1, data2;

int f(int ano, int mes) {
    if (mes <= 2) {
        return ano - 1;
    }
    return ano;
}

int g(int mes) {
    if (mes <= 2) {
        return mes + 13;
    }
    else {
        return mes + 1;
        }
    }

int calcular_N(struct data d) {
    int f_valor = f(d.ano, d.mes);
    int g_valor = g(d.mes);
    return (1461 * f_valor) / 4 + (153 * g_valor) / 5 + d.dia;
}

int main(void) {
        printf("Digite a primeira data (dd/mm/aaaa): ");
    scanf("%d/%d/%d", &data1.dia, &data1. mes, &data1.ano);

    printf("Digite a segunda data (dd/mm/aaaa): ");
    scanf("%d/%d/%d", &data2.dia, &data2.mes, &data2.ano);

    int n1 = calcular_N(data1);
    int n2 = calcular_N(data2);

    int diferenca = abs(n2 - n1);

    printf("Número de dias de diferença: %d\n", diferenca);

    return 0;
}

--------------------------------------

EXERCICIO 4

*/
#include <stdio.h>

struct data {
    int dia;
    int mes;
    int ano;
} data1;

int f(int ano, int mes) {
    if (mes <= 2) {
        return ano -1;
    }
    return ano;
}

int g(int mes) {
    if (mes <= 2) {
        return mes + 13;
    }
    return mes + 1;
}

int calcular_N(struct data d) {
    int f_valor = f(d.ano, d.mes);
    int g_valor = g(d.mes);
    return ((1461 * f_valor) / 4) + ((153 * g_valor) / 5) + d.dia; 
}

int main(void) {
    printf("Digite a data (dd/mm/aaaa): ");
    scanf("%d/%d/%d", &data1.dia, &data1.mes, &data1.ano);

    int n = calcular_N(data1);

    int D = (n - 621049) % 7;

    char dias_semana[7][20] = {
        "Domingo",
        "Segunda-feira",
        "Terça-feira",
        "Quarta-feira",
        "Quinta-feira",
        "Sexta-feira",
        "Sábado"
    };

    printf("O dia da semana é: %s\n", dias_semana[D]);

    return 0;
}


