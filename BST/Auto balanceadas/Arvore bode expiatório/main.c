#include <stdio.h>
#include <unistd.h>
#include "sgt.h"

int main(int argc, char *argv){
    sgt arvore;
    int i;

    inicializar(&arvore);

    for ( i = 0; i < 60; i++){
        inserir(&arvore, i);
        printSGT(&arvore);
        sleep(1);
        CLRSCREAN
    }

    printSGT(&arvore);
    printf("\n");
}
