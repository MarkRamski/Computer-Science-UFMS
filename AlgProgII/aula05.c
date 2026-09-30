#include <stdio.h>
int main(void) {
    int i, j;
    
    float soma_c8, soma_l3, B[5][10];
    
    for (i = 0; i < 5; i++)
        for (j = 0; j < 10; j++) {
            printf("Informe B[%d][%d]: ", i, j);
            scanf("%f", B[i][j]);
        }
    
        soma_c8 = 0.0;

        for (i = 0; i < 4; i++)
            soma_c8 = soma_c8 + B[i][7];
        
        printf("Valor da soma da oitava coluna é %f\n", soma_c8);
        soma_l3 = 0.0;

        for (j = 0; j < 10; j++)
            soma_l3 = soma_l3 + B[2][j];

    printf("Valor da soma da terceira linha é %f\n", soma_l3);

    return 0;
}