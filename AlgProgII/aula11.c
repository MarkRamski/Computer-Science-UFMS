#include <stdio.h>
#define MAX 100

void insercao(int n, int v[MAX]) {
    int i, j, x;

    for (i = 1; i < n; i++) {
        x = v[i];

        for (j = i-1; j >= 0 && v[j] > x; j--)
            v[i+1] = v[j];
        
        v[j+1] = x;
    }
}