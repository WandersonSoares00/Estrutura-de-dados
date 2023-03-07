#include <stdio.h>
#include <stdlib.h>
#include "printArv.h"

void printArvoreInterativo(No *raiz){
    int inicio, fim;
    No **fila = criaFila(&inicio, &fim);
    No *atual = raiz;

    while (atual != NULL){
        printf("%d ", atual -> val);

        if(atual -> esq != NULL)
            enfileirar(fila, &fim, atual -> esq);
        if(atual -> dir != NULL)
            enfileirar(fila, &fim, atual -> dir);

        atual = desenfileirar(fila, &inicio);
    }
    free(fila);
}

No *maisDireita(No *raiz, No *restric){
    if( raiz == NULL )
        return NULL;
    
    while (raiz -> dir != NULL && raiz -> dir != restric)
        raiz = raiz -> dir;

    return raiz;
}

void morrisTraversal(No *raiz){
    No *atual = raiz;
    No *predecessor;

    while( atual != NULL ){
        if( atual -> esq == NULL){
            printf("%d ", atual -> val); // Menor da subarvore atual
            atual = atual -> dir;
        }
        else{
            predecessor = maisDireita(atual -> esq, atual);
            //Cronstruir BTT
            if( predecessor -> dir == NULL ){
                predecessor -> dir = atual;
                atual = atual -> esq;}
            //Desconstruir BTT
            else{
                predecessor -> dir = NULL;
                printf("%d ", atual -> val);
                atual = atual -> dir;
            }
        }
    }
}


void printPreOrdem(No *raiz){
    if( raiz == NULL )
        return;
    printf("%5d", raiz ->val );
    printPreOrdem(raiz -> esq);
    printPreOrdem(raiz -> dir);
}

void printInOrdem(No *raiz){
    if( raiz == NULL )
        return;
    printInOrdem(raiz -> esq);
    printf("%5d", raiz ->val );
    printInOrdem(raiz -> dir);
}

void printPosOrdem(No *raiz){
    if( raiz == NULL )
        return;
    printPosOrdem(raiz -> esq);
    printPosOrdem(raiz -> dir);
    printf("%5d", raiz ->val );
}

void printNoAtual(No *raiz, int nivel){
    if( raiz == NULL )
        return;
    if( nivel == 1 )
        printf("%d ", raiz -> val);
    else if( nivel > 1 ){
        printNoAtual(raiz -> esq, nivel - 1);
        printNoAtual(raiz -> dir, nivel - 1);
    }    
}

void printArvore(No *raiz){
    int i;
    int h = altura(raiz);

    for( i = 1; i <= h; i++){
        printNoAtual(raiz, i);
        printf("\n");
    }
}


void inOrderInter(No *raiz){
    No *atual = raiz;
    struct fNo *pilha = NULL;
    int visitou_todo_No = 0;

    while (!visitou_todo_No){
        if( atual != NULL ){
            empilhar(&pilha, atual);
            atual = atual -> esq;
        }
        else if( !pilhaVazia(pilha) ){
            atual = desempilhar(&pilha);
            printf("%d ", atual -> val);
            atual = atual -> dir;
        }
        else
            visitou_todo_No = 1;
    }       
}

void preOrderInterativo(No *raiz){
    struct fNo *pilha = NULL;
    No *atual;

    if(raiz == NULL )   return;

    empilhar(&pilha, raiz);
    while (!pilhaVazia(pilha)){
        atual = desempilhar(&pilha);
        printf("%d ", atual -> val);

        if( atual -> dir != NULL)
            empilhar(&pilha, atual -> dir);
        if( atual -> esq != NULL)
            empilhar(&pilha, atual -> esq);
    }    
}

void preOrderInterativo_v2(No *raiz){
    struct fNo *pilha = NULL;
    No *atual = raiz;

    while (!pilhaVazia(pilha) || atual != NULL){
        while (atual != NULL){
            printf("%d ", atual -> val);

            if(atual -> dir != NULL)
                empilhar(&pilha, atual -> dir);
            
            atual = atual -> esq;
        }
        
        if(!pilhaVazia(pilha))
            atual = desempilhar(&pilha);
    }
    
}

void posOrderInteraitivo(No *raiz){
    struct fNo *pilha1, *pilha2;
    No *atual;

    if(raiz == NULL)    return;

    pilha1 = pilha2 = NULL;
    empilhar(&pilha1, raiz);
    while (!pilhaVazia(pilha1)){
        atual = desempilhar(&pilha1);
        empilhar(&pilha2, atual);

        if(atual -> esq != NULL)
            empilhar(&pilha1, atual -> esq);
        if(atual -> dir != NULL)
            empilhar(&pilha1, atual -> dir);
    }
    
    while (!pilhaVazia(pilha2)){
        atual = desempilhar(&pilha2);
        printf("%d ", atual -> val);
    }
    
}

