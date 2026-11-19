/*
PRIMEIRO EXEMPLO
#include <stdio.h>

struct data {
    int dia;
    int mes;
    int ano;
};
int main(void) {
    struct data hoje, *p;
    
    p = &hoje;
    p->dia = 24;
    p->mes = 10;
    p->ano = 2018;
    
    printf("Data de hoje: %d/%d/%d\n", hoje.dia, hoje.mes, hoje.ano);
    
    return 0;
}
*/
#include <stdio.h>
struct pts_int {
    int *pt1;
    int *pt2;
};

int main(void) {
    int i1, i2;
    struct pts_int reg;
    
    i2 = 100;
    reg.pt1 = &i1;
    reg.pt2 = &i2;
    *reg.pt1 = -2;
    
    printf("i1 = %d, *reg.pt1 = %d\n", i1, *reg.pt1);
    printf("i2 = %d, *reg.pt2 = %d\n", i2, *reg.pt2);
    
    return 0;
}