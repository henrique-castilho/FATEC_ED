#include "lista.h"

void inicia_lista (t_lista *l) {
    l->primeiro = NULL;
}

int lista_vazia (t_lista *l) {
    return (l->primeiro == NULL);
}

void empilha(t_lista * l, int num) {
    t_no * novo = constroi_no(num);
    if (novo != NULL) {
        if (!lista_vazia(l)) {
            novo->proximo = l->primeiro;
        }
        l->primeiro = novo;
    }
}

void exibe_lista (t_lista *l, char *msg) {
    t_no *aux;
    printf("\n%s\n", msg);
    if (lista_vazia(l)) {
        printf("pilha Vazia");
    } else {
        aux = l->primeiro;
        while (aux != NULL) { //vai ate o fim
            printf("%d\n", aux->info);
            aux =  aux->proximo;
        }
    }
    printf("\n");
}

int desempilha (t_lista *l) {
    int i = l->primeiro->info; // "i" recebe uma cópia da informação armazenada no primeiro nó
    t_no * aux = l->primeiro;// "aux" recebe uma copia do endereço do primeiro nó
    l->primeiro = l->primeiro->proximo;
    free(aux);
    return i;
}


int tamanho_lista (t_lista *l) {
    t_no *aux;
    int cont = 0;
    if (!lista_vazia(l)) {
        aux = l->primeiro;
        while (aux != NULL) {
            cont++;
            aux = aux->proximo;
        }
    }
    return cont;
}

int soma_valores (t_lista * l) {
    t_no *aux;
    int soma = 0;
    if (!lista_vazia(l)) {
        aux = l->primeiro;
        while (aux != NULL) {
            soma += aux->info;
            aux = aux->proximo;
        }
    }
    return soma;
}

int encontra_maior (t_lista *l) {
    t_no *aux;
    int maior;
    if (!lista_vazia(l)) {
        aux = l->primeiro;
        maior = aux->info;
        while (aux != NULL) {
            if (aux->info > maior) {
                maior = aux->info;
            }
            aux = aux->proximo;
        }
        return maior;
    }
}

int encontra_menorPar (t_lista *l) {
    t_no *aux;
    int menorPar = -1;
    if (!lista_vazia(l)) {
        aux = l->primeiro;
        while (aux != NULL) {
            if (aux->info % 2 == 0) {
                if (menorPar == -1 || aux->info < menorPar) {
                    menorPar = aux->info;
                }
            }
            aux = aux->proximo;
        }
    }
    return menorPar;
}
