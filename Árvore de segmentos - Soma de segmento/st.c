#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void auxConstruirST(int *l, int **d, int no, int inic, int fim){
    if( inic == fim ){
        (*d)[no] = l[inic];
        return;
    }
    int meio = (inic + fim) / 2;
    auxConstruirST(l, d, 2 * no, inic, meio);
    auxConstruirST(l, d, 2 * no + 1, meio + 1, fim);
    (*d)[no] = (*d)[2*no] + (*d)[2*no + 1];
}

int *construirST(int *l, int tam){
    int h = (int) ceil(log2(tam));
    int qtdNos = 2 * (int) pow(2, h) - 1;
    int *arv = malloc(qtdNos * sizeof(int));
    if(arv == NULL)         return NULL;

    auxConstruirST(l, &arv, 1, 0, tam - 1);
    
    return arv;
}

int aux_somaIntervalo(int *st, int no, int inic, int fim, int interv_inic, int interv_fim){
    if( interv_fim < inic || fim < interv_inic )
        return 0;
    if( interv_inic <= inic && interv_fim >= fim )
        return st[no];
    int meio = (inic + fim) / 2;
    return aux_somaIntervalo(st, 2*no, inic, meio, interv_inic, interv_fim) + \
           aux_somaIntervalo(st, 2*no + 1, meio + 1, fim, interv_inic, interv_fim);
}

int somaIntervalo(int *st, int tam, int interv_inic, int interv_fim){
    if( interv_inic < 0 || interv_fim >= tam || interv_inic > interv_fim )
        return - 1;
    return aux_somaIntervalo(st, 1, 0, tam - 1, interv_inic, interv_fim);
}

void aux_atualizarChave(int *st, int no, int inic, int fim, int i, int dif){
    if( i < inic || i > fim )
        return;
    else
        st[no] = st[no] + dif;
    if( inic != fim ){
        int meio = (inic + fim) / 2;
        aux_somaIntervalo(st, 2*no, inic, meio, i, dif);
        aux_somaIntervalo(st, 2*no + 1, meio + 1, fim, i, dif);
    }
}

void atualizarChave(int *arr, int *st, int tam, int i, int novo_valor){
    int dif;
    if( i < 0 || i >= tam )
        return;
    
    dif = novo_valor - arr[i];
    arr[i] = novo_valor;
    
    aux_atualizarChave(st, 1, 0, tam - 1, i, dif);
}

void aux_printST(int *st, int no, int tam, int nivel){
    if( no > 0 && no < tam ){
        aux_printST(st, 2 * no, tam, nivel + 1);

        for (int i = 0; i < nivel; i++)
            printf("      ");
        
        printf("%d\n", st[no]);

        aux_printST(st, 2*no + 1, tam, nivel + 1);
    }
}

void printST(int *st, int tam){
    aux_printST(st, 1, tam, 0);
}

