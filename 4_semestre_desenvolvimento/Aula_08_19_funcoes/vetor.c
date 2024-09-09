#include "vetor.h"

//Implementação das funções auxiliares
void preenche_vetor(int *v, int t){
    for (int i = 0; i < t; i++){
        v[i] = rand() % (t * 10);
    }
}

void exibe_vetor(int *v, int t){
    printf("Os valores do vetor sao:\n");
    for (int i = 0; i < t; i++){
        printf("%d ", v[i]);
    }
}

void soma_vetores (int *v1, int *v2, int *vs, int t){
    for (int i = 0; i < t; i++){
        vs[i] = v1[i] + v2[i];
    }
    
}