/*14. Desenvolva uma operação para transferir elementos de uma pilha P1 para uma pilha P2 ˜
(copia).*/

#include <stdio.h>
#include <stdlib.h>

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

void transferirElementos(struct No** p1, struct No** p2) {
    struct No* pilhaAuxiliar = NULL;

    while (*p1 != NULL) {
        empilhar(&pilhaAuxiliar, desempilhar(p1));
    }

    while (pilhaAuxiliar != NULL) {
        empilhar(p2, desempilhar(&pilhaAuxiliar));
    }
}

void preencherPilha(struct No** pilha) {
    char linha[100];
    char *ptr;

    printf("Digite os elementos da pilha (separados por espaco, 'Enter' para finalizar): ");
    fgets(linha, sizeof(linha), stdin);

    ptr = linha;
    while (*ptr != '\0' && *ptr != '\n') {
        if (*ptr != ' ') {
            empilhar(pilha, *ptr);
        }
        ptr++;
    }
}


void imprimirPilha(struct No* topo) {
    struct No* atual = topo;
    while (atual != NULL) {
        printf("%c ", atual->dado);
        atual = atual->proximo;
    }
    printf("\n");
}

int main() {
    struct No* p1 = NULL;
    struct No* p2 = NULL;

    printf("Preencha a pilha P1:\n");
    preencherPilha(&p1);

    printf("Pilha P1 antes da transferencia: ");
    imprimirPilha(p1);

    transferirElementos(&p1, &p2);

    printf("Pilha P1 apos transferencia: ");
    imprimirPilha(p1);
    printf("Pilha P2 apos transferencia: ");
    imprimirPilha(p2);

    // Liberação de memória
    while (p1 != NULL) {
        desempilhar(&p1);
    }
    while (p2 != NULL) {
        desempilhar(&p2);
    }

    return 0;
}
