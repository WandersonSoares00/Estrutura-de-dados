#include <stdio.h>
#include <stdlib.h>
#include "utilid.h"
#include "ordena.h"

#define TAM_MAX 100000


int main(int argc, char *argv){
    long t_ins, t_ms, t_msi, t_hs, t_qs1, t_qs2, t_qs3, t_qc;
    int vetor[TAM_MAX];
    
    aleatoriza(vetor, TAM_MAX);
    
    t_ins = tempoOrdenar(insertionSort, vetor, TAM_MAX);
    t_ms =  tempoOrdenar(mergesort, vetor, TAM_MAX);
    t_msi = tempoOrdenar(mergesort_interativo, vetor, TAM_MAX);
    t_qs1 = tempoOrdenar(quick_sortv1, vetor, TAM_MAX);
    t_qs2 = tempoOrdenar(quick_sortv2, vetor, TAM_MAX);
    t_qs3 = tempoOrdenar(quick_sortv3, vetor, TAM_MAX);
    t_hs =  tempoOrdenar(heapSort, vetor, TAM_MAX);
    t_qc =  tempoRotina_qs(vetor, TAM_MAX, sizeof(int), compara);

    printf("\nAlgoritmo \t\t Tempo de execucao\n");
    printf("Insertion Sort:          %8ld milisegundos\n", t_ins);
    printf("Merge Sort:              %8ld milisegundos\n", t_ms);
    printf("Merge Sort: (interativo) %8ld milisegundos\n", t_msi);
    printf("Heap Sort:               %8ld milisegundos\n", t_hs);
    printf("quick Sort: (versao 1)   %8ld milisegundos\n", t_qs1);
    printf("quick Sort: (versao 2)   %8ld milisegundos\n", t_qs2);
    printf("quick Sort: (versao 3)   %8ld milisegundos\n", t_qs3);
    printf("quick Sort: (c nativo)   %8ld milisegundos\n", t_qc);

    /* (Usando clock_t)
    Saída 13/01
        Insertion Sort:           7.724809
        Merge Sort:               0.018681
        Merge Sort: (interativo)  0.017936
        quick Sort: (versao 1)    0.014686
        quick Sort: (versao 2)    0.013184
        quick Sort: (versao 3)    0.017419
    */

    return EXIT_SUCCESS;
}
