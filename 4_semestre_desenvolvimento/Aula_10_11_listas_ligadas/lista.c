#include "lista.h"

void inicia_lista (t_lista *l) {
    l->primeiro = NULL;
}

int lista_vazia(t_lista *l) {
    return (l->primeiro == NULL);
}

void insere_inicio(t_lista * l, int num) {
    t_no * novo = controi_no(num);
    if (novo != NULL) {
        if (lista_vazia(l)) {
            novo->proximo = l->primeiro;
        }
        l->primeiro = novo;
    }
    
}

void exibe_lista (t_lista *l) {

}
