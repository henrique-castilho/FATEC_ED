//21. Escreva uma função que crie uma lista encadeada a partir de um vetor. 

#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura de um nó da lista encadeada
typedef struct no {
    int data;
    struct no* next; // Corrigido para ser um ponteiro para o próximo nó
} no;

// Função para criar um novo nó
no* criarNo(int data) {
    no* novoNo = (no*)malloc(sizeof(no));
    if (!novoNo) {
        printf("Erro na alocação de memória.\n");
        exit(1);
    }
    novoNo->data = data;
    novoNo->next = NULL;
    return novoNo;
}

// Função para criar uma lista encadeada a partir de um vetor
no* criarListaEncadeadaAPartirDeVetor(int vetor[], int tamanho) {
    if (tamanho == 0) return NULL;

    no* cabeca = criarNo(vetor[0]);
    no* atual = cabeca;

    for (int i = 1; i < tamanho; i++) {
        atual->next = criarNo(vetor[i]);
        atual = atual->next;
    }

    return cabeca;
}

// Função para imprimir a lista encadeada
void imprimirListaEncadeada(no* cabeca) {
    no* atual = cabeca;
    while (atual != NULL) {
        printf("%d", atual->data);
        atual = atual->next;
        if (atual != NULL) {
            printf(" -> ");
        }
    }
    printf("\n");
}

// Função principal para testar a criação da lista encadeada a partir de um vetor
int main() {
    int tamanho;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tamanho);

    int* vetor = (int*)malloc(tamanho * sizeof(int));
    if (!vetor) {
        printf("Erro na alocação de memória.\n");
        exit(1);
    }

    printf("Digite os elementos do vetor:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("Elemento %d: ", i + 1);
        scanf("%d", &vetor[i]);
    }

    no* cabeca = criarListaEncadeadaAPartirDeVetor(vetor, tamanho);

    printf("Lista encadeada: ");
    imprimirListaEncadeada(cabeca);

    // Liberar memória alocada para o vetor e para a lista encadeada
    free(vetor);

    no* atual = cabeca;
    no* proximo;
    while (atual != NULL) {
        proximo = atual->next;
        free(atual);
        atual = proximo;
    }

    return 0;
}
