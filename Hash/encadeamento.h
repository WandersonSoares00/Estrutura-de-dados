#ifndef ENCADEAMENTO_h
#define ENCADEAMENTO_h

#define M   100
#define Hash(chave)     chave % M

typedef struct LL{
    int dado;
    struct LL *prox;
}No;

void HTincializar(No ***tab);
No *addFim(No *q, int chave);
void HTinserir(No ***tab, int chave);
void printList(No *q);
void printHash(No **tab);
void HTprint(No **tab);

#endif