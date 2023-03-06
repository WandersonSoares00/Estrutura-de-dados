#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct No{
    int val;
    struct No* xno;
}Lista;

void insercao_order(Lista **list, int valor){
    Lista *ant, *prox, *novo, *atual, *aux;
    
    ant = NULL;
    atual = *list;
    novo = (Lista *) malloc(sizeof(Lista));
    if(novo == NULL)    return;

    novo -> val = valor;

    while ( atual != NULL && valor >= atual -> val ){
            ant = atual;
            atual = xor(ant, atual -> xno);
    }

    if( ant != NULL ){ // Se não é no início
        aux = xor(ant -> xno, atual); //anterior do anterior
        ant -> xno = xor(aux, novo);
    }
    if( atual != NULL ){ // Se não é inserção no fim
        prox = xor(atual -> xno, ant);  // proximo do atual
        atual -> xno = xor(prox, novo);
    }
    
    novo -> xno = xor(ant, atual);
    
    if( *list == NULL ) //Lista vazia
        *list = novo;

}


void printLista(Lista *list){
    Lista *ant = NULL, *atual = list, *prox;

    while (atual != NULL) {
        printf("%d ", atual -> val);
        prox = xor(ant, atual -> xno);
        ant = atual;
        atual = prox;
    }
}


int main(void){
    Lista *p;
    int i;

    for( i = 0; i < 10; i++ )
        insercao_order(&p, i);    
    
    im

    return 0;
}
