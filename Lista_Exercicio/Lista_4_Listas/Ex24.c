// 24. Escreva uma função que verifica se duas listas dadas são iguais (mesmo conteúdo)

#include "lista_dupla.h"
#include <time.h>

int listas_sao_iguais(t_lista_dupla *lista1, t_lista_dupla *lista2) {
    t_no_duplo *no1 = lista1->primeiro;
    t_no_duplo *no2 = lista2->primeiro;

    while (no1 != NULL && no2 != NULL) {
        if (no1->info != no2->info) {
            return 0; // As listas não são iguais
        }
        no1 = no1->proximo;
        no2 = no2->proximo;
    }

    // As duas listas devem ser NULL ao mesmo tempo para serem consideradas iguais
    return (no1 == NULL && no2 == NULL);
}


int main() {
    t_lista_dupla l1, l2;
    int tamanho, valor;

    // Inicializa as listas
    inicia_lista(&l1);
    inicia_lista(&l2);

    srand(time(0));

    // Solicita ao usuário o tamanho da lista
    printf("Digite o tamanho da lista: ");
    scanf("%d", &tamanho);

    // Solicita ao usuário os valores dos elementos e os adiciona à lista1
    for (int i = 0; i < tamanho; i++) {
        valor = rand() % 100 + 1; // Gera um número aleatório entre 1 e 100
        insere_fim(&l1, valor);
    }

    // Imprime os valores da lista1
    exibe_lista(&l1, "Lista 1");

    // Adiciona elementos à lista2
    for (int i = 0; i < tamanho; i++) {
        valor = rand() % 100 + 1; // Gera um número aleatório entre 1 e 100
        insere_inicio(&l2, valor);
    }

    // Imprime os valores da lista2
    exibe_lista(&l2, "Lista 2");

    // Verifica se as listas são iguais
    if (listas_sao_iguais(&l1, &l2)) {
        printf("As listas sao iguais.\n");
    } else {
        printf("As listas nao sao iguais.\n");
    }

    return 0;
}