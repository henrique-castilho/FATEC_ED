#include "no_duplo.h"

typedef struct fila {
    t_no_duplo * primeiro;
    t_no_duplo * ultimo;
    int num_nos;
} t_fila;

void inicia_fila(t_fila *);
int fila_vazia(t_fila *);
void enfileira(t_fila *, int); //Insere no fim
void exibe_fila(t_fila *, char *);
int desenfileira(t_fila *); //remove no inicio

//Exercício
void exibe_primeiro(t_fila *);
void exibe_ultimo(t_fila *);
void separa_fila(t_fila *, t_fila *, t_fila*);