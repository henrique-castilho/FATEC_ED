#include "no.h"

t_no * controi_no (int num) {
    t_no * novo = (t_no *) malloc(sizeof(t_no));
    if (novo != NULL) {
        novo->info = num;
        novo->proximo = NULL;
    }
    return novo;
}