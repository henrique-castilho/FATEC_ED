#include <time.h>
#include "lista_dupla.h"

int main () {
    t_lista_dupla l;

    inicia_lista(&l);
    srand(time(0));

    do {
        if (rand() % 2 == 0) { //par: insere
            if (rand() % 2 == 0) { //par: insere no inicio
                insere_inicio(&l, rand() % 10);
                printf ("insercao de inicio\n");
            } else { //impar: insere final
                insere_fim(&l, rand() % 10);
                printf ("insercao de fim\n");
            }
            
        } else { //impar: remove
            if (!lista_vazia(&l)) {
                if (rand() % 2 == 0) { //par: remove do inicio
                    printf ("%d saiu do inicio\n", remove_inicio(&l));
                } else { //impar: remove do final
                    printf ("%d saiu do fim\n", remove_fim(&l));
                }  
            }
        }

        exibe_lista(&l, "");
    } while (!lista_vazia(&l));

    return 0;
}