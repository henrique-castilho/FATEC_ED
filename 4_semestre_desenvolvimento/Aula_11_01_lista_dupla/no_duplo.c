#include "no_duplo.h"

t_no_duplo * constroi_no(int num) {
    t_no_duplo *novo = (t_no_duplo *) malloc (sizeof(t_no_duplo));
    if (novo != NULL) {
        novo->info = num;
        novo->anterior = NULL;
        novo->proximo = NULL;
    }
    return novo;
}
