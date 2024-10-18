#include "lista.h"

int main () {
    t_lista l;

    inicia_lista(&l);
    exibe_lista(&l, "Lista depois de inicializada");

    insere_inicio(&l, 1);
    insere_inicio(&l, 2);
    insere_inicio(&l, 3);
    exibe_lista(&l,"Lista depois das insercoes de inicio");

    insere_fim(&l, 4);
    insere_fim(&l, 5);
    insere_fim(&l, 6);
    exibe_lista(&l,"Lista depois das insercoes de fim");

    int primero_elemento = remove_inicio(&l);
    printf("\n%d saiu do inicio da lista", primero_elemento);
    exibe_lista(&l, "Lista depois da remocao de inicio");

    int ultimo_elemente = remove_fim(&l);
    printf("\n%d saiu do fim da lista", ultimo_elemente);
    exibe_lista(&l, "lista depois da remocao do fim");

    printf("\nTamanho da lista: %d\n", tamanho_lista(&l));

    printf("\nSoma dos valores: %d\n", soma_valores(&l));

    printf("\nO maior elemento da lista eh: %d\n", encontra_maior(&l));

    printf("\nO menor elemento par da lista eh: %d\n", encontra_menorPar(&l));

    return 0;
}