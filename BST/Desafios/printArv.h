#ifndef PRINTARV_h
#define PRINTARV_h
#include "fila.h"
#include "pilha.h"

void printArvoreInterativo(No *raiz);
No *maisDireita(No *raiz, No *restric);
void morrisTraversal(No *raiz);
void printPreOrdem(No *raiz);
void printInOrdem(No *raiz);
void printPosOrdem(No *raiz);
void printNoAtual(No *raiz, int nivel);
void printArvore(No *raiz);
void inOrderInter(No *raiz);
void preOrderInterativo(No *raiz);
void preOrderInterativo_v2(No *raiz);
void posOrderInteraitivo(No *raiz);

#endif