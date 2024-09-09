#include "prototipos.h"

int main () {
    pilha p;
    int tam;
    int elementos;

    printf("\nDigite o tamanho da pilha: ");
    scanf("%d",&tam);

    inicia_pilha(&p, tam);

    printf("\nDigite %d elemento para empilhar:\n", tam);
    for (int i = 0; i < tam; i++) {
        printf("Elemento %d: ", i+1);
        scanf("%d", &elementos);
        empilha(&p, elementos);
    }
    
    printf("\nPilha com os elementos:\n");
    mostra_pilha(&p);
    

    while (pilha_vazia(&p) != TRUE) {
        printf("%d foi desempilhado\n", desempilha(&p));
    }
    
    mostra_pilha(&p);

    libera_pilha(&p);

    return 0;
}