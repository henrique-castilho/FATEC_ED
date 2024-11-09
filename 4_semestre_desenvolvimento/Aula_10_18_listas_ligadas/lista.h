#include "no.h"

typedef struct lista {
    t_no * primeiro;
} t_lista;

void inicia_lista (t_lista *);
int lista_vazia (t_lista *);
void insere_inicio (t_lista *, int);
void exibe_lista (t_lista *, char *);
void insere_fim (t_lista *, int);
int remove_inicio (t_lista *);
int remove_fim (t_lista *);

//Exercícios
int tamanho_lista (t_lista *);
int soma_valores (t_lista *);
int encontra_maior(t_lista *);
int encontra_menorPar(t_lista *);