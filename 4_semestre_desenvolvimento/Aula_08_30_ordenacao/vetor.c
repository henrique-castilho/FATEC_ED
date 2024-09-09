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

//Implementação de ordenação com algoritimo insertionsort
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