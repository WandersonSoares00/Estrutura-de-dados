#include <stdlib.h>
#include <stdio.h>
#include "Arb.h"

No *novoNo(int chave){
    No *temp = (No *) malloc(sizeof(No));
    temp -> dado = chave;
    temp -> esq = NULL;
    temp -> dir = NULL;
    temp -> cor = VERMELHO;
    return temp;
}

int vermelho(No *y){
    if(y == NULL)       return 0;
    else                return y -> cor == VERMELHO ?   1   :   0;
}

void inverteCor(No **y){
    (*y) -> cor = VERMELHO;
    (*y) -> esq -> cor = PRETO;
    (*y) -> dir -> cor = PRETO;
}

void rotacEsq(No **A){
    No *h, *x;
    h = *A;     x = h -> dir;
    h -> dir = x -> esq;
    x -> esq = h;
    x -> cor = h -> cor;
    h -> cor = VERMELHO;
    *A = x;
}

void rotacDir(No **A){
    No *h, *x;
    h = *A;     x = h -> esq;
    h -> esq = x -> dir;
    x -> dir = h;
    x -> cor = h -> cor;
    h -> cor = VERMELHO;
    *A = x;
}

void concertarARB(No **raiz){
    if( vermelho((*raiz) -> dir) && !vermelho((*raiz) -> esq))
        rotacEsq(raiz);
    if( vermelho((*raiz) -> dir) && vermelho((*raiz) -> esq -> esq))
        rotacDir(raiz);
    if( vermelho((*raiz) -> dir) && vermelho((*raiz) -> esq))
        inverteCor(raiz);
}

void aux_inserir(No **raiz, int chave){
    if( (*raiz) == NULL){
        *raiz = novoNo(chave);
        return;
    }
    if( chave < (*raiz) -> dado )
        aux_inserir(&(*raiz) -> esq, chave);
    else if( chave > (*raiz) -> dado )
        aux_inserir(&(*raiz) -> dir, chave);
    
    concertarARB(raiz);
}

void inserir(No **raiz, int chave){
    aux_inserir(raiz, chave);
    (*raiz) -> cor = PRETO;
}

void aux_printARB(No *raiz, int nivel){
    if( raiz != NULL ){
        aux_printARB(raiz -> esq, nivel + 1);

        for (int i = 0; i < nivel; i++)
            printf("      ");
        printf(raiz -> cor == VERMELHO  ?   outVERMELHO     :   outRESET);
        printf("%d\n", raiz -> dado);

        aux_printARB(raiz -> dir, nivel + 1);
    }
}

void printARB(No *raiz){
    aux_printARB(raiz, 0);
}

void inOrder(No *raiz){
    if(raiz == NULL)    return;
    inOrder(raiz -> esq);
    printf("%d ", raiz -> dado);
    inOrder(raiz -> dir);
}
