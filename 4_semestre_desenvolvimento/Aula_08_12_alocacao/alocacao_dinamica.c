#include <stdlib.h>
#include <stdio.h>

int main(){
    //int v[100000];

    int *x;
    // x = (int *) malloc (2000000000 * sizeof(int));
    // if (x != NULL) {
    //     printf("foi");
    // } else {
    //     printf ("Falha na alocacao\n");
    // }
    
    // do{
    //     x = (int *) malloc (100000000);
    //     printf ("Endereco alocado: %p\n", x);
    //     free(x);

    // } while (x  != NULL);

    printf ("Quantos inteiros voce tem na lista?");
    int t;
    scanf("%d", &t);

    x = (int  *) malloc (t * sizeof(int));
    
    
    

    return 0;
}