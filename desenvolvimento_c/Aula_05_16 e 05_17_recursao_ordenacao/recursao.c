#include <stdio.h>

int fatorial (int n){
    ///printf("n = %d\n", n);
    if (n <= 1) {
        return 1;
    }else {
        return n *fatorial(n-1);
    }
}
int fibonacci (int n) {
    if (n <= 1)
        return 1;
    return fibonacci(n-1) + fibonacci(n-2);
}
int soma_1_a_n (int n){
    if (n > 0) return n + soma_1_a_n(n-1);
    return 0;
}
int potencia (int k, int n){
    if (n > 0) return k * potencia(k, n-1);
    return 1;
}
int multiplicacao(int n1, int n2){
    if (n1 == 1)
        return n2;
    return n2 + multiplicacao(n1 -1, n2);
}
void exibe_em_vetor1(int n, int v[]){
    if (n > 0){
        exibe_em_vetor1(n- 1, v);
    }
printf("%d ", v[n]);
}
void exibe_em_vetor2(int n, int v[]){
    if (n > 0){
        exibe_em_vetor2(n- 1, v);
    }
    printf("%d ", v[n]);   
}
void exibe_em_vetor3(int n, int v[]){
    if (n >= 0){
        printf("%d ", v[n]);
        exibe_em_vetor3 (n-1, v);
    }
}

int soma_vet (int i, int tam, int v[]){
    if (i < tam)
        return v[i] + soma_vet(i+1, tam, v);
    return 0;
}

int main(){
    // for (int i = 0; i <= 12; i++){
    //     printf("Fatorial de %d = %d\n", i, fatorial(i));
    // }
    // for (int i = 2; i <= 12; i++){
    //     printf("Fibonacci na posicao %d = %d\n", i, fibonacci(i));
    // }
    // printf("\nsoma 1 a 10: %d\n", soma_1_a_n(10));

    printf(" 2^4 = %d\n", potencia(2, 4));
    printf (" 5 x 4 = %d\n", multiplicacao(5, 4));
    int v[5] = {1, 2, 3, 4, 5};
    printf("Teste 1:\n");
    exibe_em_vetor1(5, v);
    printf("\nTeste 2:\n");
    exibe_em_vetor2(4, v);
    printf("\nTeste 3:\n");
    exibe_em_vetor3(4, v);

     printf("\nSoma do vetor = %d\n", soma_vet (0, 5, v));

    return 0;
}