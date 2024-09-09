#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0

typedef
    struct {
        int *v;
        int topo;
        int capacidade;
    }
pilha;

void inicia_pilha(pilha *, int);
int pilha_cheia(pilha *);
int pilha_vazia(pilha *);
void empilha(pilha *, int);
int desempilha(pilha *);
void mostra_pilha(pilha *);
void libera_pilha(pilha *);