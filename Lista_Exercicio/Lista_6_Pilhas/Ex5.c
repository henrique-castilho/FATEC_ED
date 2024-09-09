/*5. Considere uma pilha que armazene caracteres. Faça uma função para determinar se ˜
uma string e da forma XY, onde X e uma cadeia formada por caracteres arbitrários e Y 
é o reverso de X. Por exemplo, se x = ABCD, então y = DCBA. Considere que x e y são
duas strings distintas*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definição da estrutura da pilha usando vetores
struct Pilha {
    int topo;
    int capacidade;
    char *array;
};

// Função para criar uma pilha de capacidade especificada
struct Pilha* criarPilha(int tamanho) {
    struct Pilha* pilha = (struct Pilha*) malloc(sizeof(struct Pilha));
    pilha->capacidade = tamanho;
    pilha->topo = -1;
    pilha->array = (char*) malloc(pilha->capacidade * sizeof(char));
    return pilha;
}

// Função para verificar se a pilha está cheia
int estaCheia(struct Pilha* pilha) {
    return pilha->topo == pilha->capacidade - 1;
}

// Função para verificar se a pilha está vazia
int estaVazia(struct Pilha* pilha) {
    return pilha->topo == -1;
}

// Função para adicionar um item à pilha
void empilhar(struct Pilha* pilha, char item) {
    if (estaCheia(pilha)) {
        return;
    }
    pilha->array[++pilha->topo] = item;
}

// Função para remover um item da pilha
char desempilhar(struct Pilha* pilha) {
    if (estaVazia(pilha)) {
        return '\0';
    }
    return pilha->array[pilha->topo--];
}

// Função para verificar se a string está na forma XY
int formaXY(char* str) {
    int n = strlen(str);
    int metade = n / 2;
    struct Pilha* pilha = criarPilha(metade);

    // Empilhar a primeira metade da string
    for (int i = 0; i < metade; i++) {
        empilhar(pilha, str[i]);
    }

    // Comparar a segunda metade da string com os elementos desempilhados
    for (int i = (n % 2 == 0) ? metade : metade + 1; i < n; i++) {
        if (str[i] != desempilhar(pilha)) {
            free(pilha->array);
            free(pilha);
            return 0;
        }
    }

    free(pilha->array);
    free(pilha);
    return 1;
}

int main() {
    char str[100];

    printf("Digite a string: ");
    scanf("%s", str);

    if (formaXY(str)) {
        printf("\nA string '%s' eh da forma XY.\n", str);
    } else {
        printf("\nA string '%s' nao eh da forma XY.\n", str);
    }

    return 0;
}
