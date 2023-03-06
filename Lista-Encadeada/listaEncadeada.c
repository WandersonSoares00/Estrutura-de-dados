/*    Rotate a Linked List    */

#include <stdio.h>
#include <stdlib.h>

typedef struct No{
    int val;
    struct No* prox;
}Lista;

void insercao(Lista **p, int x){
    Lista *novo_no = (Lista *) malloc(sizeof(Lista));

    novo_no -> val = x;
    novo_no -> prox = *p;
    (*p) = novo_no;
}

void printLista(Lista *p){
    while (p != NULL) {
        printf("%d ", p -> val);
        p = p -> prox;
    }
}

void rotacionar(Lista **p, int k){
    Lista *q1, *q2, *inicio = NULL;
    
    if( k <= 0 )     return;

    q1 = *p;
    while( q1 != NULL ){
        q2 = q1;
        q1 = q1 -> prox;
        k--;
        if( k == 0 ){
            q2 -> prox = NULL;
            inicio = q1;
        }
    }

    if( k <= 0 && inicio != NULL ){
        q2 -> prox = *p;
        *p = inicio;
    }
}

int main(void){
    Lista *head = NULL;
    int i;

    // cria a lista 10->20->30->40->50->60
    for (i = 60; i > 0; i -= 10)
        insercao(&head, i);
 
    printf("Lista encadeada: \n");
    printLista(head);
    
    rotacionar(&head, -3);
 
    printf("\nLista rotacionada: \n");
    printLista(head);
    printf("\n\n");

    return 0;
}
