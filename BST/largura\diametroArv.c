#include <stdio.h>
#include <stdlib.h>
#define MAX(a, b) a > b ? a : b

typedef struct arv{
    int val;
    struct arv *esq, *dir;
}No;

void insercao(No **raiz, int k);
int altura(No *raiz);
int largura(No *raiz);

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
    
    diam = largura(raiz);
    printf("\t%d\n", diam);

    return 0;
}

void insercao(No **raiz, int k){
    No *aux, *q1, *q2;
    aux = (No *) malloc(sizeof(No));
    if(aux == NULL)
        return;
  
    aux -> val = k;
    aux -> esq = NULL;
    aux -> dir = NULL;

    q1 = q2 = *raiz;
    while( q1 != NULL ){
        q2 = q1;
        if( k > q1 -> val )
          q1 = q1 -> dir;
        else
          q1 = q1 -> esq;
    }

    if(q2 == NULL)
        *raiz = aux;
    else if(k > q2 -> val)
        q2 -> dir = aux;
    else 
        q2 -> esq = aux;
}

int altura(No *raiz){
    if( raiz == NULL )
        return 0;
    else{
        int e_altura = altura(raiz -> esq);
        int d_altura = altura(raiz -> dir);
        
        if( e_altura > d_altura )
            return (e_altura + 1);
        else
            return (d_altura + 1);
    }
}


int largura(No *raiz){
	/*Altura da subárvore direita e esquerda + raiz*/
	if( raiz == NULL )
		return 0;
	
	int e_alt = altura(raiz -> esq);
	int d_alt = altura(raiz -> dir);

	int e_larg = largura(raiz -> esq);
	int d_larg = largura(raiz -> dir);

	int larg = MAX(e_larg, d_larg);
    
    return MAX(e_alt + d_alt + 1, larg);
}
