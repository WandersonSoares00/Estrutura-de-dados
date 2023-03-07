#include <stdlib.h>
#include <stdio.h>
#include "heap.h"

int main(int argc, char *argv){
    int i, j, n = 13;
    int heap[TAM_MAX];
    
    for( i = 0; i < n; i++){
        j = rand() % 20;
        heap[i] = j + (i * 3);
    }
    
    constroiMaxHeap(heap, n);
    
    for ( i = 0; i < n; i++)  printf(" %d ", heap[i]);
    printf("\n\n");

    printHeap(heap, 0, n, 0);

    printf("\n\n");

    return EXIT_SUCCESS;
}
