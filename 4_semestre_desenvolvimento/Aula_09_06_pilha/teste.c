#include "pilha.h"

int main () {
    pilha p;
    int tam;
    char elemento;

    printf("Digite o tamano da pilha: ");
    scanf("%d",&tam);

    inicia_pilha(&p, tam);

    printf("Digite %d elemento para empilhar (caracteres):\n", tam);
    for (int i = 0; i <tam; i++) {
        printf("Elemento %d: ", i + 1);
        scanf(" %c", &elemento);
        push(elemento, &p);
    }

    mostra_pilha(&p);

    while (pilha_vazia(&p) != TRUE) {
        printf("%c foi desempilhado\n", pop(&p));
    }

    mostra_pilha(&p);
    
    return 0;
}