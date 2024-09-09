// 24. Escreva uma func¸ao que verifica se duas listas dadas são iguais (mesmo conteúdo)

#include <stdio.h>
#include <stdlib.h>

// Estrutura de nó para a lista ligada
typedef struct no {
    int valor;
    struct no *proximo;
} no;

// Função para adicionar um novo nó ao final da lista ligada
void adicionar_no(no **comeco, int valor) {
    no *novo_no = (no *)malloc(sizeof(no));
    novo_no->valor = valor;
    novo_no->proximo = NULL;

    if (*comeco == NULL) {
        *comeco = novo_no;
        return;
    }

    no *ultimo = *comeco;
    while (ultimo->proximo != NULL) {
        ultimo = ultimo->proximo;
    }
    ultimo->proximo = novo_no;
}

// Função para verificar se duas listas ligadas são iguais
int listas_sao_iguais(no *lista1, no *lista2) {
    while (lista1 != NULL && lista2 != NULL) {
        if (lista1->valor != lista2->valor) {
            return 0; // As listas não são iguais
        }
        lista1 = lista1->proximo;
        lista2 = lista2->proximo;
    }

    // As duas listas devem ser NULL ao mesmo tempo para serem consideradas iguais
    return (lista1 == NULL && lista2 == NULL);
}

// Função para imprimir os valores na lista ligada
void imprimir_lista(no *comeco) {
    no *atual = comeco;
    while (atual != NULL) {
        printf("%d ", atual->valor);
        atual = atual->proximo;
    }
    printf("\n");
}

int main() {
    no *lista1 = NULL;
    no *lista2 = NULL;
    int tamanho, valor;

    // Solicita ao usuário o tamanho da lista
    printf("Digite o tamanho da lista: ");
    scanf("%d", &tamanho);

    printf("\n");

    // Solicita ao usuário os valores dos elementos e os adiciona à lista1
    printf("Digite os valores da lista1:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("Elemento %d: ", i + 1);
        scanf("%d", &valor);
        adicionar_no(&lista1, valor);
    }

    // Imprimi os valores da lista1
    printf("Lista 1: ");
    imprimir_lista(lista1);

    printf("\n");

    // Adiciona elementos à lista2
    printf("Digite os valores da lista2:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("Elemento %d: ", i + 1);
        scanf("%d", &valor);
        adicionar_no(&lista2, valor);
    }

    // Imprimi os valores da lista1
    printf("Lista 2: ");
    imprimir_lista(lista2);

    printf("\n");

    // Verifica se as listas são iguais
    if (listas_sao_iguais(lista1, lista2)) {
        printf("As listas sao iguais.\n");
    } else {
        printf("As listas nao sao iguais.\n");
    }

    return 0;
}
