#ifndef ordena_h
#define ordena_h

static void troca(int *a, int *b);

static void quick_sortv1_aux(int *v, int inic, int fim);
void quick_sortv1(int *v, int tam);

static int particao(int *v, int inic, int fim);

static void quick_sortv2_aux(int *v, int inic, int fim);
void quick_sortv2(int *v, int tam);

static int particaov2(int *v, int inic, int fim);

static void quick_sortv3_aux(int *v, int inic, int fim);
void quick_sortv3(int *v, int tam);

static void intercalacao(int *v, int inic, int meio, int fim);

static void mergesort_aux(int *v, int inic, int fim);
void mergesort(int *v, int tam);

void mergesort_interativo(int *v, int tam);

void insertionSort(int *v, int tam);

static void corrigeDescendo(int *h, int i, int n);

static void constroiMaxHeap(int *h, int n);

void heapSort(int *v, int n);

#endif