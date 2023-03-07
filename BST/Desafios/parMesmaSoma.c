#include <stdlib.h>
#include <stdio.h>
#include "pilha.h"

int pesquisa(No *raiz, No *temp, int k){
    No *atual = raiz;

    while (atual != NULL){
        if( atual -> val == k && atual != temp ){
            printf("Par: %d + %d\n", atual -> val, temp -> val);
            return 1;
        }
        else if( k < atual -> val )
            atual = atual -> esq;
        else
            atual = atual -> dir;
    }
    
    return 0;
}

int existePar(No *raiz, No *temp, int k){
    if( temp == NULL )
        return 0;
    
    return pesquisa(raiz, temp, k - temp->val) \
            || existePar(raiz, temp -> esq, k) \
            || existePar(raiz, temp -> dir, k);
}

//SOLUÇÃO 2
int BSTVetor(No *raiz, int **vet, int i){
    if( raiz == NULL )
        return i;
    i = BSTVetor(raiz -> esq, vet, i);
    (*vet)[++i] = raiz -> val;
    i = BSTVetor(raiz -> dir, vet, i);
    return i;
}

int existeParUtil(No *raiz, int k, int qtdNos){
    int inic = 0, fim, encontrou = 0;
    int *lista = (int *) malloc(qtdNos * sizeof(int));

    fim = BSTVetor(raiz, &lista, inic - 1);

    while (inic < fim && !encontrou){
        if( lista[inic] + lista[fim] == k ){
            printf("Par: %d + %d\n", lista[inic], lista[fim]);
            encontrou = 1;
        }
        else if( lista[inic] + lista[fim] > k )
            fim--;
        else
            inic++;
    }

    free(lista);

    if(encontrou)         return 1;
    else                  return 0;
}

int existePar_v2(No *raiz, int k){
    int h, i, qtdNo = 1;
    h = altura(raiz);
    // 2 ^(h) - 1
    for ( i = 0; i < h; i++)
        qtdNo = 2 * qtdNo;
    qtdNo--;

    return existeParUtil(raiz, k, qtdNo);
}

//SOLUÇÃO 3
int existePar_v3(No *raiz, int k){
    struct fNo *pilha1 = NULL, *pilha2 = NULL;
    int val1, val2, feito1, feito2;
    No *atual1, *atual2;

    if(raiz == NULL)    return 0;

    feito1 = feito2 = 0;
    atual1 = atual2 = raiz;
    
    while (1){
        //Travesia In Order interativa
        while (!feito1){
            if( atual1 != NULL ){
                empilhar(&pilha1, atual1);
                atual1 = atual1 -> esq;
            }
            else if( !pilhaVazia(pilha1) ){
                atual1 = desempilhar(&pilha1);
                val1 = atual1 -> val;
                atual1 = atual1 -> dir;
                feito1 = 1;
            }
            else
                feito1 = 1;
        }
        //Travesia In Order Reversa interativa
        while (!feito2){
            if( atual2 != NULL ){
                empilhar(&pilha2, atual2);
                atual2 = atual2 -> dir;
            }
            else if( !pilhaVazia(pilha2) ){
                atual2 = desempilhar(&pilha2);
                val2 = atual2 -> val;
                atual2 = atual2 -> esq;
                feito2 = 1;
            }
            else
                feito2 = 1;
        }

        if( (val1 != val2) && (val1 + val2 == k) ){
            printf("Par: %d + %d\n", val1, val2);
            return 1;
        }
        
        else if( (val1 != val2) && (val1 + val2 > k) )
            feito2 = 0; //Continua travessia in Order reversa
        
        else if( (val1 != val2) && (val1 + val2 < k) )
            feito1 = 0; //Continua travessia in Order
        
        if( val1 >= val2 ) // Primeira traversia ultrapassou ou atingiu a segunda
            return 0;
    }
    
}

int main(int argc, char *argv){
    No *raiz;
    int i;

    /*
            30
           /  \
          20  80
         /   /  \
        10  60  90
    */
    insercao(&raiz, 30); insercao(&raiz, 80); insercao(&raiz, 20);
    insercao(&raiz, 90); insercao(&raiz, 60); insercao(&raiz, 10);    

    if( !existePar_v3(raiz, 120))
        printf("Nao existe par com soma %d\n", 100);

    if( !existePar_v3(raiz, 47))
        printf("Nao existe par com soma %d\n", 47);

    return EXIT_SUCCESS;
}
