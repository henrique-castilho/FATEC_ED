#include "fila.h"

void inicia_fila(t_fila *f){
    f->primeiro = f->ultimo = NULL;
    f->tamanho = 0;
}

int esta_vazia(t_fila *f){

    return f->tamanho == 0;
}

void enfileira(int x, t_fila *f){

    t_no * novo = constroi_no(x);
    if (esta_vazia(f)){

        f->primeiro = novo;

    }
    else{
        f->ultimo->proximo = novo;
    }
        f->ultimo = novo;
        f->tamanho++;
}

int desenfileira(t_fila *f){
    int temp = f->primeiro->info;
    t_no *lixo = f->primeiro;
    f->primeiro = f->primeiro->proximo;
    f->tamanho--;
    if(esta_vazia(f))
        f->ultimo = NULL;
    free(lixo);
    return temp;
}

void mostra_fila(t_fila *f){
    if(esta_vazia(f))
        printf("\nfila vazia\n");
        else{
            t_no * aux = f->primeiro;
            while(aux!=NULL){
                printf("%d ", aux->info);
                aux = aux->proximo;
            }
        }
}