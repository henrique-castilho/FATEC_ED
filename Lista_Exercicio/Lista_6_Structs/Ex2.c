/*2. Implemente um programa que leia o nome, a idade e o endereço de uma pessoa e
armazene os dados em uma estrutura.*/

#include <stdio.h>
#include <string.h>

// Definimos a estrutura pessoa para armazenar os dados
typedef struct pessoa{
    char nome[100];
    char endereco[200];
    int idade;
} dados;

int main(){
    // Declaramos uma variável do tipo dados
    dados p;

    // Pedimos o nome e lemos usando fgets
    printf("Digite o nome: ");
    fgets(p.nome, sizeof(p.nome), stdin);
    p.nome[strcspn(p.nome, "\n")] = '\0'; // Remove o caractere de nova linha, se presente

    // Pedimos a idade e lemos usando scanf
    printf("Digite a idade: ");
    scanf("%d", &p.idade);
    getchar(); // Consome o caractere de nova linha deixado no buffer de entrada

    // Pedimos o endereço e lemos usando fgets
    printf("Digite o endereco: ");
    fgets(p.endereco, sizeof(p.endereco), stdin);
    p.endereco[strcspn(p.endereco, "\n")] = '\0'; // Remove o caractere de nova linha, se presente

    // Imprimimos os dados armazenados
    printf("\nDados inseridos:\n");
    printf("Nome: %s\n", p.nome);
    printf("Idade: %d\n", p.idade);
    printf("Endereco: %s\n", p.endereco);

    return 0;
}
