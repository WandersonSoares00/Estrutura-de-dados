#ifndef utilid_h
#define utilid_h

long tempoOrdenar(void (*func)(int *, int), int *v, int tam);

long tempoRotina_qs(void *base, size_t nitems, size_t size, int (*compar)(const void *, const void*));

long tempoRotina(void (*func)(int *, int), int *p1, int p2);

void aleatoriza(int *v, int tam);

int compara(const void * a, const void * b);

void printvet(int *v, int tam);

void copia(int *a, int *b, int tam);

int ordenado(int *v, int tam);

#endif