#include "vetor.h"

void gera_vetor (int v [], int t, int l) {
    int i;
    for (i = 0; i < t; i++){
        v[i] = rand() % l;
    }
    
}
void mostra_vetor (int v[], int t, char *msg){
    int i;
    printf("\n%s\n", msg);
    for (i = 0; i < t; i++){
        printf("%d ", v[i]);
    }
    printf("\n");
}

void selection_sort (int v[], int t){
    int i, j, pos_menor, aux;
    for (i = 0; i < t - 1 ; i++){
        pos_menor = i;
        for(j=i+1; j < t; j++) {
            if (v[j] < v[pos_menor]){
                pos_menor = j;
            }
        }
        aux = v[pos_menor];
        v[pos_menor] = v[i];
        v[i] = aux;
    }
}

void insertionsort (int v[], int t)
{
   for (int j = 1; j < t; ++j) {
      int x = v[j];
      int i;
      for (i = j-1; i >= 0 && v[i] > x; --i)
         v[i+1] = v[i];
      v[i+1] = x;
   }
}

int busca_simples (int v[], int t, int x, int *cont){
    *cont = 0;
    for ( int i = 0; i < t; i++){
        *cont = *cont + 1;
        if (v[i] == x){
            return 1;
        }     
    }
return 0;
}

int busca_binaria (int v[], int t, int x, int *cont){
    int inicio = 0, fim = t-1, meio;
    *cont = 0;
    while (inicio <= fim){
        ++*cont;
        meio = (inicio + fim) / 2;
        if (x == v[meio])return meio;
        if (x > v [meio]) inicio = meio + 1;
        else fim = meio -1;      
    }
    return -1 ;
}