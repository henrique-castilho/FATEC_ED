#include "no.h"

typedef struct lista {
    t_no * primeiro;
} t_lista;


void inicia_lista (t_lista *);
int lista_vazia(t_lista *);
void insere_inicio(t_lista *, int);
void exibe_lista (t_lista *);