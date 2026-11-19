/*
// Primeiro exemplo

#include <stdio.h>

struct marca {
    int hh;
    int mm;
    int ss;
};

int converte_segundos(struct marca tempo) {
return tempo.hh * 3600 + tempo.mm * 60 + tempo.ss;
}

int main(void) {
    int segundos;
    struct marca horario;

    printf("Informe um horario (hh:mm:ss): ");
    scanf("%d:%d:%d", &horario.hh, &horario.mm, &horario.ss);

    segundos = converte_segundos(horario);

    printf("Passaram-se %d segundo(s) neste dia\n", segundos);

    return 0;
}
--------------------------------------------------------
// Segundo Exemplo

#include <stdio.h>

struct marca {
int hh; int mm; int ss;
};

void adiciona_segundo(struct marca *tempo) {
    (*tempo).ss++;
    
    if ((*tempo).ss == 60) {
        (*tempo).ss = 0;
        (*tempo).mm++;
        
        if ((*tempo).mm == 60) {
            (*tempo).mm = 0;
            (*tempo).hh++;

            if ((*tempo).hh == 24)
                (*tempo).hh = 0;
        }
    }
}

int main(void) {
    struct marca horario;

    scanf("%d:%d:%d", &horario.hh, &horario.mm, &horario.ss);

    adiciona_segundo(&horario);

    printf("Novo: %02d:%02d:%02d\n", horario.hh, horario.mm, horario.ss);

    return 0;
}
-------------------------------------------------------
// Terceiro Exemplo

#include <stdio.h>

struct marca {
    int hh;
    int mm;
    int ss;
};

void adiciona_segundo(struct marca *tempo) {
    tempo->ss++;

    if (tempo->ss == 60) {
        tempo->ss = 0;
        tempo->mm++;
        
        if (tempo->mm == 60) {
            tempo->mm = 0;
            tempo->hh++;

            if (tempo->hh == 24)
                tempo->hh = 0;
        }
    }
}

int main(void) {
    struct marca horario;

    printf("Informe um horario (hh:mm:ss): ");
    scanf("%d:%d:%d", &horario.hh, &horario.mm, &horario.ss);

    adiciona_segundo(&horario);

    printf("Novo horário %02d:%02d:%02d\n", horario.hh, horario.mm, horario.ss);

    return 0;
}
*/
#include <stdio.h>

struct data {
    int dd;
    int mm;
    int aaaa;
};

int bissexto(struct data d) {
    if (d.aaaa % 4 == 0 && d.aaaa % 100 != 0 || d.aaaa % 400 == 0) {
        return 1;
    }
    else {
        return 0;
    }
}

int dias_mes(struct data d) {
    if (d.mm == 2){

        if (bissexto(d) == 1) {
            return 29;
        } 
        else {
            return 28;
        }
    }

    if (d.mm == 4 || d.mm == 6 || d.mm == 9 || d.mm == 11) {
        return 30;
    }

    if (d.mm == 1 || d.mm == 3 || d.mm == 5 || d.mm == 7 || d.mm == 8 || d.mm == 10 || d.mm == 12) {
        return 31;
    }
}      


