#include <stdlib.h>
#include <stdio.h>

struct No{
    int dado;
    struct No *ant;
    struct No *prox;
};

void preOrder(struct No *head);
void push(struct No** head, int k);
void printList(struct No *no);
int contaNos(struct No *head);

//SOLUÇÃO 1

struct No **listaVetor(struct No *head, int tam){
    int i;
    struct No **v = (struct No **) malloc(tam * sizeof(struct No));
    
    for( i = 0; head != NULL; i++){
        v[i] = head;
        head = head -> prox;
    }
    
    return v;
}

struct No *listaBSTRec_v1(struct No **v, int inic, int fim){
    if( inic > fim )
        return NULL;
    
    int meio = (inic + fim) / 2;

    struct No *raiz = v[meio];

    raiz -> ant = listaBSTRec_v1(v, inic, meio - 1);
    raiz -> prox = listaBSTRec_v1(v, meio + 1, fim);

    return raiz;
}

struct No *listaBST_v1(struct No *inicio){
    int qtd;
    struct No **vet;
    qtd = contaNos(inicio);
    vet = listaVetor(inicio, qtd);

    return listaBSTRec_v1(vet, 0, qtd - 1);
}

//SOLUÇÃO 2
struct No *listaBSTRec_v2(struct No **head, int n){
    if( n <= 0 )
        return NULL;
    
    struct No *esq = listaBSTRec_v2(head, n / 2);

    struct No *raiz = *head;

    raiz -> ant = esq;

    *head = (*head) -> prox;

    raiz -> prox = listaBSTRec_v2(head, n - (n/2) - 1);

    return raiz;
}

struct No *listaBST_v2(struct No *inicio){
    int n;
    
    n = contaNos(inicio);

    return listaBSTRec_v2(&inicio, n);
}

int main(int argc, char *argv){
    struct No *raiz1 = NULL;
    struct No *raiz2 = NULL;
    int i;

    for( i = 20; i > 0; i--){
        push(&raiz1, i);
        push(&raiz2, i);
    }
    
    printList(raiz1);    printf("\n\n");

    raiz1 = listaBST_v1(raiz1);
    printf("Arvore raiz1 :  ");  preOrder(raiz1);

    raiz2 = listaBST_v2(raiz2);
    printf("\nArvore raiz2 :  ");  preOrder(raiz2);

    return EXIT_SUCCESS;
}

void preOrder(struct No *head){
    if( head == NULL )
        return;
    preOrder(head -> ant);
    printf(" %d ", head -> dado);
    preOrder(head -> prox);
}

int contaNos(struct No *head){
    int cont = 0;

    while(head){
        head = head -> prox;
        cont++;
    }

    return cont;
}

void printList(struct No *no){
    while ( no != NULL ){
        printf("%d ", no -> dado);
        no = no -> prox;
    }
}

void push(struct No** head, int k){
    struct No* novo  = (struct No*) malloc(sizeof(struct No));
 
    novo -> dado = k;
 
    novo -> ant = NULL;
 
    novo -> prox = (*head);
 
    if((*head) !=  NULL)
        (*head) -> ant = novo;
 
    (*head) = novo;
}

