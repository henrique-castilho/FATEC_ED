/* Ler uma string qualquer, remover seus espaços usando uma pilha e verificar se a string empilhada é palindrome */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int topo;
    int capacidade;
    char *elementos;
} pilha;

void inicia_pilha(pilha *p, int tamanho) {
    p->topo = 0;
    p->elementos = (char *) malloc(tamanho * sizeof(char));
    p->capacidade = tamanho;
}

int pilha_cheia(pilha *p) {
    if (p->topo == p->capacidade) {
        return 1;
    } else {
        return 0;
    }
}

int pilha_vazia(pilha *p) {
    if (p->topo == 0) {
        return 1;
    } else {
        return 0;
    }   
}

void empilha(pilha *p, char str) { //push
    if (pilha_cheia(p) == 1) {
        printf("A pilha esta cheia");
    } else {
        p->elementos[p->topo++] = str;
    }   
}

char desempilha(pilha *p) { //pop
    if (pilha_vazia(p) == 1) {
        printf("A pilha esta vazia");
    } else {
        return p->elementos[--p->topo];
    }
}

void mostra_pilha(pilha *p) {
    for (int i = p->topo - 1; i >= 0; i--) {
        printf("%c", p->elementos[i]);
    }
    printf("\n");
}

int eh_palindrome(pilha *p) {
    int inicio = 0;
    int fim = p->topo - 1;

    while (inicio < fim) {
        if (p->elementos[inicio] != p->elementos[fim]) {
            return 0;
        }
        inicio++;
        fim--;
    }

    return 1;
}

void libera_memoria (pilha *p) {
    free(p->elementos);
}


int main() {
    pilha p;
    char frase[100];

    printf("Digite a frase: ");
    char c;
    int i = 0;

    while ((c = getchar()) != '\n') {
        frase[i++] = c;
    }
    frase[i] = '\0';
    
    inicia_pilha(&p, strlen(frase));


    for (int i = 0; i < strlen(frase); i++) {
        if (frase[i] != ' ') {
            empilha(&p, frase[i]);
        }
    }

    printf("Frase sem espacos: ");
    mostra_pilha(&p);

    
    if (eh_palindrome(&p)) {
        printf("A frase eh palindrome!\n");
    } else {
        printf("A frase nao eh palindrome.\n");
    }

    libera_memoria(&p);

    return 0;
}