#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int info;
    struct no * proximo;
} t_no;

t_no * controi_no (int);
