#include "no_duplo.h"

t_no_duplo *constroi_no(int num) {
    t_no_duplo *novo = (t_no_duplo *) malloc (sizeof(t_no_duplo));
    if (novo == NULL) {
        printf("Erro na alocacao");
        return NULL;
    } else {
        novo->info = num;
        novo->proximo = NULL;
        novo->anterio = NULL;
    }
    return novo;
}