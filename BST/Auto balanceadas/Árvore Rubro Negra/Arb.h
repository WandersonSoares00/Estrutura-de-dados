#ifndef ARB_h
#define ARB_h

#define outVERMELHO      "\033[31m"
#define outPRETO         "\033[30m"
#define outRESET         "\x1b[m"

typedef enum{
    VERMELHO,
    PRETO
}ARN_Cor;

typedef struct Arv_rb{
    struct Arv_rb *esq, *dir;
    int dado;
    ARN_Cor cor;
}No;

No *novoNo(int chave);
int vermelho(No *y);
void inverteCor(No **y);
void rotacEsq(No **A);
void rotacDir(No **A);
void concertarARB(No **raiz);
void aux_inserir(No **raiz, int chave);
void inserir(No **raiz, int chave);
void aux_printARB(No *raiz, int nivel);
void printARB(No *raiz);
void inOrder(No *raiz);

#endif