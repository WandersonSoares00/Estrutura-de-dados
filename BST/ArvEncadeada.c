#include <stdlib.h>
#include <stdio.h>

typedef struct BTT{
    int val;
    struct BTT *esq, *dir;
    char dthread;   // 'n': falso ; 's': verdadeiro
}No;

No *maisEsquerda(No *raiz){
    if( raiz == NULL )
        return NULL;
    
    while (raiz -> esq != NULL)
        raiz = raiz -> esq;
    
    return raiz;
}

void inOrder(No *raiz){
    No *atual = maisEsquerda(raiz);

    while( atual != NULL ){
        printf("%d ", atual -> val);
        
        if( atual -> dthread == 's' )
            atual = atual -> dir;
        else
            atual = maisEsquerda(atual -> dir);
    }
    
}

void insercao(No **raiz, int k){
    No *sucessor = NULL;
    No *atual, *anterior;
    No *novo = (No *) malloc(sizeof(No));
    novo -> val = k;

    atual = anterior  = *raiz;
    while(atual != NULL){
        anterior = atual;
        if( atual -> val > k){
            sucessor = atual;
            atual = atual -> esq;
        }
        else{
            if( atual -> dthread == 's' ){
                atual -> dir = NULL;
                atual -> dthread = 'n';
            }
            atual = atual -> dir;
        }
    }

    if(anterior == NULL)
        *raiz = novo;
    else if( anterior -> val > k )
        anterior -> esq = novo;
    else
        anterior -> dir = novo;
    if( sucessor != NULL ){
        novo -> dir = sucessor;
        novo -> dthread = 's';
    }
}

int main(int argc, char *argv){
    No *raiz;
    /*
            30
           // \
          20  80
         //  // \
        10  60  90
    */
    insercao(&raiz, 30); insercao(&raiz, 80); insercao(&raiz, 20);
    insercao(&raiz, 90); insercao(&raiz, 60); insercao(&raiz, 10);

    inOrder(raiz);
    printf("\n\n");
    
    insercao(&raiz, 70);
    inOrder(raiz);
    printf("\n");

    return EXIT_SUCCESS;
}
