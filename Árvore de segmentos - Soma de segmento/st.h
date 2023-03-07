#ifndef ST_h
#define ST_h

#define CLRSCREAN       printf("\e[1;1H\e[2J");

void auxConstruirST(int *l, int **d, int no, int inic, int fim);
int *construirST(int *l, int tam);
int aux_somaIntervalo(int *st, int no, int inic, int fim, int interv_inic, int interv_fim);
int somaIntervalo(int *st, int tam, int interv_inic, int interv_fim);
void aux_printST(int *st, int no, int tam, int nivel);
void printST(int *st, int tam);
void aux_atualizarChave(int *st, int no, int inic, int fim, int i, int dif);
void atualizarChave(int *arr, int *st, int tam, int i, int novo_valor);

#endif