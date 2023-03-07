#include <stdio.h>
#include <stdlib.h>

void atualizaBIT(int *B, int n, int index, int val){
    index++;

    while (index <= n){
        B[index] += val;
        index += index & (-index);
    }
}

int *construirBIT(int *l, int n){
    int i;
    int *arv = (int *) calloc(n + 1, sizeof(int));
    if(arv == NULL)     return NULL;

    for ( i = 0; i < n; i++)
        atualizaBIT(arv, n, i, l[i]);
    return arv;
}

int soma(int *B, int interv_fim){
    int soma = 0;

    interv_fim++;

    while (interv_fim > 0){
        soma += B[interv_fim];
        interv_fim -= interv_fim & (- interv_fim);
    }

    return soma;
}

int main(int argc, char *argv){
    int i;
    int n = 10;
    int lista[10] = {3, 2, -1, 6, 5, 4, -3, 3, 7, 2};
    int *bit;

    bit = construirBIT(lista, n);

    printf("soma %d - %d : %d\n", 0, 4, soma(bit, 4));
    printf("soma %d - %d : %d\n", 0, 10, soma(bit, 10));

}
