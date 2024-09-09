#include "prototipos.h"

void inicia_pilha (pilha *p, int tamanho) {
    p->topo = 0;
    p->v = (int *) malloc (tamanho * sizeof(int));
    p->capacidade = tamanho;
}

int pilha_cheia (pilha *p) {
    if (p->topo == p->capacidade){
        return TRUE;
    } else {
        return FALSE;
    }   
}

int pilha_vazia (pilha *p) {
    if (p->topo == 0) {
        return TRUE;
    } else {
        return FALSE;
    }
}

void empilha (pilha *p, int num) {
    p->v[p->topo++] = num;  
}   

int desempilha (pilha *p) {
    return p->v[--p->topo];   
}

void mostra_pilha (pilha *p) {
    if (pilha_vazia(p) == TRUE) {
        printf("\nPilha Vazia\n");
    } else {
        for (int i = p->topo - 1; i >= 0 ; i--) {
            printf("%d\n", p->v[i]);
        }
        printf("\n");
    }
}

void libera_pilha (pilha *p) {
    free(p->v);
}