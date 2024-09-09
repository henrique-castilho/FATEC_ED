#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_CARTAS 52
#define NUM_JOGADORES 2
#define CARTAS_POR_JOGADOR 5

typedef struct {
    int valor;
    char naipe;
} Carta;

void inicializar_baralho(Carta baralho[]) {
    int i, j, count = 0;
    for (i = 0; i < 4; i++) {
        for (j = 2; j <= 14; j++) {
            baralho[count].valor = j;
            switch(i) {
                case 0: baralho[count].naipe = 'C'; break;
                case 1: baralho[count].naipe = 'O'; break;
                case 2: baralho[count].naipe = 'P'; break;
                case 3: baralho[count].naipe = 'E'; break;
            }
            count++;
        }
    }
}

void embaralhar(Carta baralho[]) {
    srand(time(NULL));
    int i, j;
    Carta temp;
    for (i = 0; i < NUM_CARTAS; i++) {
        j = rand() % NUM_CARTAS;
        temp = baralho[i];
        baralho[i] = baralho[j];
        baralho[j] = temp;
    }
}

void distribuir_cartas(Carta baralho[], Carta mao[][CARTAS_POR_JOGADOR]) {
    int i, j, count = 0;
    for (i = 0; i < NUM_JOGADORES; i++) {
        for (j = 0; j < CARTAS_POR_JOGADOR; j++) {
            mao[i][j] = baralho[count++];
        }
    }
}

void mostrar_cartas(Carta mao[][CARTAS_POR_JOGADOR]) {
    int i, j;
    for (i = 0; i < NUM_JOGADORES; i++) {
        printf("Jogador %d:\n", i+1);
        for (j = 0; j < CARTAS_POR_JOGADOR; j++) {
            printf("   Carta %d: %d%c\n", j+1, mao[i][j].valor, mao[i][j].naipe);
        }
        printf("\n");
    }
}

int main() {
    Carta baralho[NUM_CARTAS];
    Carta mao[NUM_JOGADORES][CARTAS_POR_JOGADOR];

    inicializar_baralho(baralho);
    embaralhar(baralho);
    distribuir_cartas(baralho, mao);
    mostrar_cartas(mao);

    return 0;
}
