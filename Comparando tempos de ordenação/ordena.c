#include <stdlib.h>

static void troca(int *a, int *b){
    register int aux = *a;
    *a = *b;
    *b = aux;
}

static void quick_sortv1_aux(int *v, int inic, int fim){
    int pivo = v[inic];
    int esq = inic;
    int dir = fim;

    while( esq <= dir ){
        while ( v[esq] < pivo )     esq++; //Busca um elemento maior na sublista esquerda
        while ( v[dir] > pivo )     dir--; //Busca um elementa menor na sublista direita
        
        if ( esq <= dir){   //Verifica se a Busca foi bem sucedida
            troca(&v[esq], &v[dir]);
            esq++;
            dir--;
        }
    }
    
    if ( inic < dir )   quick_sortv1_aux(v, inic, dir); //Ordena sublista direita se ela existir
    if ( esq < fim )    quick_sortv1_aux(v,  esq, fim); //Ordena sublista esquerda se ela existir
}

void quick_sortv1(int *v, int tam){
    quick_sortv1_aux(v, 0, tam);
}

static int particao(int *v, int inic, int fim){
    int pivo = v[inic];
    int esq = inic;
    int dir = fim;

    while( esq < dir ){
        while( v[esq] <= pivo)     esq++; //Busca um elemento maior na sublista esquerda
        while( v[dir] > pivo)     dir--; //Busca um elementa menor na sublista direita
        
        if ( esq < dir)   //Se a Busca foi bem sucedida, precisa trocar
            troca(&v[esq], &v[dir]);
    }
    // esq > dir, i.e: dir é o último elemento da sublista esquerda v[inic ... dir ... fim]
    troca(&v[inic], &v[dir]);
    
    return dir;
}

static void quick_sortv2_aux(int *v, int inic, int fim){
    int p;
    if( inic < fim ){
        p = particao(v, inic, fim);
        quick_sortv2_aux(v, inic, p - 1);
        quick_sortv2_aux(v, p + 1, fim);
    }
}

void quick_sortv2(int *v, int tam){
    quick_sortv2_aux(v, 0, tam);
}

static int particaov2(int *v, int inic, int fim){
    int k, j, pivo;
    int i = inic - 1;
    //k no intervalo [0 ; fim - inic]
    k = (double) ((double) rand () / ((double) RAND_MAX + 1)) * (double)(fim - inic + 1);
    troca(&v[inic + k], &v[fim]); //Deixa o pivo aleatório
    pivo = v[fim];

    //empurra os valores maiores que o pivo, indicados por i, para sua direita 
    for ( j = inic; j < fim; j++){
        if (v[j] <= pivo ){
            i++;
            if(i != j)  troca(&v[i], &v[j]);
        }
    }
    // pivo na sua posição
    troca(&v[i + 1], &v[fim]);

    return i + 1; // retorna a posição do pivo
}

static void quick_sortv3_aux(int *v, int inic, int fim){
    if( inic < fim ){
        int p = particaov2(v, inic, fim);
        quick_sortv3_aux(v, inic, p - 1);
        quick_sortv3_aux(v, p + 1, fim);
    }
}

void quick_sortv3(int *v, int tam){
    quick_sortv3_aux(v, 0, tam - 1);
}

static void intercalacao(int *v, int inic, int meio, int fim){
    int i = inic, k = 0;
    int j = meio;
    int aux[fim - inic];

    while (i < meio && j < fim){
        if ( v[i] < v[j] )   aux[k] = v[i++];
        else                 aux[k] = v[j++];
        k++;
    }
    
    while (i < meio)    aux[k++] = v[i++];
    while (j < fim )    aux[k++] = v[j++];
    
    for(k = 0; k < fim - inic; k++)    v[inic + k] = aux[k];
}

//v[inic .. fim-1]
static void mergesort_aux(int *v, int inic, int fim){
    int meio;

    if(fim - inic > 1){
        meio = (inic + fim) / 2;
        mergesort_aux(v, inic, meio);
        mergesort_aux(v, meio, fim);
        intercalacao(v, inic, meio, fim);
    }
}

void mergesort(int *v, int tam){
    mergesort_aux(v, 0, tam);
}

void mergesort_interativo(int *v, int tam){
    int bloco = 1;
    int i, fim; // subvetor v[i .. fim-1]

    while( bloco < tam ){
        i = 0;
        while( i + bloco < tam ){
            fim = i + (2 * bloco);
            if ( fim > tam )
                fim = tam;
            intercalacao(v, i, i + bloco, fim);
            i = i + 2 * bloco;
        }
        bloco = 2 * bloco;
    }

}

void insertionSort(int *v, int tam){
    register int i, j;
    int aux;

    for( i = 1; i < tam; i++ ){
        aux = v[i];
        for( j = i; (j > 0) && (aux < v[j - 1]) ; j-- )
            v[j] = v[j - 1];
        if ( j < i )        v[j] = aux;
    }
}

#define filhoEsquerdo(i)    (2 * i) + 1
#define filhoDireito(i)     (2 * i) + 2

static void corrigeDescendo(int *h, int i, int n){
    int fesq = filhoEsquerdo(i);
    int fdir = filhoDireito(i);
    int maior = i;

    if( fesq < n && h[fesq] > h[maior] )
        maior = fesq;
    
    if( fdir < n && h[fdir] > h[maior]  )
        maior = fdir;

    if( maior != i ){
        troca(&h[maior], &h[i]);
        corrigeDescendo(h, maior, n);
    }
}

static void constroiMaxHeap(int *h, int n){
    int i;
    for ( i = n / 2 - 1; i >= 0; i--)
        corrigeDescendo(h, i, n);
}

void heapSort(int *v, int n){
    int i;
    
    constroiMaxHeap(v, n);

    for( i = n - 1; i >= 0; i--){
        troca(&v[0], &v[i]);
        corrigeDescendo(v, 0, i);
    }
}

