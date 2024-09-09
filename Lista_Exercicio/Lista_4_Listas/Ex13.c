/*13. Considere uma lista contendo numeros inteiros positivos. Fac¸a uma função que retorne
a media da lista.*/

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
    no *ultimo = *comeco;
    novo_no->valor = valor;
    novo_no->proximo = NULL;

    if (*comeco == NULL) {
        *comeco = novo_no;
        return;
    }

    while (ultimo->proximo != NULL) {
        ultimo = ultimo->proximo;
    }
    ultimo->proximo = novo_no;
}

// Função para calcular a média dos valores na lista ligada
float calcular_media(no *comeco) {
    int soma = 0, cont = 0;
    no *atual = comeco;

    while (atual != NULL) {
        soma += atual->valor;
        cont++;
        atual = atual->proximo;
    }

    return (cont > 0) ? (float)soma / cont : 0;
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
    no *comeco = NULL;
    int n, valor;

    // Pergunta ao usuário quantos números ele deseja inserir
    printf("Quantos numeros voce quer inserir para calcular a media?\n");
    scanf("%d", &n);

    // Verifica se a quantidade de números é positiva
    if (n <= 0) {
        printf("A quantidade de numeros deve ser positiva.\n");
        return 1;
    }

    // Lê os números e adiciona à lista
    for (int i = 0; i < n; i++) {
        printf("Digite o %do numero inteiro positivo:\n", i+1);
        scanf("%d", &valor);

        if (valor < 0) {
            printf("Apenas numeros positivos sao permitidos.\n");
            i--; // Diminui o contador para tentar novamente
        } else {
            adicionar_no(&comeco, valor);
        }
    }

    // Calcula e imprime a média dos números na lista
    float media = calcular_media(comeco);
    printf("\n%.1f eh a media dos numeros ", media);
    imprimir_lista(comeco);

    return 0;
}
