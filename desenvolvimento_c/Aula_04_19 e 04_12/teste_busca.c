#include "vetor.h"

int main(){
    int *v, t, l, x, cont;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &t);
    printf("Digite o limite de geracao: ");
    scanf("%d", &l);
    v = (int *) malloc (t * sizeof(int));
    gera_vetor(v, t, l);
    //mostra_vetor(v, t, "Vetor gerado");
    printf("Digite o valor para busca: ");
    scanf("%d", &x);
    if (busca_simples (v, t, x, &cont)){
        printf("\n%d Foi encontrado pela busca simples\n", x);
    }
    else
        printf("\n%d Nao foi encontrado pela busca simples\n", x);
    printf("\na busca simples realizou %d teste\n", cont);
    insertionsort( v, t);
    //mostra_vetor (v, t, "Vetor ordenado");
    int pos = busca_binaria(v, t, x, &cont);
    if (pos == -1){
        printf ("\n%d Nao encontrado pela busca binaria\n", x);
    }
    else {
        printf ("\n%d Encontrado pela busca na posicao %d\n", x, pos);
    }
    printf("\nbusca binaria realizou %d testes\n", cont);
    return 0;
}