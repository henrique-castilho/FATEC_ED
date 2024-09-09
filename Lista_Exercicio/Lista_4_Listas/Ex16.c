//16. Fazer uma funçao que copia uma lista L1 em uma outra lista L2.

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

// Função para copiar a lista L1 para L2
void copiar_lista(no *L1, no **L2) {
    no *atual = L1;
    while (atual != NULL) {
        adicionar_no(L2, atual->valor);
        atual = atual->proximo;
    }
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

// Função para liberar a memória alocada para a lista
void liberar_lista(no *comeco) {
    no *atual = comeco;
    while (atual != NULL) {
        no *temp = atual;
        atual = atual->proximo;
        free(temp);
    }
}

int main() {
    no *L1 = NULL;
    no *L2 = NULL;
    int n, valor;

    // Solicita ao usuário o número de elementos na lista L1
    printf("Quantos elementos deseja adicionar na lista L1? ");
    scanf("%d", &n);

    printf ("\n");

     // Solicita ao usuário os valores dos elementos e os adiciona à lista L1~
    printf("Digite os valores de cada elemento:\n");
    for (int i = 0; i < n; i++){
        printf("%do elemento: ", i + 1);
        scanf("%d", &valor);
        adicionar_no(&L1, valor);
    }

    printf("Lista L1: ");
    imprimir_lista(L1);

    // Copia a lista L1 para L2
    copiar_lista(L1, &L2);

    printf("Lista L2 (copia de L1): ");
    imprimir_lista(L2);

    // Libera a memória alocada para as listas
    liberar_lista(L1);
    liberar_lista(L2);

    return 0;
}
