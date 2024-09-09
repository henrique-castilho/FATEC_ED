#include "fila.h"

int main () {
    t_fila * fila = constroi_fila(10);
    if (fila != NULL){
        printf ("Estrutura fila alocada com sucesso!\n");
    }
    else {
        printf("Problema na alocação da fila!\n");
    }
    if (esta_vazia(fila)){
        printf("Fila vazia\n");
    }
    else {
        printf("Fila tem gente");
    }
    int a = 10;
    while (enfileira(a++, fila)) {
        mostra_fila(fila);
    }
    if (esta_cheia(fila)) {
        printf ("\nFila esta cheia\n\n");
    }
    else {
        printf("Fila tem lugar");
    }
    while (desenfileira (&a, fila))
        printf ("%d foi atendido\n", a);
    return 0;
}