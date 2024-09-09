/* 3. Faça um programa que leia do usuario o tamanho de um vetor a ser lido e faça a alocação
dinamica de memória. Em seguida, leia do usuário seus valores e mostre quantos dos números 
são pares e quantos são ímpares*/

#include <stdio.h>
#include <stdlib.h>

int main(){
    int *v, t;
    int par = 0, impar = 0;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &t);

    v = (int *) malloc (t * sizeof(int));

    printf("Digite os %d numero do vetor:\n", t);
    for (int i = 0; i < t; i++) {
        printf("Digite o %d valor: ", i+1);
        scanf("%d", &v[i]);
    }
    
    for (int i = 0; i < t; i++) {
        if (v[i] % 2 == 0) {
            par++;
        } else {
            impar++;
        }
    }
    
    printf("Quantidade de numeros pares: %d\n", par);
    printf("Quantidade de numeros impares: %d", impar);

    free(v);

    return 0;
}