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

void insere_fim(t_lista_dupla *l, int num) {
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

int remove_inicio(t_lista_dupla *l) {
    int num = l->primeiro->info; //num é a informação que vai ser removido e devolvido
    t_no_duplo *aux = l->primeiro; //aux é o ponteiro que guarda o endereço que vai ser liberado
    if (l->primeiro == l->ultimo) { //tem um só
        l->primeiro = NULL;
        l->ultimo = NULL;
    } else { //tem pelo menos 2
        l->primeiro = l->primeiro->proximo; //primeiro passa ser o segundo
        l->primeiro->anterior = NULL;
    }
    l->num_nos--;
    free(aux);
    return num;
}


int remove_fim(t_lista_dupla *l) {
    int num = l->ultimo->info; //num é a informação que vai ser removido e devolvido
    t_no_duplo *aux = l->ultimo; //aux é o ponteiro que guarda o endereço que vai ser liberado
    if (l->ultimo == l->primeiro) { //tem um só
        l->primeiro = NULL;
        l->ultimo = NULL;
    } else {
        l->ultimo = l->ultimo->anterior; // ultímo passa ser o penultimo
        l->ultimo->proximo = NULL;
    }
    l->num_nos--;
    free(aux);
    return num;
}