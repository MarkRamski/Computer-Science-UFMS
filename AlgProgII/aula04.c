/*
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
    struct {
        int horas;
        int minutos;
        int segundos;
    } first_hor, second_hor, diferenca;

    printf("Digite o primeiro horario (hh:mm:ss): ");
    scanf("%d:%d:%d", &first_hor.horas, first_hor.minutos, first_hor.segundos);

    printf("Digite a segunda hora (hh:mm:ss): ");
    scanf("%d:%d:%d", second_hor.horas, second_hor.minutos, second_hor.segundos);

    if (first_hor.horas < second_hor.horas) {
        diferenca.horas = second_hor.horas - first_hor.horas;
        
        if (first_hor.minutos )
    }


    return 0;
}