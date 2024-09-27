#include "vetor.h"

//Implementação das funções auxiliares
void preenche_vetor(int *v, int t){
    for (int i = 0; i < t; i++){
        v[i] = rand() % (t * 10);
    }
}

void exibe_vetor(int *v, int t, char *msg) {
    printf("\n%s\n", msg);
    for (int i = 0; i < t; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
}

void soma_vetores (int *v1, int *v2, int *vs, int t){
    for (int i = 0; i < t; i++){
        vs[i] = v1[i] + v2[i];
    }
}

//Implementação de ordenação com algoritimo bubblesort
void bubblesort (int *v, int n) {
    for (int i = 1; i < n; i++) { //Número de vezes que foi feita
        for (int j = 0; j < n - i; j++){ //posição
            if (v[j] > v[j+1]) {
                int aux = v[j];
                v[j] = v[j+1];
                v[j+1] = aux; 
            }
        }
    }
}

//Implementação de ordenação com algoritimo insertionsort
void insertionsort(int *v, int n) {
    int i, j;
    for(i = 1; i < n; i++) { //Posições
        int x =v[i];
        for (j = i-1; j >= 0 && v[j] > x; j--) { //Posições
            v[j+1] = v[j];
        }
        v[j+1] = x;
    }
}

//Implementação de ordenação com algoritimo selectionsort
void selectionsort(int *v, int n) {
    for (int i = 0; i < n-1; i++) {
        int menor = i;
        for (int j = i+1; j < n; j++) {
            if (v[j] < v[menor]) {
                menor = j;
            }     
        }
        int x = v[i];
        v[i] = v[menor];
        v[menor] = x;  
    }
}

int partition(int *a, int pri, int ult, int *cont) {
   int x = a[ult];
   int i = pri-1;
   int j;
   for (j = pri; j < ult; j++) {
        (*cont)++;
        if (a[j] <= x) {
            i = i + 1;
            int aux =a[i];
            a[i] = a[j];
            a[j] = aux;
        }
    }
    i = i + 1;
    int aux = a[j];
    a[j] = a[i];
    a[i] = aux;
    return i;
}

void quicksort(int *v, int pri, int ult, int *cont) {
    (*cont)++;
    if (pri < ult){
        int q = partition (v, pri, ult, cont);
        quicksort (v, pri, q-1, cont);
        quicksort (v, q+1, ult, cont);
    }
    
}

int busca_simples (int *v, int x, int n, int *cont) {
    for (int i = 0; i < n; i++) {
        (*cont)++;
        if (x == v[i]) {
            return 1;
        }
    }
    return 0;
}

int busca_binaria (int *v, int x, int n, int *cont) {
    int ini = 0, fim = n -1;
    while (ini <= fim) {
        int meio = (ini + fim) / 2;
        (*cont)++;
        if (x == v[meio]) {
            return 1;
        }
        (*cont)++;
        if (x > v[meio]) {
            ini = meio + 1;
        } else fim = meio -1;
    }
    return 0;
}