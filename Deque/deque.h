#ifndef DEQUEE_h
#define DEQUEE_h

#define TAM_MAX 20

typedef struct{
    int vet[TAM_MAX];
    int frente, cauda;
}Deque;

void inicializaDeque(Deque **d);
int estaCheia(Deque *d);
int insereFrente(Deque **d, int k);
int insereFim(Deque **d, int k);
int deletaFrente(Deque **d);
int deletaFim(Deque **d);
void exibeDeque(Deque *d);

#endif