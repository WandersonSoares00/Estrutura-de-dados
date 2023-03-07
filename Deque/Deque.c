#include <stdlib.h>
#include <stdio.h>
#include "deque.h"

void inicializaDeque(Deque **d){
    *d = (Deque *) malloc(sizeof(Deque));
    (*d) -> frente = -1;
    (*d) -> cauda = -1;
}

int estaCheia(Deque *d){
    return ((d -> frente == 0 && d -> cauda == TAM_MAX) || \
            (d -> frente == d -> cauda + 1));
}

int insereFrente(Deque **d, int k){
    
    if(estaCheia(*d))   return 0; //overflow

    if( (*d) -> frente == -1 ){
        (*d) -> frente = 0;
        (*d) -> cauda = 0;
    }
    else if( (*d) -> frente == 0 )
        (*d) -> frente = TAM_MAX - 1;
    else
        ((*d) -> frente)--;

    (*d) -> vet[(*d) -> frente] = k;
    return 1;
}

int insereFim(Deque **d, int k){

    if(estaCheia(*d))   return 0; //overflow

    if( (*d) -> cauda == -1 ){
        (*d) -> frente = 0;
        (*d) -> cauda = 0;
    }
    else if( (*d) -> cauda == TAM_MAX - 1 )
        (*d) -> cauda == 0;
    else
        ((*d) -> cauda)++;

    (*d) -> vet[(*d) -> cauda] = k;
    return 1;
}

int deletaFrente(Deque **d){
    int aux = (*d) -> frente;

    if( (*d) -> frente == -1 )
        return - 1;
    else if( (*d) -> frente == (*d) -> cauda ){
        (*d) -> frente = -1;
        (*d) -> cauda = -1;
    }
    else if( (*d) -> frente == TAM_MAX - 1 )
        (*d) -> frente = 0;
    else
        ((*d) -> frente)++;

    return (*d) -> vet[aux];
}

int deletaFim(Deque **d){
    int aux = (*d) -> cauda;

    if( (*d) -> cauda == -1 )
        return - 1;
    else if( (*d) -> frente == (*d) -> cauda ){ 
        (*d) -> frente = -1;
        (*d) -> cauda = -1;
    }
    else if( (*d) -> cauda == 0 )
        (*d) -> cauda = TAM_MAX - 1;
    else
        ((*d) -> cauda)--;

    return (*d) -> vet[aux];
}

void exibeDeque(Deque *d){
    int item;

    if( d -> frente != -1 ){
        item = deletaFrente(&d);
        printf(" [ %d ] ", item);
        exibeDeque(d);
        insereFrente(&d, item);
    }
}
/*
int main(int argc, char *argv){
    Deque *dq;
    int i;

    inicializaDeque(&dq);

    for ( i = 0; i < 10; i++)
        insereFrente(&dq, i);
    
    exibeDeque(dq);
    
    if(insereFrente(&dq, 10));{
        printf("\n\n");
        exibeDeque(dq);
        printf("\n\n");
    }

    if(insereFim(&dq, 78));{
        printf("\n\n");
        exibeDeque(dq);
        printf("\n\n");
    }

    deletaFim(&dq);
    exibeDeque(dq);
    printf("\n\n");

    deletaFrente(&dq);
    exibeDeque(dq);
    printf("\n\n");

    return EXIT_SUCCESS;
}
*/