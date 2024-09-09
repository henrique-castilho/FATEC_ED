#include "no.h"

typedef struct abb {
    t_no * raiz;
} t_abb;

void inicializa_abb (t_abb *);

int esta_vazia (t_abb *);

void insere (int, t_abb *);

void exibe_em_ordem (t_abb *);

int o_maior (t_abb *);

void exibe_pre_ordem (t_abb * a);

void exibe_decrescente (t_abb *);

int altura (t_abb *);