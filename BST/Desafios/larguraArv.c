#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

int larguraPorNiv(No *raiz, int k);
int larguraMax(No *raiz);
int larguraMax_inter(No *raiz);
int inicializa(int *vet, int tam);
int maxVet(int *v, int tam);
void largMaxRec(No *raiz, int *cont, int nivel);
int obterLargMaxRec(No *raiz);

int main(){
    No *raiz;
    int diam;
    /*
            30
           /  \
          20  80
         /   /  \
        10  60  90
    */
    insercao(&raiz, 30); insercao(&raiz, 80); insercao(&raiz, 20);
    insercao(&raiz, 90); insercao(&raiz, 60); insercao(&raiz, 10);
    
    diam = larguraMax(raiz);
    printf("\t%d\n", diam);
    diam = larguraMax_inter(raiz);
    printf("\t%d\n", diam);

    insercao(&raiz, 25);

    diam = obterLargMaxRec(raiz);
    printf("\t%d\n", diam);

    return 0;
}


//SOLUÇÃO 1
int larguraPorNiv(No *raiz, int k){
	if( raiz == NULL )
		return 0;
	if( k == 1 )
        return 1;    
    return larguraPorNiv(raiz -> esq, k - 1) + larguraPorNiv(raiz -> dir, k - 1);
}

int larguraMax(No *raiz){
    int i, larg, lmax = 0;
    int h = altura(raiz);

    for ( i = 0; i <= h; i++){
        larg = larguraPorNiv(raiz, i);
        if( larg > lmax )
            lmax = larg;
    }
    
    return lmax;
}

//SOLUÇÃO 2
int larguraMax_inter(No *raiz){
    int larg, lmax, inic, fim;
    No *atual;
    No **fila = criaFila(&inic, &fim);

    if( raiz == NULL )  return 0;

    enfileirar(fila, &fim, raiz);
    lmax = 1;
    while (!fvazia(inic, fim)){
        larg = filaTamanho(inic, fim);
        if( larg > lmax )
            lmax = larg;
        //Enfileira todos os filhos de cada nível da árvore
        while (larg--){
            atual = desenfileirar(fila, &inic);

            if(atual -> esq != NULL)
                enfileirar(fila, &fim, atual -> esq);
            if(atual -> dir != NULL)
                enfileirar(fila, &fim, atual -> dir);
        }
        
    }
    free(fila);

    return lmax;
}

//SOLUÇÃO 3
int inicializa(int *vet, int tam){
    int i;
    for (i = 0; i < tam; i++)
        *(vet + i) = 0;
}

int maxVet(int *v, int tam){
    int i, max = *v;
    for( i = 1; i < tam; i++)
        if( *(v + i) > max )
            max = *(v + i);
    return max;   
}

void largMaxRec(No *raiz, int *cont, int nivel){
    if( raiz != NULL ){
        cont[nivel]++;
        largMaxRec(raiz -> esq, cont, nivel + 1);
        largMaxRec(raiz -> dir, cont, nivel + 1);
    }
}

int obterLargMaxRec(No *raiz){
    int nivel = 0;
    int h = altura(raiz);
    int cont_no[h]; //Vetor com a quantidade de nós de cada nível

    inicializa(cont_no, h);

    largMaxRec(raiz, cont_no, nivel);

    return maxVet(cont_no, h);
}

