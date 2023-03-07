#include <stdio.h>
#include <stdlib.h>
#include "avl.h"


No *rotacionaDir(No *y){
    int hesq, hdir;
    No *X = y -> esq;
    No *A2 = X -> dir;
    /*      y                   X  
           / \                 / \
          X   yd   ---->      Xe  y
         / \                     / \
        Xe  A2                 A2   yd
    */
    X -> dir = y;
    y -> esq = A2;

    hesq = ALTURA(y -> esq);    hdir = ALTURA(y -> dir);
    y -> altura = MAX(hesq, hdir) + 1;
    
    hesq = ALTURA(X -> esq);    hdir = ALTURA(X -> dir);
    X -> altura = MAX(hesq, hdir) + 1;

    return X;
}

No *rotacionaEsq(No *y){
    int hesq, hdir;
    No *X = y -> dir;
    No *A2 = X -> esq;
    /*      y                   X  
           / \                 / \
         ye   X   ---->       y  Xd
             / \             / \  
            A2 Xd           ye  A2 
    */
    X -> esq = y;
    y -> dir = A2;

    hesq = ALTURA(y -> esq);    hdir = ALTURA(y -> dir);
    y -> altura = MAX(hesq, hdir) + 1;

    hesq = ALTURA(X -> esq);    hdir = ALTURA(X -> dir);
    X -> altura = MAX(hesq, hdir) + 1;

    return X;
}

int fatorBalanc(No *n){
    if( n == NULL )     return 0;
    else                return ((ALTURA(n -> esq)) - (ALTURA(n -> dir)));
}

No *balancear(No *raiz){
    int balanc = fatorBalanc(raiz);

    // reta esquerda ou joelho do lado esquerdo
    if( balanc > 1 ){ 
        if( fatorBalanc( raiz -> dir) >= 0 ) // Reta
            return rotacionaDir(raiz);
        else{   // RDD
            raiz -> esq = rotacionaEsq(raiz -> esq);
            return rotacionaDir(raiz);      }
    }
    else if( balanc < -1){  // reta direita ou joelho do lado direito
        if( fatorBalanc( raiz -> dir) <= 0 ) // Reta
            return rotacionaEsq(raiz);
        else{   //RDE
            raiz -> dir = rotacionaDir(raiz -> dir);
            return rotacionaEsq(raiz);
        }
    }
    
    return raiz;
}

No *NovoNo(int chave){
    No *temp = (No *) malloc(sizeof(No));
    temp -> dado = chave;
    temp -> altura = 0;
    temp -> esq = NULL;
    temp -> dir = NULL;
    return temp;
}

No *inserir(No *raiz, int chave){
    if( raiz == NULL )
        return NovoNo(chave);
    if( chave < raiz -> dado )
        raiz -> esq = inserir(raiz -> esq, chave );
    else if( chave > raiz -> dado )
        raiz -> dir = inserir(raiz -> dir, chave );
    else
        return raiz;
    
    raiz -> altura = MAX((ALTURA(raiz -> esq)), (ALTURA(raiz -> dir))) + 1;

    raiz = balancear(raiz);

    return raiz;
}

No *NoMinValor(No *a){
    while (a -> esq != NULL)   a = a -> esq;
    return a;
}

No *remover(No *raiz, int chave){
    if(raiz == NULL )
        return NULL;
    else if( chave < raiz -> dado )
        raiz -> esq = remover(raiz -> esq, chave);
    else if( chave > raiz -> dado )
        raiz -> dir = remover(raiz -> dir, chave);
    else{ // busca bem sucedida
        if( raiz -> esq == NULL && raiz -> dir == NULL){
            free(raiz);
            return NULL;
        }
        else if( raiz -> esq != NULL && raiz -> dir != NULL){
            No *temp = NoMinValor(raiz -> dir);
            raiz -> dado = temp -> dado;
            temp -> dado = chave;  
            raiz -> dir = remover(raiz -> dir, chave);
            return raiz;
        }
        else{ //Apenas um filho
            No *temp;
            if(raiz -> esq == NULL )    temp = raiz -> dir;
            else                        temp = raiz -> esq;
            free(raiz);
            return temp;
        }
    }
    if( raiz == NULL) return NULL;

    raiz -> altura = MAX((ALTURA(raiz -> esq)), (ALTURA(raiz -> dir))) + 1;

    raiz = balancear(raiz);

    return raiz;
}

/*
No *remover(No *raiz, int chave){
    if( raiz == NULL )
        return NULL;
    else if( chave < raiz -> dado )
        raiz -> esq = remover(raiz -> esq, chave);
    else if( chave > raiz -> dado )
        raiz -> dir = remover(raiz -> dir, chave);
    else{ // busca bem sucedida
        if( raiz -> esq == NULL || raiz -> dir == NULL){
            No *temp;
            if(raiz -> esq == NULL )    temp = raiz -> dir;
            else                        temp = raiz -> esq;

            if( temp == NULL ){ // Folha
                temp = raiz; 
                raiz = NULL;  }
            else
                *raiz = *temp;
            
            free(temp);
        }
        else{ // raiz com dois filhos
            No *temp = NoMinValor(raiz -> dir);
            raiz -> dado = temp -> dado;
            raiz -> dir = remover(raiz -> dir, chave);
        }
    }
    /
    if( raiz == NULL )      return NULL;

    raiz -> altura = MAX((ALTURA(raiz -> esq)), (ALTURA(raiz -> dir))) + 1;

    raiz = balancear(raiz);
    /

    return raiz;
}
*/
void printAVL(No *raiz, int nivel){
	if( raiz != NULL ) { 
		printAVL(raiz -> esq, nivel + 1);
		
        for(int i = 0; i < nivel; i++)  
			printf("      "); 
		printf("%d\n", raiz -> dado ); 
		
        printAVL(raiz -> dir, nivel + 1);
	}
}
