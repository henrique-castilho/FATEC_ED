/*13. Desenvolva uma função para testar se duas pilhas P1 e P2 são iguais*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct No {
    char dado;
    struct No* proximo;
};

struct No* criarNo(char dado) {
    struct No* novoNo = (struct No*)malloc(sizeof(struct No));
    novoNo->dado = dado;
    novoNo->proximo = NULL;
    return novoNo;
}

void empilhar(struct No** topo, char dado) {
    struct No* novoNo = criarNo(dado);
    novoNo->proximo = *topo;
    *topo = novoNo;
}

char desempilhar(struct No** topo) {
    if (*topo == NULL) {
        return '\0';
    }
    struct No* temp = *topo;
    char dado = temp->dado;
    *topo = (*topo)->proximo;
    free(temp);
    return dado;
}

int pilhasSaoIguais(struct No* p1, struct No* p2) {
    while (p1 != NULL && p2 != NULL) {
        if (p1->dado != p2->dado) {
            return 0;
        }
        p1 = p1->proximo;
        p2 = p2->proximo;
    }

    return (p1 == NULL && p2 == NULL) ? 1 : 0;
}

void limparPilha(struct No** topo) {
    while (*topo != NULL) {
        desempilhar(topo);
    }
}

void preencherPilha(struct No** topo, char* pilha) {
    int tamanho = strlen(pilha);
    for (int i = 0; i < tamanho; i++) {
        if (pilha[i] != ' ') {
            empilhar(topo, pilha[i]);
        }
    }
}

void imprimirPilha(struct No* topo) {
    printf("Pilha: ");
    while (topo != NULL) {
        printf("%c ", topo->dado);
        topo = topo->proximo;
    }
    printf("\n");
}

int main() {
    struct No* p1 = NULL;
    struct No* p2 = NULL;
    char pilha1[100], pilha2[100];

    printf("Digite os elementos da pilha 1 (separados ou juntos): ");
    scanf(" %[^\n]%*c", pilha1);
    preencherPilha(&p1, pilha1);

    printf("\nDigite os elementos da pilha 2 (separados ou juntos): ");
    scanf(" %[^\n]%*c", pilha2);
    preencherPilha(&p2, pilha2);

    imprimirPilha(p1);
    imprimirPilha(p2);

    if (pilhasSaoIguais(p1, p2)) {
        printf("\nAs pilhas sao iguais.\n");
    } else {
        printf("\nAs pilhas sao diferentes.\n");
    }

    limparPilha(&p1);
    limparPilha(&p2);

    return 0;
}

