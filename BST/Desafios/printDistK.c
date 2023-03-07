#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

void printDistKRec(No *raiz, int k);
void printFila(No **fila, int *frente, int tam);
void printDistKInter(No *raiz, int k);

int main(){
    No *raiz;
    int cont;
    int alt;
    /*
            30
           /  \
          20  80
         /   /  \
        10  60  90
    */
    insercao(&raiz, 30); insercao(&raiz, 80); insercao(&raiz, 20);
    insercao(&raiz, 90); insercao(&raiz, 60); insercao(&raiz, 10);
    
    alt = altura(raiz);
    for(cont = 0; cont < alt; cont++){
        printDistKRec(raiz, cont);
        printf("\n");
    }

    printf("\n\n");

    for(cont = 0; cont < alt; cont++){
        printDistKInter(raiz, cont);
        printf("\n");
    }

    return 0;
}

void printDistKRec(No *raiz, int k){
    if(raiz == NULL || k < 0)
        return;
    if( k == 0){
        printf(" %d ", raiz -> val);
        return;
    }
    printDistKRec(raiz -> esq, k - 1);
    printDistKRec(raiz -> dir, k - 1);
}

void printFila(No **fila, int *frente, int tam){
    No *atual;

    while (tam--){
        atual = desenfileirar(fila, frente);
        printf(" %d ", atual -> val);
    }
}

void printDistKInter(No *raiz, int k){
    int inic, ftam, fim, nivel = 0;
    No *atual;
    No **fila;

    if( raiz == NULL )  return;

    fila = criaFila(&inic, &fim);
    enfileirar(fila, &fim, raiz);

    while (!fvazia(inic, fim)){
        ftam = filaTamanho(inic, fim);

        if( nivel == k )
            return printFila(fila, &inic, ftam);
        
        for (; ftam ; ftam--){
            atual = desenfileirar(fila, &inic);

            if(atual -> esq != NULL)
                enfileirar(fila, &fim, atual -> esq);
            if(atual -> dir != NULL)
                enfileirar(fila, &fim, atual -> dir);
        }

        nivel++;
    }

    free(fila);
}
