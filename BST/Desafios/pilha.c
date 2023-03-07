#include <stdlib.h>
#include "pilha.h"

int pilhaVazia(struct fNo *topo){
    if( topo == NULL )      return 1;
    else                    return 0;
}

void empilhar(struct fNo **topo, No *dado){
    
    struct fNo *novo = (struct fNo *) malloc(sizeof(struct fNo));
    novo -> tNo = dado;

    if( *topo == NULL )
        novo -> prox = NULL;
    else
        novo -> prox = *topo;
    
    *topo = novo;
}

No *desempilhar(struct fNo **topo){
    //if( *topo == NULL )     return NULL;
    struct fNo *apagado = *topo;
    *topo = apagado -> prox;
    
    return apagado -> tNo;
}

