#include <stdio.h>
#include <unistd.h>
#include "avl.h"


int main(int argc, char *argv){
    No *raiz = NULL;
    int i;

    for ( i = 0; i < 30; i++){
        raiz = inserir(raiz, i);
        printf("\nElemento %d inserido.\n\n", i);
        printAVL(raiz, 0);
        sleep(1);
        CLRSCREEN
    }
    
    
    for ( i = 30; i >= 0; i--){
        raiz = remover(raiz, i);
        printf("\nValor %d removido \n\n", i);
        printAVL(raiz, 0);
        sleep(1);
        CLRSCREEN
    }
    
    return 0;
}
