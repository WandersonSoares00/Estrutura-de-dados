#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <sys/time.h>
#include <time.h>


long tempoRotina_qs(void *base, size_t nitems, size_t size, int (*compar)(const void *, const void*)){
    long segs, milisegs;
    struct timeval inic, fim;

    gettimeofday(&inic, NULL);
    qsort(base, nitems, size, compar);
    gettimeofday(&fim, NULL);

    segs = (fim.tv_sec - inic.tv_sec);
    milisegs = (((segs * 1000000) + fim.tv_usec) - inic.tv_usec);

    return milisegs;
}

long tempoRotina(void (*func)(int *, int), int *p1, int p2){
    long segs, milisegs;
    struct timeval inic, fim;

    gettimeofday(&inic, NULL);
    func(p1, p2);
    gettimeofday(&fim, NULL);

    segs = (fim.tv_sec - inic.tv_sec);
    milisegs = (((segs * 1000000) + fim.tv_usec) - inic.tv_usec);

    return milisegs;
}

void copia(int *a, int *b, int tam){
    register int i;
    for ( i = 0; i < tam; i++)
        *(a + i) = *(b + i);   
}

int ordenado(int *v, int tam){
    register int i;
    
    for ( i = 1; i < tam; i++){
        if( v[i - 1] > v[i] )
            return 0;
    }
    return 1;
}

long tempoOrdenar(void (*func)(int *, int), int *v, int tam){
    int vaux[tam];
    long t;
    
    copia(vaux, v, tam);
    t = tempoRotina(func, v, tam);
    copia(v, vaux, tam);
    
    return t;
}

void aleatoriza(int *v, int tam){
    int i;
    srand(time(NULL));

    for ( i = 0; i < tam; i++)
        v[i] = rand() % tam;
    
}

int compara(const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

void printvet(int *v, int tam){
    register int i;

    for (i = 0; i < tam; i++)
        printf("-- %d ", *(v + i));
}

