#include <stdio.h>

void funcao1(int a) {
    printf("Entrei na funcao1: %d\n", a);
    a++;
}

void funcao2(int a) {
    printf("Entrei na funcao2: %d\n", a);
    a++;
    funcao1(a); 
}

void funcao3(int *a) {
    printf("Valor de 'a' na chegada a funcao3: %d\n", *a);
    *a = *a + 1;
}


int main() {
    int a = 10;

    funcao1(a);
    funcao2(a);
    funcao3(&a);
    printf("Terminei tudo, a = %d!\n", a);

    return 0;
}   