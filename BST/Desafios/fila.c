#include <stdlib.h>
#include "fila.h"

No **criaFila(int *frente, int *cauda){
    *frente = 0;
    *cauda = 0;
    
    No **fila = (No **) malloc( sizeof(No *) * TAM_FILA_MAX);

    return fila;
}

int filaTamanho(int frente, int cauda){
    return (cauda - frente);
}

int fvazia(int frente, int cauda){
    if((frente == cauda) || (frente > cauda))
        return 1;
    else
        return 0;
}

void enfileirar(No **fila, int *cauda, No *dados){
    fila[(*cauda)] = dados;
    (*cauda)++;
}

No *desenfileirar(No **fila, int *frente){
    (*frente)++;
    return fila[*frente - 1];
}
