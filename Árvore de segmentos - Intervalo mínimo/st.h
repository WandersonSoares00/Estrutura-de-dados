#ifndef ST_h
#define ST_h

#define CLRSCREAN       printf("\e[1;1H\e[2J");

int valMin(int a, int b);
int auxConstruirST(int *l, int **d, int no, int inic, int fim);
int *construirST(int *l, int tam);
int aux_RMQ(int *st, int no, int inic, int fim, int interv_inic, int interv_fim);
int RMQ(int *st, int tam, int interv_inic, int interv_fim);
void aux_printST(int *st, int no, int tam, int nivel);
void printST(int *st, int tam);

#endif