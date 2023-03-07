#include <stdio.h>
#include <stdlib.h>
#include "arvBin.h"
#include "fila.h"

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


int alturaInterativo(No *raiz){
    No *atual;
    int altura = 0;
    int cont_no, inicio, fim;

    No **fila = criaFila(&inicio, &fim);
    enfileirar(fila, &fim, raiz);

    //Conta todos os níveis da árvore
    while (!fvazia(inicio, fim)){
        altura++;
        cont_no = filaTamanho(inicio, fim);
        //Enfileira todos os nós (dados por cont_no) de cada nível da árvore
        while (cont_no--){
            atual = desenfileirar(fila, &inicio);

            if(atual -> esq != NULL)
                enfileirar(fila, &fim, atual -> esq);
            if(atual -> dir != NULL)
                enfileirar(fila, &fim, atual -> dir);
        }
    }
    return altura;
}

int main(){
    No *raiz;
    /*
            30
           /  \
          20  80
         /   /  \
        10  60  90
    */
    insercao(&raiz, 30); insercao(&raiz, 80); insercao(&raiz, 20);
    insercao(&raiz, 90); insercao(&raiz, 60); insercao(&raiz, 10);
    
    printArvore(raiz);
    printf("\nAltura: %d", alturaInterativo(raiz));
    
    insercao(&raiz, 100);
    printf("\nNova altura: %d\n\n", alturaInterativo(raiz));
    
    return 0;
}

