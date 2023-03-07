#ifndef AVL_h
#define AVL_h

typedef struct avl{
    int dado;
    struct avl *esq, *dir;
    int altura;
}No;

#define MAX(a, b) a > b     ?  a  :  b
#define ALTURA(p) p == NULL ?  0  :  p -> altura
#define CLRSCREEN   printf("\e[1;1H\e[2J");

No *rotacionaDir(No *y);
No *rotacionaEsq(No *y);
int fatorBalanc(No *n);
No *balancear(No *raiz);
No *NovoNo(int chave);
No *inserir(No *raiz, int chave);
No *NoMinValor(No *a);
No *remover(No *raiz, int chave);
void printAVL(No *raiz, int nivel);

#endif