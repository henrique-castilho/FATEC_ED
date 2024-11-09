#include "lista_dupla.h"

void inicia_lista(t_lista_dupla *l) {
    l->primeiro = NULL;
    l->ultimo = NULL;
}

int lista_vazia(t_lista_dupla *l) {
    return(l->primeiro == NULL);
}

void insere_inicio(t_lista_dupla *l, int num) {
    t_no_duplo *novo = constroi_no(num);
    if (novo != NULL) {
        if (lista_vazia(l)) {
            l->ultimo = novo;
        } else {
            novo->proximo = l->primeiro;
            l->primeiro->anterio = novo;
        }
        l->primeiro = novo;
    }
}
void insere_fim(t_lista_dupla *l, int num) {
    t_no_duplo *novo = constroi_no(num);
    if (novo != NULL) {
        if (lista_vazia(l)) {
            l->primeiro = novo;    
        } else {
            novo->anterio = l->ultimo;
            l->ultimo->proximo = novo;
        }
        l->ultimo = novo;
    }
    
}
void exibe_lista(t_lista_dupla *l, char *msg) {
    t_no_duplo *aux;
    printf("\n%s\n", msg);
    if (lista_vazia(l)) {
        printf("Lista Vazia");
    } else {
        aux = l->primeiro;
        while (aux != NULL) {
            printf("%d ", aux->info);
            aux = aux->proximo;
        }
    }
    printf("\n");
}

int remove_inicio(t_lista_dupla *l) {
    int num = l->primeiro->info;
    t_no_duplo *aux = l->primeiro;
    if (l->primeiro == l->ultimo) {
        l->primeiro = NULL;
        l->ultimo = NULL;
    } else {
        l->primeiro = l->primeiro->proximo;
        l->primeiro->anterio = NULL;
    }
    free(aux);
    return num;
}

int remove_fim(t_lista_dupla *l) {
    int num = l->ultimo->info;
    t_no_duplo *aux = l->ultimo;
    if (l->ultimo == l->primeiro) { //tem um só
        l->primeiro = NULL;
        l->ultimo = NULL;
    } else {
        l->ultimo = l->ultimo->anterio;
        l->ultimo->proximo = NULL;
    }
    free(aux);
    return num;
}
