#include <stdio.h>
#include <stdlib.h>
#include "arvBin.h"

void insercao(No **raiz, int k){
    No *aux, *q1, *q2;
    aux = (No *) malloc(sizeof(No));
    if(aux == NULL)
        return;
  
    aux -> val = k;
    aux -> esq = NULL;
    aux -> dir = NULL;

    q1 = q2 = *raiz;
    while( q1 != NULL ){
        q2 = q1;
        if( k > q1 -> val )
          q1 = q1 -> dir;
        else
          q1 = q1 -> esq;
    }

    if(q2 == NULL)
        *raiz = aux;
    else if(k > q2 -> val)
        q2 -> dir = aux;
    else 
        q2 -> esq = aux;
}


int altura(No *raiz){
    if( raiz == NULL )
        return 0;
    else{
        int e_altura = altura(raiz -> esq);
        int d_altura = altura(raiz -> dir);
        
        if( e_altura > d_altura )
            return (e_altura + 1);
        else
            return (d_altura + 1);
    }
}


No *remover(No *raiz, int chave){
    if( raiz == NULL )
        return NULL;
    else if( chave < raiz -> val )
        raiz -> esq = remover(raiz -> esq, chave);
    else if( chave > raiz -> val )
        raiz -> dir = remover(raiz -> dir, chave);
    else{ // busca bem sucedida
        if( raiz -> esq == NULL ){ // Um filho ou sem filhos
            No *temp = raiz -> dir;
            free(raiz);
            return temp;
        }
        if( raiz -> dir == NULL ){ // Apenas o filho esquerdo
            No *temp = raiz -> esq;
            free(raiz);
            return temp;
        }
        else{ // raiz com dois filhos
            No *temp = NoMinValor(raiz -> dir);
            raiz -> val = temp -> val;
            raiz -> dir = remover(raiz -> dir, chave);
        }
    }
    return raiz;
}

No *novoNo(int k){
    No *temp = (No *) malloc(sizeof(No));
    temp -> esq = NULL;
    temp -> dir = NULL;
    temp -> val = k;
    return temp;
}
