/*13. Considere uma lista contendo numeros inteiros positivos. Faça uma função que retorne
a media da lista.*/

#include "lista_dupla.h"
#include "time.h"

// Função para calcular a média dos valores na lista ligada
float calcular_media(t_lista_dupla *l, char *msg) {
    int soma = 0, cont = 0;
    printf("\n%s\n", msg);
    t_no_duplo *aux = l->primeiro;
    while (aux != NULL) {
        soma += aux->info;
        cont++;
        aux = aux->proximo;
    }
    if (cont > 0) {
        return (float)soma/cont;
    } else {
        return 0;
    }
}

int main() {
    t_lista_dupla l;
    int num, tamanho_lista;

    inicia_lista(&l);
    
    srand(time(0));

    printf("Digite o tamanho da lista: ");
    scanf("%d", &tamanho_lista);

    printf("\nTamanho da lista gerada: %d\n\n", tamanho_lista);

    // Cria uma lista de números aleatórios
    for (int i = 0; i < tamanho_lista; i++) {
        num = rand() % 100 + 1; // Gera um número aleatório entre 1 e 100
        insere_fim(&l, num);
        exibe_lista(&l, "Inserido na lista");
    }

    // Exibe a lista gerada
    exibe_lista(&l, "Lista gerada com numeros aleatorios:");

    // Calcula e imprime a média dos números na lista
    float media = calcular_media(&l, "Media do numeros da lista");
    printf("%.2f\n", media);

    return 0;
}