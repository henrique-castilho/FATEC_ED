#include "no.h"

int main () {
    struct no a; // 'a' é uma struct nó
    t_no b; // 'b' é uma struct nó
    t_no * p; // 'p' é um ponteiro para uma struct nó

    a.info = 12;
    
    b.info = 35;
    printf("Endereco da variavel 'b': %p\n", &b);
    a.proximo = &b;
    printf("Endereco da variavel 'a': %p\n", &a);
    p = &a;
    
    return 0;
}