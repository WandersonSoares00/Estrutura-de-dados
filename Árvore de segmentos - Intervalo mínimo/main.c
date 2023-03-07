#include <stdio.h>
#include "st.h"

#define TAM_MAX     20
void printList(int *l);

int main(int argc, char *argv){
    int lista[TAM_MAX];
    int *arvoreSt;
    int i;

    for ( i = 0; i < TAM_MAX; i++)         lista[i] = i;

    arvoreSt = construirST(lista, TAM_MAX);
    
    printList(lista);               printf("\n");
    
    printST(arvoreSt, TAM_MAX);     printf("\n");

    for ( i = 0; i < TAM_MAX; i++){
        printf("Mínimo intervalo %d - %d : %d\n", 0, i,   RMQ(arvoreSt, TAM_MAX, 0, i));
        printf("Mínimo intervalo %d - %d : %d\n", i, 2*i, RMQ(arvoreSt, TAM_MAX, i, 2*i));
    }

}

void printList(int *l){
    printf("\tLista: ");
    for ( int i = 0; i < TAM_MAX; i++)    printf("%d ", l[i]);
    printf("\n");
}
