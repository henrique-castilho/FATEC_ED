#include "no.h"

typedef struct lista {
    t_no * primeiro;
} t_lista;

void inicia_lista (t_lista *);
int lista_vazia (t_lista *);
void empilha (t_lista *, int);
void exibe_lista (t_lista *, char *);
int desempilha (t_lista *);

//Exercícios
int tamanho_lista (t_lista *);
int soma_valores (t_lista *);
int encontra_maior(t_lista *);
int encontra_menorPar(t_lista *);