#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>
#include "st.h"

int valMin(int a, int b){
    return a > b    ?   b   :   a;
}

int auxConstruirST(int *l, int **d, int no, int inic, int fim){
    if( inic == fim ){
        (*d)[no] = l[inic];
        return l[inic];
    }
    int meio = (inic + fim) / 2;
    (*d)[no] = valMin(auxConstruirST(l, d, 2 * no + 1, inic, meio), auxConstruirST(l, d, 2 * no + 2, meio + 1, fim));
    
    return (*d)[no];
} 

int *construirST(int *l, int tam){
    int h = (int) ceil(log2(tam));
    int qtdNos = 2 * (int) pow(2, h) - 1;
    int *arv = malloc(qtdNos * sizeof(int));
    if(arv == NULL)         return NULL;

    auxConstruirST(l, &arv, 0, 0, tam - 1);
    
    return arv;
}

int aux_RMQ(int *st, int no, int inic, int fim, int interv_inic, int interv_fim){
    if( interv_fim < inic || fim < interv_inic )
        return INT_MAX;
    if( interv_inic <= inic && interv_fim >= fim )
        return st[no];
    
    int meio = (inic + fim) / 2;
    return valMin(aux_RMQ(st, 2*no + 1, inic, meio, interv_inic, interv_fim),
           aux_RMQ(st, 2*no + 2, meio + 1, fim, interv_inic, interv_fim));
}

//Retorna valor mínimo do intervalo l[interv_inic ... interv_fim]
int RMQ(int *st, int tam, int interv_inic, int interv_fim){
    if( interv_inic < 0 || interv_fim >= tam || interv_inic > interv_fim )
        return - 1;
    return aux_RMQ(st, 0, 0, tam - 1, interv_inic, interv_fim);
}

void aux_printST(int *st, int no, int tam, int nivel){
    if( no >= 0 && no < tam ){
        aux_printST(st, 2 * no + 1, tam, nivel + 1);

        for (int i = 0; i < nivel; i++)
            printf("      ");
        
        printf("%d\n", st[no]);

        aux_printST(st, 2*no + 2, tam, nivel + 1);
    }
}

void printST(int *st, int tam){
    aux_printST(st, 0, tam, 0);
}
