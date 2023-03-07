#ifndef     SGT_h
#define     SGT_h

typedef struct BST{
    int dado;
    struct BST *esq, *dir;
}No;

typedef struct{
    No *raiz;
    int qtdNos;
}sgt;

#define CLRSCREAN       printf("\e[1;1H\e[2J");

static int const log32(int n);
void inicializar(sgt *A);
int armazenaArray(No *raiz, No **arr, int index);
int ArvTamanho(No *raiz);
int inserirEbuscarAltura(sgt *arv, No **novo);
No *arrayArv(No **arr, int inic, int fim);
void refazArv(No **pai, No *filho);
int inserir(sgt *arv, int chave);
void aux_printARB(No *raiz, int nivel);
void printSGT(sgt *arv);

#endif