#include "pilha.h"

void inicia_pilha(pilha *p, int tamanho) {
    p->topo = 0;
    p->v = (char *) malloc (tamanho * sizeof(char));
    p->capacidade = tamanho;
}

int pilha_cheia(pilha *p) {
    if (p->topo == p->capacidade) {
        return TRUE;
    } else {
        return FALSE;
    }
}

int pilha_vazia(pilha *p) {
    if (p->topo == 0 ){
        return TRUE;
    } else {
        return FALSE;
    }
}

//EMPILHA
void push (char c, pilha *p) {
    p->v[p->topo++] = c;
    //p->topo++;
}

//DESEMPILHA
char pop(pilha *p){
    //p->topo--;
    return p->v[--p->topo];
}

void mostra_pilha (pilha *p){
    if (pilha_vazia(p)==TRUE){
        printf("Pilha Vazia");
    } else {
        for (int i = p->topo - 1; i>=0; i--) {
            printf("%c\n", p->v[i]);
        }
    }
    printf("-------------\n");
}