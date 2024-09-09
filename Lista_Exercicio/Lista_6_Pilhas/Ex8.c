/*8. Escreva um programa que utilize uma pilha para verificar se expressoes aritm ˜ eticas est ´ ao˜
com a parentizac¸ao correta. O programa deve verificar express ˜ oes para ver se cada “abre ˜
parenteses” tem um “fecha par ˆ enteses” correspondente. Ex.: ˆ
Correto: ( ( ) ) – ( ( )( ) ) – ( ) ( )
Incorreto: )( – ( ( ) ( – ) ) ( (  */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definição da estrutura da pilha usando vetores
struct Pilha {
    int topo;
    int capacidade;
    char* array;
};

// Função para criar uma pilha de capacidade especificada
struct Pilha* criarPilha(int capacidade) {
    struct Pilha* pilha = (struct Pilha*) malloc(sizeof(struct Pilha));
    pilha->capacidade = capacidade;
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

// Função para verificar se a expressão está com a parentização correta
int verificarParenteses(char* expressao) {
    int n = strlen(expressao);
    struct Pilha* pilha = criarPilha(n);

    for (int i = 0; i < n; i++) {
        if (expressao[i] == '(') {
            empilhar(pilha, expressao[i]);
        } else if (expressao[i] == ')') {
            if (estaVazia(pilha)) {
                free(pilha->array);
                free(pilha);
                return 0;  // Encontrou um ')' sem correspondente '('
            }
            desempilhar(pilha);
        }
    }

    int resultado = estaVazia(pilha);
    free(pilha->array);
    free(pilha);
    return resultado;
}

int main() {
    char expressao[100];

    printf("Digite a expressao aritmetica: ");
    fgets(expressao, sizeof(expressao), stdin);

    // Remover o caractere de nova linha que fgets adiciona ao final da string
    expressao[strcspn(expressao, "\n")] = '\0';

    if (verificarParenteses(expressao)) {
        printf("\nA expressao '%s' esta com a parentizacao correta.\n", expressao);
    } else {
        printf("\nA expressao '%s' nao esta com a parentizacao correta.\n", expressao);
    }

    return 0;
}
