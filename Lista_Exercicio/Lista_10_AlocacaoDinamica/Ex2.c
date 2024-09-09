/* 2. Faça um programa que leia do usuario o tamanho de um vetor a ser lido e faça a alocação
dinâmica de memória. Em seguida, leia do usuário seus valores e imprima o vetor lido.*/

#include <stdio.h>
#include <stdlib.h>

int main(){
    int *v, t;

    printf("Digite o tamanho do seu vetor: ");
    scanf("%d", &t);

    v = (int *) malloc (t * sizeof(int));

    printf("Digite %d numeros inteiros:\n", t);
    for (int i = 0; i < t; i++){
        printf("Digite o %d numeoro: ", i+1);
        scanf("%d", &v[i]);
    }

    printf("\nOs numeros digitados foram:\nVetor: ");
    for (int i = 0; i < t; i++){
        printf("%d ", v[i]);
    }


    return 0;
}