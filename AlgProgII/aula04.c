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
*/

#include <stdio.h>

int main(void) {
    
    return 0;
}