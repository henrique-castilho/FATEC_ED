#include "vetor.h"

int main(){
    int n, *v;
    srand(time(0));

    printf("Digite o tamanho do vetor, 0 encerra: ");
    scanf("%d", &n);

    while (n > 0){
        int const_quick = 0;
        int const_busca_simples = 0;
        int const_busca_binaria = 0;

        v = (int *) malloc (n * sizeof(int));

        preenche_vetor(v, n);
        exibe_vetor(v, n, "Vetor Gerado");

        int x;
        printf ("\nDigite um valor para a busca: ");
        scanf("%d", &x);
        if (busca_simples(v, x, n, &const_busca_simples) == 1) {
            printf("pela busca simples, %d esta na lista\n", x);
        } else {
            printf("pela busca simples, %d nao esta na lista\n", x);
        }
        printf("A busca simples realizou %d comparacoes\n", const_busca_simples);
        
        quicksort(v, 0, n-1, &const_quick);
        exibe_vetor(v, n, "Vetor ordenado");
        printf("O quick realicou %d comparacoes\n", const_quick);

        if (busca_binaria(v, x, n, &const_busca_binaria) == 1) {
            printf("Pela busca binaria, %d esta na lista\n", x);
        } else {
            printf("Pela busca binaria, %d nao esta na lista\n", x);
        }
        printf("A busca binaria realizou %d comparacoes\n", const_busca_binaria);

        free(v);
        printf("\nDigite o tamanho para um novo teste, 0 encerra: ");
        scanf("%d", &n);
    }
    return 0;
}