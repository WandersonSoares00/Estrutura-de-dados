#include <stdio.h>
#include <stdlib.h>
#include "encadeamento.h"

void HTincializar(No ***tab){
    (*tab) = (No **) malloc(M * sizeof(No *));
    for (int i = 0; i < M; i++)
        (*tab)[i] = NULL;
}

No *addFim(No *q, int chave){
    No *temp = q;
    No *novo = (No *) malloc(sizeof(No *));
    novo -> dado = chave;
    novo -> prox = NULL;
    while (temp != NULL)
        if( temp -> prox == NULL){
            temp -> prox = novo;
            return q;    
        }
        else
            temp = temp -> prox;
    return novo;
}

void HTinserir(No ***tab, int chave){
    int index = Hash(chave);
    (*tab)[index] = addFim((*tab)[index], chave);
}

void printList(No *q){
    while (q != NULL){
        printf("%d --> ", q -> dado );
        q = q -> prox;
    }
    //printf("%p", q);
}

void printHash(No **tab){
    for (int i = 0; i < M; i++){
        printf("%d  --> ", i);
        printList(tab[i]);
        printf("\n");
    }
}

void HTprint(No **tab){
    No *temp;
    int i;
    for ( i = 0; i < M; i++){
        temp = tab[i];
        if( temp != NULL ){
            printf("%d ", temp -> dado);
            temp = temp -> prox;
            if(temp == NULL)    printf("\n");
        }
    }
}

/*
int main(){
    No **h;
    int i, a[] = {15, 11, 27, 8, 12};;
    int n = sizeof(a) / sizeof(*a);

    HTincializar(&h);

    for ( i = 0; i < n; i++)
        HTinserir(&h, a[i]);

    printHash(h);
}

*/