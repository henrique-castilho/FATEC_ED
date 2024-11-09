#include "fila.h"

int main() {
    t_fila f, f_par, f_impar;
    inicia_fila(&f);
    inicia_fila(&f_par);
    inicia_fila(&f_impar);
    for (int i = 1; i <=10; i++) {
        enfileira(&f, i);
    }
    exibe_fila(&f, "Fila completa");
    separa_fila(&f, &f_par, &f_impar);
    exibe_fila(&f_par, "Fila de pares");
    exibe_fila(&f_impar, "Fila de impar");    

    return 0;
}