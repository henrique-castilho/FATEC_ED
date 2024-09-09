/*1. Crie um programa que:
(a) Aloque dinamicamente um array de 5 numeros inteiros,
(b) Peça para o usuario digitar os 5 números no espaço alocado,
(c) Mostre na tela os 5 numeros,
(d) Libere a memoria alocada. */

#include <stdio.h>
#include <stdlib.h>

int main(){
    int *v, t = 5;


    v = (int *) malloc (t* sizeof(int));

    printf("Digite 5 numeros inteiros:\n");
    for (int i = 0; i < t; i++){
        printf("Digite o %d numeoro: ", i+1);
        scanf("%d", &v[i]);
    }

    printf("\nOs numeros digitados foram:\nVetor: ");
    for (int i = 0; i < t; i++){
        printf("%d ", v[i]);
    }

    free(v);

    return 0;
}