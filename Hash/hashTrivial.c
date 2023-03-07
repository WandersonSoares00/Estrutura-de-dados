#include <stdio.h>
#include <stdlib.h>
#define TAM_MAX     100

int inserir(int ***h, int chave){
    if( (*h) == NULL ){
        (*h) = (int **) calloc(TAM_MAX + 1, sizeof(int *));
        for (int i = 0; i < TAM_MAX + 1; i++)
            (*h)[i] = (int *) calloc(2, sizeof(int));
    }
    if( abs(chave) > TAM_MAX )                return 0;
    if( chave >= 0 ){
        if ( (*h)[chave][0] == 1 )          return 0;
        (*h)[chave][0] = 1;
    }
    else{
        if ( (*h)[abs(chave)][0] == 1 )     return 0;
        (*h)[abs(chave)][1] = 1;
    }

    return 1;
}

int busca(int **h, int k){
    if( abs(k) > TAM_MAX || h == NULL)          return 0;
    if( k >= 0 )
        if( h[k][0] )               return 1;
        else                        return 0;
    else
        if( h[abs(k)][1] )          return 1;
        else                        return 0;
}

void printHash(int **h){
    for (register int i = 0; i < TAM_MAX; i++){
        if( h[i][0] )       printf("%d ", i);
        if( h[i][1] )       printf("%d ", -1 * i);
    }
}

int main(int argc, char *argv){
    int **TabHash;
    int i, x;

    for (int i = 1; i <= 15; i++){
        x = (int) (rand() % (i*i));
        printf("%d ", x);
        printf(inserir(&TabHash, x)   ?   "inserido\n"   :  "nao inserido\n");
    }
    
    printHash(TabHash);

    return EXIT_SUCCESS;
}
