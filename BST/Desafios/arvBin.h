#ifndef ARV_h
#define ARV_H

typedef struct arv{
    int val;
    struct arv *esq, *dir;
}No;

void insercao(No **raiz, int k);
No *novoNo(int k);
int altura(No *raiz);

#endif