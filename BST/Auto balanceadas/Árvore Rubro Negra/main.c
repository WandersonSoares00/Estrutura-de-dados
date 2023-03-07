#include <stdio.h>
#include "Arb.h"

int main(int argc, char *argv){
    No *raiz = NULL;
    int i;

    for ( i = 0; i < 60; i++){
        inserir(&raiz, i);
    }

    printARB(raiz);
    printf("\n");
}
