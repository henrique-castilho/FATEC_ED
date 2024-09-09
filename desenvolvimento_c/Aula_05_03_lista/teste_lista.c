#include "lista.h"

int main (){
    t_lista lista;
    inicialiaza_lista(&lista);
    printf ("Lista inicializada\n");
    mostra_lista(lista);
    for (int i = 15; i <= 25; i++){
        printf("Inserindo o %d\n", i);
        insere_inicio(i, &lista);
        mostra_lista(lista);
    }
    while (!esta_vazia(&lista)) {
        printf("%D foi removido do inicio\nA lista ficou assim:\n", remove_inicio(&lista));
        mostra_lista(lista);
    }
    
    return 0;
}