#include <stdlib.h>
#include <stdio.h>
#include "pilha.h"
#include "fila.h"

void kMenores(No *raiz, int k);

int main(int argc, char *argv){
    No *raiz;
    int i;

    /*
            30
           /  \
          20  80
         /   /  \
        10  60  90
    */
    insercao(&raiz, 30); insercao(&raiz, 80); insercao(&raiz, 20);
    insercao(&raiz, 90); insercao(&raiz, 60); insercao(&raiz, 10);
    
    for ( i = 0; i <= 6; i++){
        kMenores(raiz, i);
        printf("\n");
    }
    
    return EXIT_SUCCESS;
}

void kMenores(No *raiz, int k){
    struct fNo *pilha = NULL;
    int inic, fim;
    No **fila = criaFila(&inic, &fim);
    No *atual = raiz;

    if(raiz == NULL)    return;

    empilhar(&pilha, raiz);

    while (!pilhaVazia(pilha) && k > 0){
        if( atual != NULL ){
            empilhar(&pilha, atual);
            atual = atual -> esq;
        }
        else if( !pilhaVazia(pilha) ){
            atual = desempilhar(&pilha);
            enfileirar(fila, &fim, atual);
            k--;
            atual = atual -> dir;
        }
    }

    while (!fvazia(inic, fim)){
        atual = desenfileirar(fila, &inic);
        printf("%d ", atual -> val);
    }

    free(pilha);
}
