#ifndef FILA_h
#define FILA_h

#include "arvBin.h"
#define TAM_FILA_MAX 20

No **criaFila(int *frente, int *cauda);
int filaTamanho(int frente, int cauda);
int fvazia(int frente, int cauda);
void enfileirar(No **fila, int *cauda, No *dados);
No *desenfileirar(No **fila, int *frente);

#endif