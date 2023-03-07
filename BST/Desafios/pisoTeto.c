#include <stdlib.h>
#include <stdio.h>
#include "arvBin.h"

No *teto(No *raiz, int chave);
No *piso(No *raiz, int chave);
void pisoTetoBST(No *raiz, int chave, No **piso, No **teto);

int main(int argc, char *argv){
    No *raiz, *p, *t;
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
    
    for ( i = 10; i <= 100; i += 10){
        pisoTetoBST(raiz, i, &p, &t);
        if( p != piso(raiz, i))     printf("erro\n");
        if( t != teto(raiz, i))     printf("erro\n");
        printf("(%3d)\tpiso: %3d ", i, p == NULL ? -1 : p -> val);
        printf("  teto: %3d\n", t == NULL ? -1 : t -> val);
    }

    printf("\n");

    return EXIT_SUCCESS;
}

No *teto(No *raiz, int chave){
    if( raiz == NULL )
        return NULL;
    if( chave == raiz -> val )
        return raiz;
    if( raiz -> val < chave )
        return teto(raiz -> dir, chave);
    // raiz -> val > chave
    No *resp = teto(raiz -> esq, chave);
    
    if( resp == NULL )
        return raiz;
    else
        return resp;
}

No *piso(No *raiz, int chave){
    if( raiz == NULL )
        return NULL;
    if( chave == raiz -> val )
        return raiz;
    if( raiz -> val > chave )
        return piso(raiz -> esq, chave);
    // raiz -> val < chave
    No *resp = piso(raiz -> dir, chave);
    
    if( resp == NULL || resp -> val < raiz -> val )
        return raiz;
    else
        return resp;
}

void pisoTetoBST(No *raiz, int chave, No **piso, No **teto){
    *piso = *teto = NULL;

    while (raiz != NULL){
        if( raiz -> val == chave ){
            *piso = *teto = raiz;
            return;
        }
        if( raiz -> val > chave ){
            *teto = raiz;
            raiz = raiz -> esq;
        }else{
            *piso = raiz;
            raiz = raiz -> dir;
        }
    }
}

