#include <stdio.h>
#define MAX 100000

//Método ingênuo
int maiorFreq(int *arr, int n){
    int i, resp, freq_atual, freq_max;
    int tab[MAX] = {0};

    //Armazena elementos pela frequência
    for ( i = 0; i < n; i++)
        tab[arr[i]]++;

    freq_max = 0;  resp = -1;

    for ( i = 0; i < MAX; i++){
        freq_atual = tab[i];

        if( freq_atual > freq_max ) {
            resp = i;
            freq_max = freq_atual;  }
    }

    return resp;
}

int main(){
    int vet[] = {12, 36, 7, 12, 10, 6, 8, 7, 14, 12, 7, 9, 7, 12, 12, 12, 12};
    
    printf("Elemento mais frequente eh %d", maiorFreq(vet, sizeof(vet)/sizeof(*vet)));

    return 0;
}
