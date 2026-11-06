// Declaração de uma VARIÁVEL PONTEIRO:
// int *p;

// Uma fora de inicializar o ponteiro é dar o edendereço de uma variavel
// int i, *p;
// p = &i;

// ou dessa forma:
// int i, *p = &i;

// imprimindo o valor de i de forma indireta por ponteiro:
// printf("%d", *p);

/*
PRIMEIRO EXEMPLO

#include <stdio.h>

int main(void) {
    char c, *p;
    p = &c;
    c = 'a';
    
    // Endereço de c; conteúdo de c
    printf("&c = %p c = %c\n", &c, c);
    // Endereço da variável ponteiro; Endereço de c por ponteiro; Conteúdo do ponteiro
    printf("&p = %p p = %p *p = %c\n\n", &p, p, *p);
    
    c = '/';

    // Endereço de c; conteúdo de c
    printf("&c = %p c = %c\n", &c, c);
    // Endereço da variável ponteiro; Endereço de c por ponteiro; Conteúdo do ponteiro
    printf("&p = %p p = %p *p = %c\n\n", &p, p, *p);
    
    *p = 'Z';
    
    // Endereço de c; conteúdo de c
    printf("&c = %p c = %c\n", &c, c);
    // Endereço da variável ponteiro; Endereço de c por ponteiro; Conteúdo do ponteiro
    printf("&p = %p p = %p *p = %c\n\n", &p, p, *p);
    
    return 0;
}
------------------------------------
SEGUNDO EXEMPLO

#include <stdio.h>
int main(void) {
    int i, j, *p1, *p2;
    p1 = &i;

    i = 5;
    j = 2 * *p1 + 3;

    p2 = p1;
    
    printf("i = %d, &i = %p\n\n", i, &i);
    printf("j = %d, &j = %p\n\n", j, &j);

    printf("&p1 = %p, p1 = %p, *p1 = %d\n", &p1, p1, *p1);
    printf("&p2 = %p, p2 = %p, *p2 = %d\n\n", &p2, p2, *p2);
    
    return 0;
}
------------------------------------
EXERCICIO 3

#include <stdio.h>
int main(void) {
    int a, b, *pt1, *pt2;
    
    pt1 = &a;
    pt2 = &b;
    
    a = 1;
    (*pt1)++;
    b = a + *pt1;
    *pt2 = *pt1 * *pt2;
    
    printf("a=%d, b=%d, *pt1=%d, *pt2=%d\n", a, b, *pt1, *pt2);
    
    return 0;
}
-----------------------------------
EXERCICIO 4
#include <stdio.h>
int main(void) {
    int a, b, c, *ptr;
    
    a = 3;
    b = 7;

    printf("a=%d, b=%d\n", a, b);
    
    ptr = &a;
    c = *ptr;
    ptr = &b;
    a = *ptr;
    ptr = &c;
    b = *ptr;

    printf("a=%d, b=%d\n", a, b);
    
    return 0;
}
-----------------------------------
EXERCICIO 5
#include <stdio.h>
int main(void) {
    int i, j, *p, *q;
    
    p = &i;
    q = p;
    *p = 1;
    printf("i=%d, *p=%d, *q=%d\n", i, *p, *q);

    q = &j;
    i = 6;
    *q = *p;
    printf("i=%d, j=%d, *p=%d, *q=%d\n", i, j, *p, *q);

    return 0;
}
*/
