/*3. Construa uma estrutura aluno com nome, numero de matrícula e curso. Leia do usuário
a informação de 5 alunos, armazene em vetor dessa estrutura e imprima os dados na
tela.*/

#include <stdio.h>
#include <string.h>
#define NUM_ALUNO 5

struct aluno{
    char nome[50], curso[150];
    int num_matricula;
};

int main(){
    struct aluno alunos[NUM_ALUNO];

    // Lê as informações de cada auluno
    for (int i = 0; i < NUM_ALUNO; i++){
        printf("Digite as informacoes do aluno %d:\n", i + 1);
        printf("Nome: ");
        fgets(alunos[i].nome, sizeof(alunos[i].nome), stdin);
        // Remover o caractere de nova linha '\n' do final do nome
        alunos[i].nome[strcspn(alunos[i].nome, "\n")] = '\0';

        printf("Matricula: ");
        scanf("%d", &alunos[i].num_matricula);
        getchar();

        printf("Curso: ");
        fgets(alunos[i].curso, sizeof(alunos[i].curso), stdin);
        // Romover o caractere de nova lina '\n' do final do nome
        alunos[i].curso[strcspn(alunos[i].curso, "\n")] = '\0';

        printf("\n");
    }

    // Imprimi as informações dos alunos
    printf("Informacoes dos alunos\n");
    for (int i = 0; i < NUM_ALUNO; i++){
        printf("Aluno %d:\n", i + 1);
        printf("Nome: %s\n", alunos[i].nome);
        printf("Matricula: %d\n", alunos[i].num_matricula);
        printf("Curso: %s\n\n", alunos[i].curso);
    }
    

    return  0;
}