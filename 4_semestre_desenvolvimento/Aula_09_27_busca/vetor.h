#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//protótipo das funções: declarando as funções
void preenche_vetor(int *, int);
void exibe_vetor(int *, int, char *);
void soma_vetores (int *, int *, int *, int);
void bubblesort (int *, int);
void insertionsort (int *, int);
void selectionsort (int *, int);
void quicksort (int *, int, int, int *); //Vetor v, posições inicial e final12
int busca_simples (int *, int, int, int *); //Bucsa em um vetor de inteiros, um inteiro, um tamanho qualquer
int busca_binaria (int *, int, int, int *); //Bucsa em um vettor de inteiros, um inteiro, de um tamanho qualquer