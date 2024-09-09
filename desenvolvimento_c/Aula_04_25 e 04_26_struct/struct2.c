#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int dia, mes, ano;
} t_data;

t_data le_data() {
    t_data data;
    do {
        printf ("\ndigite o dia: ");
        scanf ("%d", &data.dia);
    } while (data.dia < 1 || data.dia > 31);
    printf("\ndigite o mes: ");
    scanf("%d", &data.mes);
    while (data.mes > 12 || data.mes < 1) {
        printf("\ninsira um mes valido: ");
        scanf("%d", &data.mes);
    }
    printf("\ndigite o ano: ");
    scanf("%d", &data.ano);
    while (data.ano > 2024 || data.ano < 1900) {
        printf("\ninsira um ano valido: ");
        scanf("%d", &data.ano);
    }
    return data;
}
void mostra_data (t_data data) {
    printf ("%d/%d/%d\n", data.dia, data.mes, data.ano);
}
int * le_vetor (int t) {
    //int v[t]; --> alocação de variável local
    int * v = (int *) malloc (t * sizeof(int));
    for (int i=0; i<t; i++) {
        printf("%d: ", i);
        scanf ("%d", &v[i]);
    }
    return v;
}
int * gera_vetor (int t) {
    int * v = (int *) malloc (t * sizeof(int));
    for (int i=0; i<t; i++) {
        v[i] = rand() % 1000;
    }
    return v;
}
void mostra_vetor (int *v, int t) {
    printf ("\nendereco do vetor: %p\n", v);
    // for (int i=0; i<t; i++) {
    //     printf ("%d ", v[i]);
    // }
}
t_data data_seguinte (t_data data) {

}
int main () {
    t_data d1, d2;
    d1 = le_data();
    mostra_data(d1);
    d2 = le_data();
    mostra_data(d2);
    // int t;
    // srand(time(0));
    // printf ("\nescolha o tamanho do vetor, 0 encerra: ");
    // scanf ("%d", &t);
    // while (t>0) {
    //     int * v = gera_vetor(t);
    //     mostra_vetor(v, t);
    //     printf ("\nescolha o tamanho do vetor, 0 encerra: ");
    //     free(v);
    //     scanf ("%d", &t);
    // }
    return 0;
}