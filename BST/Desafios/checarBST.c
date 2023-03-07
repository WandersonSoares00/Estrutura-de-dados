#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include "arvBin.h"

int valMax(No *raiz);
int valMin(No *raiz);
int BST(No *raiz);
int auxBSTv2(No *raiz, int min, int max);
int BST_v2(No *raiz);
int auxBSTv3(No *raiz, No *ant);
int BST_v3(No *raiz);

int main(int argc, char *argv){
    No *raiz;
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
    
    if(BST_v3(raiz))
        printf("Eh BST\n");
    else
        printf("Nao eh BST\n");

    return EXIT_SUCCESS;
}


int valMax(No *raiz){
    if (raiz == NULL) {
        return 0;
    }
 
    int esqMax = valMax(raiz-> esq);
    int dirMax = valMax(raiz-> dir);
 
    int valor = 0;
    if (esqMax > dirMax) {
        valor = esqMax;
    }
    else {
        valor = dirMax;
    }
 
    if (valor < raiz -> val) {
        valor = raiz -> val;
    }
 
    return valor;
}

int valMin(No *raiz){
    if (raiz == NULL) {
        return 0;
    }
 
    int esqMin = valMin(raiz-> esq);
    int dirMin = valMin(raiz-> dir);
 
    int valor = 0;
    if (esqMin < dirMin) {
        valor = esqMin;
    }
    else {
        valor = dirMin;
    }
 
    if (valor > raiz -> val) {
        valor = raiz -> val;
    }
 
    return valor;
}

int BST(No *raiz){
    if( raiz == NULL )
        return 1;
    if( raiz -> esq != NULL && valMax(raiz -> esq) < raiz -> val )
        return 1;
    if( raiz -> dir != NULL && valMin(raiz -> dir) > raiz -> val )
        return 1;
    if( BST(raiz -> esq) && BST(raiz -> dir) )
        return 1;
    else
        return 0;
}

int auxBSTv2(No *raiz, int min, int max){
    if(raiz == NULL)        
        return 1;
    if( raiz -> val < min || raiz -> val > max )
        return 0;
    return (auxBSTv2(raiz -> esq, min, raiz -> val - 1)) && auxBSTv2(raiz -> dir, raiz -> val + 1, max);
}

int BST_v2(No *raiz){
    return auxBSTv2(raiz, INT_MIN, __INT_MAX__);
}

int auxBSTv3(No *raiz, No *ant){
    if( raiz == NULL )
        return 1;
    if( !auxBSTv3(raiz -> esq, ant) )
        return 0;
    
    if( ant != NULL && raiz -> val < ant -> val )
        return 0;

    No *anterior = raiz;       

    if( !auxBSTv3(raiz -> dir, anterior) )
        return 0;
}

int BST_v3(No *raiz){
    No *anterior = NULL;
    return auxBSTv3(raiz, anterior);
}
