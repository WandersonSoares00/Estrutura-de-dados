#include <stdio.h>
#define MAX 100000

//Método ingênuo
int par(int *l, int tam, int soma){
    int i, aux;
    int tab[MAX] = {0};

    for (int i = 0; i < tam; i++){
        aux = soma - l[i];
        if( tab[aux] == 1 ) //aux + l[i] = soma
            return 1;
        else
            tab[l[i]] = 1;
    }

    return 0;
}

int main(){
    int vet[] = {9, 36, 7, 12, 10, 6};
    
    if(par(vet, sizeof(vet)/sizeof(*vet), 15) )     printf("Existe par com soma %d\n", 15);
    else                                            printf("Nao existe par com soma %d\n", 15);

    if(par(vet, sizeof(vet)/sizeof(*vet), 12) )     printf("Existe par com soma %d\n", 12);
    else                                            printf("Nao existe par com soma %d\n", 12);
}
