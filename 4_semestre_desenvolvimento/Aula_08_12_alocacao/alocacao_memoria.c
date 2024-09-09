#include <stdio.h>

int main(){
    int i; //Armazena um inteiro simples
    int *p; //Armazena o endereço de um inteiro
    int v[4]; //Armazenar 4 inteiros, não se esqueça que um vetor é sempre um ponteiro

    printf ("Tamanho da variavel i: %d bytes\n", sizeof(i));
    printf ("Tamanhdo da variavel p: %d bytes\n", sizeof(p));
    printf ("Tamanho da variavel v: %d bytes\n", sizeof(v));

    printf ("Veja o conteudo de v: %p\n", v);
    printf ("Veja o conteudo de p: %p\n", p);
    printf ("Veja o conteudo de i: %d\n", i);

    printf ("Onde esta o i: %p\n", &i);
    printf ("Onde esta o P: %p\n", &p);

    p = &i; // P aponta para o i, ou seja contém o endereço de i
    // O operador & chama-se operador referência

    i= 10;
    printf ("Conteudo apontado por p: %d\n", *p);
    // O operador * (nesse contexto), chama se operador derreferênica

    *p = -20;
    printf("Para ver se entendemos i = %d\n", i);
    return 0;
}