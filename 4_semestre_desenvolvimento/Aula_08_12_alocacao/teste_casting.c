#include <stdio.h>

int main(){
    int a = 18;
    int b = 4;

    printf ("18 / 4 = %d\n", a/b);
    printf ("18 / 4 = %f\n", a/b);

    printf ("18 / 4 = %.2f\n", (float) a/b);

    float x = 34.56;
    int n = (int) x;
    printf ("Valor de n (Pega o valor inteiro de x): %d\n", n);

    float decimal = x - n;
    printf ("A parte decimal de x %.2f", decimal);

    return 0;
}