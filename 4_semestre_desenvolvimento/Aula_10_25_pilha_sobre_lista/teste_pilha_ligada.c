#include "lista.h"

int menu () {
    int op;
    printf ("Escolha uma opcao:\n");
    printf ("1 - empilhar\n");
    printf ("2 - desempilhar\n");
    printf ("3 - mostrar pilha\n");
    printf ("0 - sair\n");
    printf ("-> ");
    scanf ("%d", &op);
    return op;
}

int main () {
    int op;
    t_lista l;

    inicia_lista(&l);

    do {
        op = menu();
        switch (op) {
            case 1:
                printf ("Digite o valor para empilhar: ");
                int num;
                scanf("%d", &num);
                empilha(&l, num);
                break;

            case 2:
                if (!lista_vazia(&l)) {
                    printf ("%d foi desempilhado\n", desempilha(&l));
                } else {
                    printf ("Pila esta vazia\n");
                }
                break;

            case 3:
                exibe_lista(&l, "Pilha");
                break;

            case 0:
                printf ("Obrigado, volte sempre!");
                break;

            default:
                printf ("Opcao invalida, tente novamente!\n");
                break;
        
        }

    } while (op != 0);
    
    return 0;
}