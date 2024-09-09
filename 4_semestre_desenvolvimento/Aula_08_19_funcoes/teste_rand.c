#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int m, n;
    srand(time(0));
    m = rand() %10;
    n = rand()%100;

    printf("m = %d e n = %d", m, n );

    return 0;
}