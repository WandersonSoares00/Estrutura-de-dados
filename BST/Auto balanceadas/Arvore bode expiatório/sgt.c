#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "sgt.h"

static int const log32(int n){
    double const log23 = 2.4663034623764317;
    return (int) ceil(log23 * log(n));
}

void inicializar(sgt *A){
    A -> raiz = NULL;
    A -> qtdNos = 0;
}

int armazenaArray(No *raiz, No **arr, int index){
    if( raiz == NULL )
        return index;
    index = armazenaArray(raiz -> esq, arr, index);
    arr[index++] = raiz;
    return armazenaArray(raiz -> dir, arr, index);
}

int ArvTamanho(No *raiz){
    if( raiz == NULL )      return 0;
    else                    return ArvTamanho(raiz -> esq) + ArvTamanho(raiz -> dir) + 1;
}

int inserirEbuscarAltura(sgt *arv, No **novo){
    No *temp, *r;
    int altura = 0;
    r = temp = arv -> raiz;

    if( r == NULL ){
        arv -> raiz = *novo;
        (arv -> qtdNos)++;
        return altura;
    }
    
    while (temp != NULL){
        r = temp;
        if( (*novo) -> dado < temp -> dado )           temp = temp -> esq;
        else if( (*novo) -> dado > temp -> dado )      temp = temp -> dir; 
        else                                        return -1;
        altura++;
    }
    
    if( (*novo) -> dado < r -> dado )    r -> esq = *novo;
    else                                 r -> dir = *novo;
    
    (arv -> qtdNos)++;
    return altura;
}

No *arrayArv(No **arr, int inic, int fim){
    if( inic > fim )
        return NULL;
    int meio = (inic + fim) / 2;
    No *raiz = arr[meio];

    raiz -> esq = arrayArv(arr, inic, meio - 1);
    raiz -> dir = arrayArv(arr, meio + 1, fim);
    return raiz;
}

void refazArv(No **pai, No *filho){
    No **lista;
    int n = ArvTamanho(filho);

    lista = malloc(n * sizeof(No));
    armazenaArray(filho, lista, 0);

    if( *pai == NULL )
        (*pai) = arrayArv(lista, 0, n - 1);
    else if( (*pai) -> esq == filho)
        (*pai) -> esq = arrayArv(lista, 0, n - 1);
    else
        (*pai) -> dir = arrayArv(lista, 0, n - 1);
}


int inserir(sgt *arv, int chave){
    No *pai, *filho, *novo;
    int h;
    
    novo = (No *) malloc(sizeof(No));
    novo -> dado = chave;
    novo -> esq = NULL;
    novo -> dir = NULL;

    h = inserirEbuscarAltura(arv, &novo);
    
    pai = NULL;
    filho = arv -> raiz;

    if(h > log32(arv -> qtdNos)){
        //Busca o no como bode expiatório
        do{
            pai = filho;
            if( novo -> dado < pai -> dado )               filho = pai -> esq;
            else                                           filho = pai -> dir;
        } while (3 * ArvTamanho(filho) <= 2 * ArvTamanho(pai) );
    
        refazArv(&pai, filho);
    }

    return h >= 0;
}

void aux_printSGT(No *raiz, int nivel){
    if( raiz != NULL ){
        aux_printSGT(raiz -> esq, nivel + 1);

        for (int i = 0; i < nivel; i++)
            printf("     ");
        printf("%d\n", raiz -> dado);

        aux_printSGT(raiz -> dir, nivel + 1);
    }
}

void printSGT(sgt *arv){
    aux_printSGT(arv -> raiz, 0);
}
