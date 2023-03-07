#include <stdio.h>
#define MAX 100000

//Método ingênuo
void remover(int *h, int chave)     {  h[chave] = 0;    }
void inseir(int *h, int chave)      {  h[chave] = 1;    }
int busca(int *h, int chave)        {  return h[chave]; }

int buscaChaveDupK(int *arr, int n, int k){
    int i;
    int tab[MAX] = {0};

    for ( i = 0; i < n; i++){
        if( arr[i] < 0 )        return -1;
        if( busca(tab, arr[i]) )
            return 1;
        else
            inseir(tab, arr[i]);
        if( i >= k )
            remover(tab, arr[i - k]);
    }

    return 0;
}

int main(){
    int vet[] = {12, 36, 7, 12, 10, 6};
    
    if(buscaChaveDupK(vet, sizeof(vet)/sizeof(*vet), 2) )     printf("Existe elemento duplicado com distancia %d\n", 2);
    else                                                      printf("Nao existe elemento duplicado com distancia %d\n", 2);

    if(buscaChaveDupK(vet, sizeof(vet)/sizeof(*vet), 3) )    printf("Existe elemento duplicado com distancia %d\n", 3);
    else                                                      printf("Nao existe elemento duplicado com distancia %d\n", 3);

    return 0;
}
