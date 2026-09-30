#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#define MAX 100000
/*
// #include <unistd.h> // Apenas para usar o sleep() de exemplo
int main() {
  struct timeval inicio, fim;
  int v[MAX];

  // Captura o tempo inicial
  gettimeofday(&inicio, NULL);

  // Trecho de código que você quer medir (exemplo: pausa de 1 segundo)
  // sleep(1);
  for(int i=0;  i < MAX; i++)
    v[i] = rand()%(107 * MAX);
    
  // Captura o tempo final
  gettimeofday(&fim, NULL);

  // Calcula a diferença em segundos e microssegundos
  long segundos = fim.tv_sec - inicio.tv_sec;
  long microssegundos = fim.tv_usec - inicio.tv_usec;

  // Converte tudo para o total em microssegundos
  long long tempo_total = (segundos * 1000000LL) + microssegundos;
  printf("Tempo decorrido: %lld microssegundos\n", tempo_total);
  printf("Tempo decorrido: %.6f segundos\n", (double)tempo_total / 1000000.0);
  return 0;
}
*/
void mergesort(int p, int r, int v[MAX]) {
    int q;

    if (p < r - 1) {
        q = (p + r) / 2;
        mergesort(p, q, v);
        mergesort(q, r, v);
        intercala(p, q, r, v);
    }
}

int main() {
    struct timeval inicio, fim;
    int v[MAX];

    gettimeofday(&inicio, NULL);


}
