#include <stdio.h>
#include <stdlib.h>
#include "encadeamento.h"

struct BST{
    int dado;
    struct BST *esq, *dir;
};

void BSTinserir(struct BST **raiz, int chave){
    if( (*raiz) == NULL){
        *raiz = (struct BST*) malloc(sizeof(struct BST*));
        (*raiz) -> esq = (*raiz) -> dir = NULL;
        (*raiz) -> dado = chave;
        return;}
    if( chave < (*raiz) -> dado )
        BSTinserir(&(*raiz) -> esq, chave);
    else if( chave > (*raiz) -> dado )
        BSTinserir(&(*raiz) -> dir, chave);
}

int obterTravessiaVertival(struct BST *raiz, No ***tab, int hd){
    if( raiz == NULL )
        return hd;
    
    (*tab)[hd] = addFim((*tab)[hd], raiz -> dado);

    obterTravessiaVertival(raiz -> esq, tab, hd - 1);
    return obterTravessiaVertival(raiz -> dir, tab, hd + 1);
}

void printVertical(struct BST *raiz){
    int i;
    No **hashMap;
    
    HTincializar(&hashMap);
    //Distancia relativa da raiz aos filho iniciada em 40 para evitar index negativos
    i = obterTravessiaVertival(raiz, &hashMap, 40);
    
    for ( i--; hashMap[i] ; i--){
        printList(hashMap[i]);
        printf("\n");
    }
}

int main(int argc, char *argv){
    struct BST *raiz;
    /*
            30
           /  \
          20  80
         /   /  \
        10  60  90
    */
    BSTinserir(&raiz, 30); BSTinserir(&raiz, 80); BSTinserir(&raiz, 20);
    BSTinserir(&raiz, 90); BSTinserir(&raiz, 60); BSTinserir(&raiz, 10);

    printVertical(raiz);

    return EXIT_SUCCESS;
}
