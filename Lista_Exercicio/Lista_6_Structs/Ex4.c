/*4. Crie uma estrutura representando os alunos de um determinado curso. A estrutura deve
conter a matrícula do aluno, nome, nota da primeira prova, nota da segunda prova e nota
da terceira prova.
(a) Permita ao usuario entrar com os dados de 5 alunos.
(b) Encontre o aluno com maior nota da primeira prova.
(c) Encontre o aluno com maior média geral.
(d) Encontre o aluno com menor média geral. 
(e) Para cada aluno diga se ele foi aprovado ou reprovado, considerando o valor 6 para
aprovação. */


#include <stdio.h>
#include <string.h>
#define NUM_ALUNOS 5
#define MEDIA_MINIMA 6

struct Aluno{
    int matricula;
    char nome[100];
    float nota1, nota2, nota3, media;    
};

// Função para calcular a média do aluno
void calculaMedia (struct Aluno *aluno) {
    aluno -> media = (aluno -> nota1 + aluno -> nota2 + aluno -> nota3) / 3.0;
}

int main(){
    struct Aluno info_aluno[NUM_ALUNOS];
    

    // (a) Entrada de dados de 5 alunos
    for (int i = 0; i < NUM_ALUNOS; i++){
        printf("Entre com os dados do aluno %d:\n", i+1);
        printf("Matricula: ");
        scanf("%d", &info_aluno[i].matricula);
        getchar();

        printf("Nome: ");
        fgets(info_aluno[i].nome, sizeof(info_aluno[i].nome), stdin);
        // Remover o caractere de nova linha '\n' do final do nome
        info_aluno[i].nome[strcspn(info_aluno[i].nome, "\n")] = '\0';


        do {
            printf("Nota da primeira prova: ");
            scanf("%f", &info_aluno[i].nota1);
            if (info_aluno[i].nota1 < 0 || info_aluno[i].nota1 > 10){
                printf("NOTA INVALIDA! Insira novamente.\n");    
            }
        } while (info_aluno[i].nota1 < 0 || info_aluno[i].nota1 > 10);

        do {
            printf("Nota da segunda prova: ");
            scanf("%f", &info_aluno[i].nota2);
            if (info_aluno[i].nota2 < 0 || info_aluno[i].nota2 > 10){
                printf("NOTA INVALIDA! Insira novamente.\n");
            }
        } while (info_aluno[i].nota2 < 0 || info_aluno[i].nota2 > 10);

        do {
            printf("Nota da terceira prova: ");
            scanf("%f", &info_aluno[i].nota3);
            if (info_aluno[i].nota3 < 0 || info_aluno[i].nota3 > 10){
                printf("NOTA INVALIDA!");
            }
        } while (info_aluno[i].nota3 < 0 || info_aluno[i].nota3 > 10);

        printf("\n");

        //Calcula a media do aluno
        calculaMedia(&info_aluno[i]);
    }

    // (b) Encontra o aluno com a maior nota na primeira prova
    float maiorNota1 = info_aluno[0].nota1;
    int alunoMaiorNota1 = 0;
    for (int i = 0; i < NUM_ALUNOS; i++){
        if (info_aluno[i].nota1 > maiorNota1){
            maiorNota1 = info_aluno[i].nota1;
            alunoMaiorNota1 = i;
        }        
    }

    printf("Aluno com maior nota na primeira prova:\n");
    printf("Nome: %s\n", info_aluno[alunoMaiorNota1].nome);
    printf("Nota: %.2f\n\n", maiorNota1);
    
    //(c) Encontra o aluno com maior média geral.
    float maiorMedia = info_aluno[0].media;
    int alunoMaiorMedia = 0;
    for (int i = 0; i < NUM_ALUNOS; i++){
        if (info_aluno[i].media > maiorMedia){
            maiorMedia = info_aluno[i].media;
            alunoMaiorMedia = i;
        }
    }
    
    printf("Aluno com a maior media:\n");
    printf("Nome: %s\n", info_aluno[alunoMaiorMedia].nome);
    printf("Media: %.2f\n\n", maiorMedia);


    //(d) Encontra o aluno com menor média geral.
    float menorMedia = info_aluno[0].media;
    int alunoMenorMedia = 0;
    for (int i = 0; i < NUM_ALUNOS; i++){
        if (info_aluno[i].media < menorMedia){
            menorMedia = info_aluno[i].media;
            alunoMenorMedia = i;
        }
    }

    printf("Aluno com a menor media:\n");
    printf("Nome: %s", info_aluno[alunoMenorMedia].nome);
    printf("Media: %.2f\n\n", menorMedia);

    // (e) Verifica se cada aluno foi aprovado ou reprovado
    printf("Situacao dos alunos:\n");
    for (int i = 0; i < NUM_ALUNOS; i++){
        printf("%s: ", info_aluno[i].nome);
        if (info_aluno[i].media >= MEDIA_MINIMA){
            printf("APROVADO com a media %.2f\n", info_aluno[i].media);
        } else {
            printf("REPROVADO\n com a media %.2f", info_aluno[i].media);
        }        
    }
    return 0;
}
