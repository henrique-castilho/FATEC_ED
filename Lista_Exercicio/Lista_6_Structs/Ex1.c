/*Escreva um trecho de codigo para fazer a criação dos novos tipos de dados conforme
solicitado abaixo:
• Horario: composto de hora, minutos e segundos.
• Data: composto de dia, mes e ano. 
• Compromisso: composto de uma data, horario e texto que descreve o compromisso.*/

#include <stdio.h>
#include <string.h>

struct horario {
    int hora, minutos, segundos;
};

struct data {
    int dia, mes, ano;
};

struct compromisso {
    struct data dataCompromisso;
    struct horario horarioCompromisso;
    char descricao[100];
};

int main() {
    struct compromisso meuCompromisso;
    int ano_atual = 2024;

    // Pede ao usuário entrar com os valores da data
    printf("Data do seu compromisso\n");
    printf("Digite o dia do seu compromisso: ");
    scanf("%d", &meuCompromisso.dataCompromisso.dia);
    if (meuCompromisso.dataCompromisso.dia < 1 || meuCompromisso.dataCompromisso.dia > 31) {
        printf("DIA INVALIDO!\n");
        return 1;
    }

    printf("Digite o mes do seu compromisso (1 a 12): ");
    scanf("%d", &meuCompromisso.dataCompromisso.mes);
    if (meuCompromisso.dataCompromisso.mes < 1 || meuCompromisso.dataCompromisso.mes > 12) {
        printf("MES INVALIDO!\n");
        return 1;
    }

    printf("Digite o ano do seu compromisso: ");
    scanf("%d", &meuCompromisso.dataCompromisso.ano);
    if (meuCompromisso.dataCompromisso.ano < ano_atual) {
        printf("ANO INVALIDO!\n");
        return 1;
    }

    printf("\n");

    // Pede ao usuário entrar com os valores do horario
    printf("Horario do compromisso\n");
    do {
        printf("Digite a hora do seu compromisso: ");
        scanf("%d", &meuCompromisso.horarioCompromisso.hora);
        if (meuCompromisso.horarioCompromisso.hora < 0 || meuCompromisso.horarioCompromisso.hora > 23) {
            printf("HORA INVALIDA! Digite novamente.\n");
        }
    } while (meuCompromisso.horarioCompromisso.hora < 0 || meuCompromisso.horarioCompromisso.hora > 23);

    do {
        printf("Digite os minutos do seu compromisso: ");
        scanf("%d", &meuCompromisso.horarioCompromisso.minutos);
        if (meuCompromisso.horarioCompromisso.minutos < 0 || meuCompromisso.horarioCompromisso.minutos > 59) {
            printf("MINUTOS INVALIDOS!\n");
        }
    } while (meuCompromisso.horarioCompromisso.minutos < 0 || meuCompromisso.horarioCompromisso.minutos > 59);

    do {
        printf("Digite os segundos do seu compromisso: ");
        scanf("%d", &meuCompromisso.horarioCompromisso.segundos);
        if (meuCompromisso.horarioCompromisso.segundos < 0 || meuCompromisso.horarioCompromisso.segundos > 59) {
            printf("SEGUNDOS INVALIDOS!\n");
        }
    } while (meuCompromisso.horarioCompromisso.segundos < 0 || meuCompromisso.horarioCompromisso.segundos > 59);

    printf("\n");

    // Pede ao usuário entrar com a descrição
    printf("Descricao do compromisso\n");
    printf("Digite a descricao do seu compromisso: ");
    getchar(); // Limpar o buffer do teclado
    fgets(meuCompromisso.descricao, sizeof(meuCompromisso.descricao), stdin);

    // Verifica se o último caractere inserido foi uma quebra de linha
    if (meuCompromisso.descricao[strlen(meuCompromisso.descricao) - 1] == '\n') {
        // Se foi, substitui a quebra de linha por um terminador nulo
        meuCompromisso.descricao[strlen(meuCompromisso.descricao) - 1] = '\0';
    } else {
        // Caso contrário, o usuário excedeu o limite de caracteres
        printf("Limite de caracteres atingido (100)\n");
        return 1;
    }

    // Exibe os valores
    printf("\nCompromisso:\n");
    printf("Data: %02d/%02d/%04d\n", meuCompromisso.dataCompromisso.dia, meuCompromisso.dataCompromisso.mes, meuCompromisso.dataCompromisso.ano);
    printf("Horario: %02d:%02d:%02d\n", meuCompromisso.horarioCompromisso.hora, meuCompromisso.horarioCompromisso.minutos, meuCompromisso.horarioCompromisso.segundos);
    printf("Descricao: %s\n", meuCompromisso.descricao);

    return 0;
}
