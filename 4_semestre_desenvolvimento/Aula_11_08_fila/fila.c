#include "fila.h"

void inicia_fila(t_fila *f) {
    f->primeiro = NULL;
    f->ultimo = NULL;
    f->num_nos = 0;
}

int fila_vazia(t_fila *f) {
    return f->primeiro == NULL;
}

void enfileira(t_fila *f, int num) { //insere no fim
   t_no_duplo * novo = constroi_no(num);
    if (novo != NULL) {
        if (fila_vazia(f)) {
            f->primeiro = novo;
        } else {
            novo->anterior = f->ultimo;
            f->ultimo->proximo = novo;
        }
        f->ultimo = novo;
        f->num_nos ++;
    }
}

void exibe_fila(t_fila *f, char *msg) {
    t_no_duplo *aux;
    printf("\n%s\n", msg);
    if (fila_vazia(f)) {
        printf("Fila Vazia");
    } else {
        aux = f->primeiro;
        while (aux != f->ultimo) {
            printf("%d, ", aux->info);
            aux = aux->proximo;
        }
        printf("%d", aux->info);
    }
    printf("\n");
}

int desenfileira(t_fila *f) { //remove no inicio
    int num = f->primeiro->info; //num é a informação que vai ser removido e devolvido
    t_no_duplo *aux = f->primeiro; //aux é o ponteiro que guarda o endereço que vai ser liberado
    if (f->primeiro == f->ultimo) { //tem um só
        f->primeiro = NULL;
        f->ultimo = NULL;
    } else { //tem pelo menos 2
        f->primeiro = f->primeiro->proximo; //primeiro passa ser o segundo
        f->primeiro->anterior = NULL;
    }
    f->num_nos--;
    free(aux);
    return num;
}

void exibe_primeiro(t_fila* f) {
    if (fila_vazia(f)) {
        printf("Fila vazia");
    } else {
        printf("Primeiro: %d\n", f->primeiro->info);
    }   
}

void exibe_ultimo(t_fila *f) {
    if (fila_vazia(f)) {
        printf("Fila_vazia");
    } else {
        printf("Ultimo: %d\n", f->ultimo->info);
    }
}

//Exercício
void separa_fila(t_fila *f, t_fila *f_par, t_fila *f_impar) {
    while (!fila_vazia(f)){
        int num = desenfileira(f);
        if (num % 2) {
            enfileira (f_impar, num);
        } else {
            enfileira(f_par, num);
        }
    }
}