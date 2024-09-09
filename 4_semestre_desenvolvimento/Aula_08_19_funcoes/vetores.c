#include "vetor.h"

int main(){
    srand(time(0));
    //Pedir o tamanho do vetor
   int t;
    printf("Digite o tamanho do vetor, 0 encerra: ");
    scanf("%d", &t);
    
    while (t > 0) {
        //Alocar o vetor de inteiros dinamicamente
        int * v = (int *) malloc (t *sizeof(int));
        printf("\nEndereco alocado: %p\n", v);

        preenche_vetor (v, t);
        exibe_vetor (v, t);
        free(v);

        printf("\nDigite o novo tamanho, 0 encerra: ");
        scanf ("%d", &t);
    }
    return 0;
}

