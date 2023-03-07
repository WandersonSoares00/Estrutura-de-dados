#include <stdlib.h>
#include <stdio.h>
#include "arvBin.h"

void buscaPreSuc(No *raiz, int *pre, int *suc, int x);
void buscaPreSucInter(No *raiz, No **pre, No **suc, int x);

int main(int argc, char *argv){
    No *raiz;
    No *predessedor, *sucessor;
    int x;

    /*
            30
           /  \
          20  80
         /   /  \
        10  60  90
    */
    insercao(&raiz, 30); insercao(&raiz, 80); insercao(&raiz, 20);
    insercao(&raiz, 90); insercao(&raiz, 60); insercao(&raiz, 10);

    scanf("%d", &x);
    buscaPreSucInter(raiz, &predessedor, &sucessor, x);
    printf("%d  < %d < %d\n", predessedor ? predessedor->val : -1 , x, sucessor ? sucessor -> val : -1);

    return EXIT_SUCCESS;
}

void buscaPreSuc(No *raiz, int *pre, int *suc, int x){
    No *aux;

    if( raiz == NULL )      return;
    if( raiz -> val == x ){
        if( raiz -> esq != NULL ){
            aux = raiz -> esq;
            while (aux -> dir != NULL)
                aux = aux -> dir;
            *pre = aux -> val;
        }
        if( raiz -> dir != NULL ){
            aux = raiz -> dir;
            while (aux -> esq != NULL)
                aux = aux -> esq;
            *suc = aux -> val;
        }
    }
    else if( raiz -> val > x ){
        *suc = raiz -> val;
        buscaPreSuc(raiz -> esq, pre, suc, x);
    }
    else{
        *pre = raiz -> val;
        buscaPreSuc(raiz -> dir, pre, suc, x);
    }
}


void buscaPreSucInter(No *raiz, No **pre, No **suc, int x){
    No *atual = raiz;
    *pre = *suc = NULL;

    while (atual != NULL)
        if( atual -> val < x ){
            *pre = atual;
            atual = atual -> dir;
        }else
            atual = atual -> esq;
    
    atual = raiz;

    while (atual != NULL)
        if( atual -> val > x ){
            *suc = atual;
            atual = atual -> esq;
        }else
            atual = atual -> dir;
}
