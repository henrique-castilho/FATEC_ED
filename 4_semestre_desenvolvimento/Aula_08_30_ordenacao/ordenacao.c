#include "vetor.h"

int main(){
    int n, *v;
    srand(time(0));

    printf("Digite o tamanho do vetor, 0 encerra: ");
    scanf("%d", &n);

    while (n > 0){
        v = (int *) malloc (n * sizeof(int));
        //Preenche o vetor e ordena com o bubblesort
        preenche_vetor(v, n);
        exibe_vetor(v, n, "1o Vetor gerado:");
        long inicio = time(0);
        bubblesort(v, n);
        long fim = time(0);
        printf("\nn = %d, tempo bubble = %d", n, fim - inicio);
        exibe_vetor(v, n, "Vetor ordenado bubble:");

        //Preenche o vetor e ordena com o insertiosort
        preenche_vetor(v, n);
        exibe_vetor(v, n, "2o vetor gerado");
        inicio = time(0);
        insertionsort(v, n);
        fim = time(0);
        printf("\nn = %d, tempo insertion = %d", n, fim - inicio);
        exibe_vetor(v, n, "Vetor ordenado insertion:");


        //Preenche o vetor e ordena com o selectionsort
        preenche_vetor(v, n);
        exibe_vetor(v, n, "3o vetor gerado:");
        inicio = time(0);
        selectionsort(v, n);
        fim = time(0);
        printf("\nn = %d, tempo selection = %d", n, fim - inicio);
        exibe_vetor(v, n, "Vetor ordenado selection");

        free(v);

        printf("\nDigite o tamanho para um novo teste, 0 encerra: ");
        scanf("%d", &n);
    }

    return 0;
}