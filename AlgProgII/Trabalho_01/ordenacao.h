/*
Marcos Henrique de Souza Almeida
202419040110
*/

#ifndef ORDENACAO_H
#define ORDENACAO_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge_sort(int vetor[], int inicio, int fim);
void quick_sort(int vetor[], int inicio, int fim);
void quick_sort_insercao(int vetor[], int inicio, int fim);
void usar_qsort(int vetor[], int n);

void copiar_vetor(int origem[], int destino[], int n);
int esta_ordenado_decrescente(int vetor[], int n);
void imprimir_vetor(int vetor[], int n);

#endif