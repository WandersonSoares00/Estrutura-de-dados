#include <stdlib.h>
#include <stdio.h>
#include "arvBin.h"

void printInOrdem(No *raiz){
    if( raiz == NULL )
        return;
    printInOrdem(raiz -> esq);
    printf("%5d", raiz ->val );
    printInOrdem(raiz -> dir);
}

void vetparaBST(int *vet, No *raiz, int *index){
    if( raiz == NULL || vet == NULL)
        return;
    vetparaBST(vet, raiz -> esq, index);

    raiz -> val = vet[*index];
    (*index)++;

    vetparaBST(vet, raiz -> dir, index);
}

void BTparaVetor(No *raiz, int *vet, int *index){
    if( raiz == NULL )
        return;
    BTparaVetor(raiz -> esq, vet, index);

    vet[*index] = raiz -> val;
    (*index)++;

    BTparaVetor(raiz -> dir, vet, index);
}

int contNos(No *raiz){
    if( raiz == NULL )
        return 0;
    return contNos(raiz -> esq) + contNos(raiz -> dir) + 1;
}

int compara(const void* a, const void* b){
    return (*(int*)a - *(int*) b);
}

void BTparaBST(No **raiz){

    int numNos = contNos(*raiz);

    int inOrder[numNos];
    int i = 0;

    BTparaVetor(*raiz, inOrder, &i);

    qsort(inOrder, numNos, sizeof(inOrder[0]), compara);

    i = 0;
    vetparaBST(inOrder, *raiz, &i);
}



int main(int argc, char *argv){
    No *raiz;
    int i;

    /*  Árvore Binária:
             10
            /  \
            2   7
           / \
          8   4
    */
    raiz = novoNo(10);  raiz -> esq = novoNo(2);   raiz -> dir = novoNo(7);
    raiz -> esq -> esq = novoNo(8);  raiz -> esq -> dir = novoNo(4);

    printInOrdem(raiz);
    printf("\n");

    BTparaBST(&raiz);

    printInOrdem(raiz);
    printf("\n");

    return EXIT_SUCCESS;
}
