#ifndef HEAP_H
#define HEAP_H

#define TAM_MAX  50

int pai(int i);
int filhoEsquerdo(int i);
int filhoDireito(int i);
void troca(int *a, int *b);
int obterMax(int *h);
int inserir(int *h, int *index, int dado);
void printHeap(int *h, int index, int n, int nivel);
void corrigeDescendo(int *h, int i, int n);
int removeMax(int *h, int *n);
void constroiMaxHeap(int *h, int n);


#endif