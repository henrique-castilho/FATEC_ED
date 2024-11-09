#include "lista_dupla.h"
#include "time.h"

void copiar_lista(t_lista_dupla *l1, t_lista_dupla *l2) {
    t_no_duplo *aux = l1->primeiro;
    while (aux != NULL) {
        insere_fim(l2, aux->info);  // Insere no fim de L2
        aux = aux->proximo;
    }
}

int main() {
    t_lista_dupla l1, l2;
    int tamanho_lista, num;

    // Inicializa as listas
    inicia_lista(&l1);
    inicia_lista(&l2);

    srand(time(0));

    printf("Digite o tamanho da lista L1: ");
    scanf("%d", &tamanho_lista);

    printf("\n");

    for (int i = 0; i < tamanho_lista; i++) {
        num = rand() % 100 + 1; // Gera um número aleatório entre 1 e 100
        insere_fim(&l1, num);
        exibe_lista(&l1, "Inserido na lista");
    }

    printf("\n\nListas completas\n");
    exibe_lista(&l1, "Lista L1");

    // Copia a lista L1 para L2
    copiar_lista(&l1, &l2);

    exibe_lista(&l2, "Lista L2 (copia de L1)");

    // Libera a memória das listas
    while (!lista_vazia(&l1)) {
        remove_inicio(&l1);
    }
    while (!lista_vazia(&l2)) {
        remove_inicio(&l2);
    }

    return 0;
}