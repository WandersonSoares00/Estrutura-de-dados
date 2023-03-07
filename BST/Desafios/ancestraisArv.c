#include <stdlib.h>
#include <stdio.h>
#include "arvBin.h"

int printAncestrais(No *raiz, int k){
    if( raiz == NULL )
        return 0;
    if( raiz -> val == k )
        return 1;
    if( (printAncestrais(raiz -> esq, k)) || printAncestrais(raiz -> dir, k)){
        printf(" %d ", raiz -> val);
        return 1;
    }
    else
        return 0;
}


int main(int argc, char *argv){
    No *raiz;
    /*
            30
           /  \
          20  80
         /   /  \
        10  60  90
    */
    insercao(&raiz, 30); insercao(&raiz, 80); insercao(&raiz, 20);
    insercao(&raiz, 90); insercao(&raiz, 60); insercao(&raiz, 10);

    printAncestrais(raiz, 10);
    printf("\n");
    printAncestrais(raiz, 60);
    printf("\n");

    return EXIT_SUCCESS;
}