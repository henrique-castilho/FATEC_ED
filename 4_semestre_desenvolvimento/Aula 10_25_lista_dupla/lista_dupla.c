#include "lista_dupla.h"

void inicia_lista(t_lista_dupla *l) {
    l->primeiro = NULL;
    l->ultimo = NULL;
    l->num_nos = 0;
}

int lista_vazia(t_lista_dupla *l) {
    return l->primeiro == NULL;
}

void insere_inicio(t_lista_dupla *l, int num) {
    t_no_duplo * novo = constroi_no(num);
    if (novo != NULL) {
        if (lista_vazia(l)) {
            l->ultimo = novo;
        } else {
            novo->proximo = l->primeiro;
            l->primeiro->anterior = novo;
        }
        l->primeiro = novo;
        l->num_nos ++;
    }
}

void isere_fim(t_lista_dupla *l, int num) {
   t_no_duplo * novo = constroi_no(num);
    if (novo != NULL) {
        if (lista_vazia(l)) {
            l->primeiro = novo;
        } else {
            novo->anterior = l->ultimo;
            l->ultimo->proximo = novo;
        }
        l->ultimo = novo;
        l->num_nos ++;
    }
}

void exibe_lista(t_lista_dupla *l, char *msg) {
    t_no_duplo *aux;
    printf("\n%s\n", msg);
    if (lista_vazia) {
        printf("Lista Vazia");
    } else {
        aux = l->primeiro;
        do {
            printf("%d, ", aux->info);
            aux = aux->proximo;
        } while (aux->proximo != l->ultimo);
        printf ("%d", aux->info);
    }
    printf("\n");
}