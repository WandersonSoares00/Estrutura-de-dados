#include <stdlib.h>
#include <stdio.h>
#include "heap.h"

int pai(int i){
    return (i - 1) / 2;
}

int filhoEsquerdo(int i){
    return 2 * i + 1;
}

int filhoDireito(int i){
    return 2 * i + 2;
}

void troca(int *a, int *b){
    int aux = *a;
    *a = *b;
    *b = aux;
}

int obterMax(int *h){
    return h[0];
}

int inserir(int *h, int *index, int dado){
    int i;
    if( *index > TAM_MAX )
        return !printf("Overflow");

    h[(*index)++] = dado;
    
    i = *index - 1;
    while (i > 0 && h[pai(i)] < h[i] ){
        troca(&h[pai(i)], &h[i]);
        i = pai(i);
    }
    
    return 1;
}


void printHeap(int *h, int index, int n, int nivel){
	if( index < n ) { 
		printHeap(h, filhoEsquerdo(index), n, nivel + 1);
		
        for(int i = 0; i < nivel; i++)  
			printf("      "); 
		printf("%d\n", h[index]); 
		
        printHeap(h, filhoDireito(index), n, nivel + 1);
	} 
}

// Desce os elementos que ferem a propriedade max heap
void corrigeDescendo(int *h, int i, int n){
    int fesq = filhoEsquerdo(i);
    int fdir = filhoDireito(i);
    int maior = i;

    if( fesq < n && h[fesq] > h[maior] )
        maior = fesq;
    
    if( fdir < n && h[fdir] > h[maior]  )
        maior = fdir;

    if( maior != i ){
        troca(&h[maior], &h[i]);
        corrigeDescendo(h, maior, n);
    }
}

//h[0 .. n .. TAM_MAX]
int removeMax(int *h, int *n){
    int max = h[0];

    h[0] = h[*n];
    (*n)--;

    corrigeDescendo(h, 0, *n);
    return max;
}

void constroiMaxHeap(int *h, int n){
    int i;
    for ( i = n / 2 - 1; i >= 0; i--)
        corrigeDescendo(h, i, n);
}
