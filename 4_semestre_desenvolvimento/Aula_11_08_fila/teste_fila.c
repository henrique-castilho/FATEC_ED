#include <time.h>
#include "fila.h"

int main () {
    t_fila f;

    inicia_fila(&f);
    srand(time(0));
    
    do {
        if (rand() %2 ) {//enfileirar
            enfileira(&f, rand() % 10);
            exibe_fila(&f,  "Chegou mais um");
            
        } else {
            if(!fila_vazia(&f)) {
                desenfileira(&f);
                exibe_fila(&f, "Primeiiro foi desenfilerado");
            } else {
                printf("Nao chegou ninguem\n");
            }
        }
    } while (!fila_vazia(&f));
    
    return 0;
}
