#ifndef PILHA_h
#define PILHA_h
#include "fila.h"

struct fNo{
    No *tNo;
    struct fNo *prox;
};

int pilhaVazia(struct fNo *topo);
void empilhar(struct fNo **topo, No *dado);
No *desempilhar(struct fNo **topo);

#endif