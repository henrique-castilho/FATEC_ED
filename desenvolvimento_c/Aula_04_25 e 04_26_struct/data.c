#include <stdio.h>
#include <stdlib.h>
#include <time.h>

    typedef struct {
        int dia, mes, ano;
    } t_data;

int valida_data (t_data data) {
    if (data.dia < 1 || 
        data.mes < 1 || data.mes > 12 || 
        data.ano < 1900 || data.ano > 2090) 
        return 0;
    switch(data.mes){
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            if(data.dia > 31) return 0;
            break;
        case 4: case 6: case 9: case 11:
            if(data.dia > 30) return 0;
        case 2:
            if(data.dia > 28) return 0;
            break;
    }
    return 1;
}

t_data le_data() {
    t_data data;
    int valida;
    do {
        printf ("\ndigite o dia: ");
        scanf ("%d", &data.dia);
        printf("\ndigite o mes: ");
        scanf("%d", &data.mes);
        printf("\ndigite o ano: ");
        scanf("%d", &data.ano);
        valida = valida_data (data);
        if (!valida)
            printf ("data invalida");
    } while (!valida);
    return data;
}
void mostra_data (t_data data) {
    printf ("%d/%d/%d\n", data.dia, data.mes, data.ano);
}
t_data data_seguinte (t_data data) {
    switch(data.mes){
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
            if(data.dia == 31){
                data.dia = 1;
                data.mes = data.mes + 1;
            }else{
                data.dia = data.dia + 1;
            }
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            if(data.dia == 30){
                data.dia = 1;
                data.mes = data.mes + 1;
            }else{
                data.dia = data.dia + 1;
            }
            break;
        case 2:
            if(data.dia == 28){
                data.dia = 1;
                data.mes = 3;
            }else{
                data.dia = data.dia + 1;
            }
            break;
        case 12:
            if(data.dia == 31){
                data.dia = 1;
                data.mes = 1;
                data.ano = data.ano + 1;
            }else{
                data.dia = data.dia + 1;
            }
            break;
    }
    return data;
}
int main () {
    t_data d1, d2;
    d1 = le_data();
    mostra_data(d1);
    d2 = data_seguinte(d1);
    mostra_data(d2);
    return 0;
}       